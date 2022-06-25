#ifndef JSONRPC_CPP_STUB_FINALSERVER_H_
#define JSONRPC_CPP_STUB_FINALSERVER_H_

#include <jsonrpccpp/server.h>

class finalServer : public jsonrpc::AbstractServer<finalServer>
{
    public:
        finalServer(jsonrpc::AbstractServerConnector &conn, jsonrpc::serverVersion_t type = jsonrpc::JSONRPC_SERVER_V2) : jsonrpc::AbstractServer<finalServer>(conn, type)
        {
            this->bindAndAddMethod(jsonrpc::Procedure("getMajorStudents", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "action",jsonrpc::JSON_STRING,"arguments",jsonrpc::JSON_STRING,"class_id",jsonrpc::JSON_STRING,"host_url",jsonrpc::JSON_STRING, NULL), &finalServer::getMajorStudentsI);
            this->bindAndAddMethod(jsonrpc::Procedure("getStudentInfo", jsonrpc::PARAMS_BY_NAME, jsonrpc::JSON_OBJECT, "action",jsonrpc::JSON_STRING,"arguments",jsonrpc::JSON_STRING,"host_url",jsonrpc::JSON_STRING,"student_name",jsonrpc::JSON_STRING, NULL), &finalServer::getStudentInfoI);
        }

        inline virtual void getMajorStudentsI(const Json::Value &request, Json::Value &response)
        {
            response = this->getMajorStudents(request["action"].asString(), request["arguments"].asString(), request["class_id"].asString(), request["host_url"].asString());
        }
        inline virtual void getStudentInfoI(const Json::Value &request, Json::Value &response)
        {
            response = this->getStudentInfo(request["action"].asString(), request["arguments"].asString(), request["host_url"].asString(), request["student_name"].asString());
        }
        virtual Json::Value getMajorStudents(const std::string& action, const std::string& arguments, const std::string& class_id, const std::string& host_url) = 0;
        virtual Json::Value getStudentInfo(const std::string& action, const std::string& arguments, const std::string& host_url, const std::string& student_name) = 0;
};

#endif //JSONRPC_CPP_STUB_FINALSERVER_H_
