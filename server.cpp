#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>

#include <string>
#include <vector>
#include <iostream>

#include <stdio.h>
#include <stdbool.h>
#include <jsonrpccpp/server/connectors/httpserver.h>

#include "finalserver.h"
#include "Student.h"
#include "Major.h"

using namespace jsonrpc;
using namespace std;



class MyfinalServer : public finalServer
{
public:
  MyfinalServer(AbstractServerConnector &connector, serverVersion_t type);
  virtual Json::Value getMajorStudents(const std::string& action, const std::string& arguments,
				 const std::string& class_id, const std::string& host_url);
  virtual Json::Value getStudentInfo(const std::string& action, const std::string& arguments,
       	 const std::string& student_name, const std::string& host_url);

};

MyfinalServer::MyfinalServer(AbstractServerConnector &connector, serverVersion_t type)
  : finalServer(connector, type)
{
  std::cout << "MyfinalServer Object created" << std::endl;
}

std::vector<Student>* student_object_array_ptr;


Json::Value
MyfinalServer::getMajorStudents
(const std::string& action, const std::string& arguments,
 const std::string& class_id, const std::string& host_url)
{
  Json::Value result;
  std::cout << action << " " << arguments << " " << class_id << std::endl;
  std::string strJson;


  strJson+="{\"Students\" : \"";
  for (int i = 0; i < size(*student_object_array_ptr); i++){
    strJson+= ((*student_object_array_ptr)[i]).s_name+ ", ";
    std::cout<<strJson<<std::endl;

    }
    strJson+=("\"}");
    strJson += "{\"status\" : \"successful\"}";
    std::cout<<strJson<<std::endl;
  Json::CharReaderBuilder builder;
  Json::CharReader* reader = builder.newCharReader();
  std::string errors;
  bool parsingSuccessful = reader->parse
    (strJson.c_str(), strJson.c_str() + strJson.size(), &result, &errors);
  delete reader;

  if (!parsingSuccessful) {
    std::cout << "Failed to parse the JSON, errors:" << std::endl;
    std::cout << errors << std::endl;
  }

  return result;
}

Json::Value
MyfinalServer::getStudentInfo
(const std::string& action, const std::string& arguments, const std::string& student_name, const std::string& host_url)
{
  Json::Value result;
  std::cout << action << " " << arguments << " " << student_name << std::endl;
  std::string strJson;
  for (int i = 0; i < size(*student_object_array_ptr); i++){
    if ((((*student_object_array_ptr)[i]).s_name) == student_name){
      std::cout <<(((*student_object_array_ptr)[i]).s_name)<<std::endl;
      std::cout <<student_name<<std::endl;
      strJson += "{\"Student Name\": \"" + student_name + "\",";
      strJson += "\"Email\" : \"" + ((*student_object_array_ptr)[i]).s_email + "\",";
      strJson += "\"Year\" : \"" + ((*student_object_array_ptr)[i]).s_year + "\",";
      strJson += "\"Resume\" : \"" + ((*student_object_array_ptr)[i]).s_resume_filename + "\",";
      strJson += "\"status\" : \"successful\"}";
      std::cout <<strJson<<std::endl;

      Json::CharReaderBuilder builder;
      Json::CharReader* reader = builder.newCharReader();
      std::string errors;
      bool parsingSuccessful = reader->parse
        (strJson.c_str(), strJson.c_str() + strJson.size(), &result, &errors);
      delete reader;

      if (!parsingSuccessful) {
        std::cout << "Failed to parse the JSON, errors:" << std::endl;
        std::cout << errors << std::endl;
      }

      return result;
    }

  }
  return "Student not on this server!";
}



int main(void){
  Student Carly("Carly", "c@ucdavis.edu", "2024", "carly_resume.docx");
  Student Fred("Fred", "f@ucdavis.edu", "2023", "fred_resume.docx");
  std::vector<Student> student_object_array{Carly, Fred};
  student_object_array_ptr = &student_object_array;
  std::cout <<&student_object_array<<std::endl;
  std::cout <<student_object_array_ptr<<std::endl;
  std::cout <<student_object_array[0].s_name<<std::endl;
  std::cout <<(*student_object_array_ptr)[0].s_name<<std::endl;
  std::cout<<size(*student_object_array_ptr)<<std::endl;
  std::cout <<size(student_object_array)<<std::endl;
  HttpServer httpserver(8381);
  MyfinalServer s(httpserver,
		JSONRPC_SERVER_V1V2);
  s.StartListening();
  std::cout << "Hit enter to stop the server" << endl;
  getchar();

  s.StopListening();
  return 0;
}
