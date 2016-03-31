#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.cpp"
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
/*
    int port = 9090;
    shared_ptr<ProThriftHandler> handler(new ProThriftHandler());
    shared_ptr<TProcessor> processor(new ProThriftProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    server.serve()
    */
    QThread* thread = new QThread;
        Worker* worker = new Worker();
        worker->moveToThread(thread);
        connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
        connect(thread, SIGNAL(started()), worker, SLOT(process()));
        connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
        connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        thread->start();

}

