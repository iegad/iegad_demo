#include "employeeService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TJSONProtocol.h>
#include <iostream>
#include <thrift/transport/THttpServer.h>
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

class employeeServiceHandler : virtual public employeeServiceIf {
 public:
  employeeServiceHandler() {
    // Your initialization goes here
  }

  int32_t addEmployee(const employee& obj) {

    std::cout<<obj.id<<'\t'<<obj.name<<std::endl;
    return 0;
  }

};


int main(int argc, char **argv)
{
  int port = 9090;
  shared_ptr<employeeServiceHandler> handler(new employeeServiceHandler());
  shared_ptr<TProcessor> processor(new employeeServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new THttpServerTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TJSONProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

