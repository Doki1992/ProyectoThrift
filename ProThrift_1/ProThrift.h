/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ProThrift_H
#define ProThrift_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "proprueba_types.h"



#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class ProThriftIf {
 public:
  virtual ~ProThriftIf() {}
  virtual void ping() = 0;
  virtual void obtener_posicion(std::string& _return, const int32_t pos) = 0;
  virtual int32_t sumar(const int32_t uno, const int32_t dos) = 0;
};

class ProThriftIfFactory {
 public:
  typedef ProThriftIf Handler;

  virtual ~ProThriftIfFactory() {}

  virtual ProThriftIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ProThriftIf* /* handler */) = 0;
};

class ProThriftIfSingletonFactory : virtual public ProThriftIfFactory {
 public:
  ProThriftIfSingletonFactory(const boost::shared_ptr<ProThriftIf>& iface) : iface_(iface) {}
  virtual ~ProThriftIfSingletonFactory() {}

  virtual ProThriftIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ProThriftIf* /* handler */) {}

 protected:
  boost::shared_ptr<ProThriftIf> iface_;
};

class ProThriftNull : virtual public ProThriftIf {
 public:
  virtual ~ProThriftNull() {}
  void ping() {
    return;
  }
  void obtener_posicion(std::string& /* _return */, const int32_t /* pos */) {
    return;
  }
  int32_t sumar(const int32_t /* uno */, const int32_t /* dos */) {
    int32_t _return = 0;
    return _return;
  }
};


class ProThrift_ping_args {
 public:

  ProThrift_ping_args(const ProThrift_ping_args&);
  ProThrift_ping_args& operator=(const ProThrift_ping_args&);
  ProThrift_ping_args() {
  }

  virtual ~ProThrift_ping_args() throw();

