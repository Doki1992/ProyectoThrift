#include "worker.h"
#include "ProThrift_server.skeleton.cpp"

// --- CONSTRUCTOR ---
Worker::Worker() {
    // you could copy data from constructor arguments to internal variables here.
}

// --- DECONSTRUCTOR ---
Worker::~Worker() {
    // free resources
}

// --- PROCESS ---
// Start processing data.
void Worker::process() {
    // allocate resources using new here
    int port = 9090;
    shared_ptr<ProThriftHandler> handler(new ProThriftHandler());
    shared_ptr<TProcessor> processor(new ProThriftProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    server.serve();
    qDebug("Hello World!");
    emit finished();
}
