#include <string>

#include <stdbool.h>
#include <stdlib.h>
#include <jsonrpccpp/client/connectors/httpclient.h>

#include "Major.h"
#include "finalclient.h"

using namespace jsonrpc;
using namespace std;


Major::Major(std::string arg_action, std::string arg_arguments, std::string arg_major, std::string arg_host_url){
  this->action = arg_action;
  this->arguments = arg_arguments;
  this->major = arg_major;
  this->host_url = arg_host_url;
  std::cout<<"Major Object Constructor Called"<<std::endl;
}

std::string
Major::getMajorStudents()
{

  HttpClient httpclient((this->host_url).c_str());
  finalClient myClient(httpclient, JSONRPC_CLIENT_V2);

  Json::Value myv;

  try {
    myv = myClient.getMajorStudents((this->action).c_str(), (this->arguments).c_str(),
			      (this->major).c_str(), (this->host_url).c_str());
    cout << myv.toStyledString() << endl;
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }

  return (myv["Students"]).asString();
}