  bool operator == (const ProThrift_ping_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ProThrift_ping_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProThrift_ping_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProThrift_ping_pargs {
 public:


  virtual ~ProThrift_ping_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProThrift_ping_result {
 public:

  ProThrift_ping_result(const ProThrift_ping_result&);
  ProThrift_ping_result& operator=(const ProThrift_ping_result&);
  ProThrift_ping_result() {
  }

  virtual ~ProThrift_ping_result() throw();

  bool operator == (const ProThrift_ping_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const ProThrift_ping_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProThrift_ping_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProThrift_ping_presult {
 public:


  virtual ~ProThrift_ping_presult() throw();

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ProThrift_obtener_posicion_args__isset {
  _ProThrift_obtener_posicion_args__isset() : pos(false) {}
  bool pos :1;
} _ProThrift_obtener_posicion_args__isset;

class ProThrift_obtener_posicion_args {
 public:

  ProThrift_obtener_posicion_args(const ProThrift_obtener_posicion_args&);
  ProThrift_obtener_posicion_args& operator=(const ProThrift_obtener_posicion_args&);
  ProThrift_obtener_posicion_args() : pos(0) {
  }

  virtual ~ProThrift_obtener_posicion_args() throw();
  int32_t pos;

  _ProThrift_obtener_posicion_args__isset __isset;

  void __set_pos(const int32_t val);

  bool operator == (const ProThrift_obtener_posicion_args & rhs) const
  {
    if (!(pos == rhs.pos))
      return false;
    return true;
  }
  bool operator != (const ProThrift_obtener_posicion_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProThrift_obtener_posicion_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProThrift_obtener_posicion_pargs {
 public:


  virtual ~ProThrift_obtener_posicion_pargs() throw();
  const int32_t* pos;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ProThrift_obtener_posicion_result__isset {
  _ProThrift_obtener_posicion_result__isset() : success(false) {}
  bool success :1;
} _ProThrift_obtener_posicion_result__isset;

class ProThrift_obtener_posicion_result {
 public:

  ProThrift_obtener_posicion_result(const ProThrift_obtener_posicion_result&);
  ProThrift_obtener_posicion_result& operator=(const ProThrift_obtener_posicion_result&);
  ProThrift_obtener_posicion_result() : success() {
  }

  virtual ~ProThrift_obtener_posicion_result() throw();
  std::string success;

  _ProThrift_obtener_posicion_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const ProThrift_obtener_posicion_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ProThrift_obtener_posicion_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProThrift_obtener_posicion_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ProThrift_obtener_posicion_presult__isset {
  _ProThrift_obtener_posicion_presult__isset() : success(false) {}
  bool success :1;
} _ProThrift_obtener_posicion_presult__isset;

class ProThrift_obtener_posicion_presult {
 public:


  virtual ~ProThrift_obtener_posicion_presult() throw();
  std::string* success;

  _ProThrift_obtener_posicion_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ProThrift_sumar_args__isset {
  _ProThrift_sumar_args__isset() : uno(false), dos(false) {}
  bool uno :1;
  bool dos :1;
} _ProThrift_sumar_args__isset;

class ProThrift_sumar_args {
 public:

  ProThrift_sumar_args(const ProThrift_sumar_args&);
  ProThrift_sumar_args& operator=(const ProThrift_sumar_args&);
  ProThrift_sumar_args() : uno(0), dos(0) {
  }

  virtual ~ProThrift_sumar_args() throw();
  int32_t uno;
  int32_t dos;

  _ProThrift_sumar_args__isset __isset;

  void __set_uno(const int32_t val);

  void __set_dos(const int32_t val);

  bool operator == (const ProThrift_sumar_args & rhs) const
  {
    if (!(uno == rhs.uno))
      return false;
    if (!(dos == rhs.dos))
      return false;
    return true;
  }
  bool operator != (const ProThrift_sumar_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProThrift_sumar_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ProThrift_sumar_pargs {
 public:


  virtual ~ProThrift_sumar_pargs() throw();
  const int32_t* uno;
  const int32_t* dos;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ProThrift_sumar_result__isset {
  _ProThrift_sumar_result__isset() : success(false) {}
  bool success :1;
} _ProThrift_sumar_result__isset;

class ProThrift_sumar_result {
 public:

  ProThrift_sumar_result(const ProThrift_sumar_result&);
  ProThrift_sumar_result& operator=(const ProThrift_sumar_result&);
  ProThrift_sumar_result() : success(0) {
  }

  virtual ~ProThrift_sumar_result() throw();
  int32_t success;

  _ProThrift_sumar_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const ProThrift_sumar_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ProThrift_sumar_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProThrift_sumar_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ProThrift_sumar_presult__isset {
  _ProThrift_sumar_presult__isset() : success(false) {}
  bool success :1;
} _ProThrift_sumar_presult__isset;

class ProThrift_sumar_presult {
 public:


  virtual ~ProThrift_sumar_presult() throw();
  int32_t* success;

  _ProThrift_sumar_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ProThriftClient : virtual public ProThriftIf {
 public:
  ProThriftClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ProThriftClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void ping();
  void send_ping();
  void recv_ping();
  void obtener_posicion(std::string& _return, const int32_t pos);
  void send_obtener_posicion(const int32_t pos);
  void recv_obtener_posicion(std::string& _return);
  int32_t sumar(const int32_t uno, const int32_t dos);
  void send_sumar(const int32_t uno, const int32_t dos);
  int32_t recv_sumar();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ProThriftProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<ProThriftIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ProThriftProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_ping(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_obtener_posicion(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_sumar(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ProThriftProcessor(boost::shared_ptr<ProThriftIf> iface) :
    iface_(iface) {
    processMap_["ping"] = &ProThriftProcessor::process_ping;
    processMap_["obtener_posicion"] = &ProThriftProcessor::process_obtener_posicion;
    processMap_["sumar"] = &ProThriftProcessor::process_sumar;
  }

  virtual ~ProThriftProcessor() {}
};

class ProThriftProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ProThriftProcessorFactory(const ::boost::shared_ptr< ProThriftIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ProThriftIfFactory > handlerFactory_;
};

class ProThriftMultiface : virtual public ProThriftIf {
 public:
  ProThriftMultiface(std::vector<boost::shared_ptr<ProThriftIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ProThriftMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ProThriftIf> > ifaces_;
  ProThriftMultiface() {}
  void add(boost::shared_ptr<ProThriftIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void ping() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->ping();
    }
    ifaces_[i]->ping();
  }

  void obtener_posicion(std::string& _return, const int32_t pos) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->obtener_posicion(_return, pos);
    }
    ifaces_[i]->obtener_posicion(_return, pos);
    return;
  }

  int32_t sumar(const int32_t uno, const int32_t dos) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->sumar(uno, dos);
    }
    return ifaces_[i]->sumar(uno, dos);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class ProThriftConcurrentClient : virtual public ProThriftIf {
 public:
  ProThriftConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ProThriftConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void ping();
  int32_t send_ping();
  void recv_ping(const int32_t seqid);
  void obtener_posicion(std::string& _return, const int32_t pos);
  int32_t send_obtener_posicion(const int32_t pos);
  void recv_obtener_posicion(std::string& _return, const int32_t seqid);
  int32_t sumar(const int32_t uno, const int32_t dos);
  int32_t send_sumar(const int32_t uno, const int32_t dos);
  int32_t recv_sumar(const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif



#endif
