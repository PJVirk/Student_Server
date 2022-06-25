#ifndef JSONRPC_CPP_STUB_FINALCLIENT_H_
#define JSONRPC_CPP_STUB_FINALCLIENT_H_

#include <jsonrpccpp/client.h>

class finalClient : public jsonrpc::Client
{
    public:
        finalClient(jsonrpc::IClientConnector &conn, jsonrpc::clientVersion_t type = jsonrpc::JSONRPC_CLIENT_V2) : jsonrpc::Client(conn, type) {}

        Json::Value getMajorStudents(const std::string& action, const std::string& arguments, const std::string& class_id, const std::string& host_url)
        {
            Json::Value p;
            p["action"] = action;
            p["arguments"] = arguments;
            p["class_id"] = class_id;
            p["host_url"] = host_url;
            Json::Value result = this->CallMethod("getMajorStudents",p);
            if (result.isObject())
                return result;
            else
                throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
        }
        Json::Value getStudentInfo(const std::string& action, const std::string& arguments, const std::string& host_url, const std::string& student_name)
        {
            Json::Value p;
            p["action"] = action;
            p["arguments"] = arguments;
            p["host_url"] = host_url;
            p["student_name"] = student_name;
            Json::Value result = this->CallMethod("getStudentInfo",p);
            if (result.isObject())
                return result;
            else
                throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
        }
};

#endif //JSONRPC_CPP_STUB_FINALCLIENT_H_
