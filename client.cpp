#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <jsonrpccpp/client/connectors/httpclient.h>

#include "finalclient.h"
#include "Major.h"

using namespace jsonrpc;
using namespace std;
std::string student_name;





std::string getInputHostUrl(void);
std::string checkHostUrl(void);
void getStudentInfo(std::string arg_host_url, std::string arg_student_name);
bool CheckStudentPresence(std::string arg_host_url, std::string arg_student_name);

std::vector<std::string> server_1_student_names = {"Carly", "Fred"};
std::vector<std::string> server_2_student_names = {"Katherine", "George"};
std::vector<std::string> server_3_student_names = {"Olivia", "Daniel"};

int main(void){

  char search_mode;
  std::cout<<"Welcome to student-search."<<std::endl;
  std::cout<<"Please select search mode:\nSearch by Major(M)\nSearch for Student(S)"<<std::endl;
  std::cin>>search_mode;
  search_mode = toupper(search_mode);
  while (search_mode != 'M' && search_mode != 'S'){
    std::cout<<"Please try again!"<<std::endl;
    std::cin>>search_mode;
    search_mode = toupper(search_mode);
  }

  if (search_mode == 'M'){
    std::string major_students;
    std::string host_url;
    std::cout<<"You have selected: Search by Major(M)"<<std::endl;
    std::cout<<"Please enter major in ALL CAPS: ";
    std::getline(std::cin>>std::ws, major_students);
    std::cout <<major_students;
    host_url = getInputHostUrl();
    std::cout<<host_url<<std::endl;
    Major major_object{"getMajorStudents", "Getting students in major...",major_students, host_url};
    std::string students_in_major = major_object.getMajorStudents();
    std::cout<<"Students in Major: " <<std::endl;

    std::cout<<students_in_major<<std::endl;

  }
  else if(search_mode == 'S'){
    std::string host_url;
    std::string check_host_url;
    std::cout<<"You have selected: Search by Student(S)"<<std::endl;
    std::cout<<"Please enter student name: ";
    std::getline(std::cin>>std::ws, student_name);
    std::cout<<student_name;
    host_url = getInputHostUrl();
    check_host_url = checkHostUrl();
    std::cout<<host_url<<std::endl;
    if(CheckStudentPresence(host_url, student_name) == true){
      getStudentInfo(host_url, student_name);
    }
    else{
      std::cout<< student_name << " is not on this server!"<<std::endl;
      std::cout<<check_host_url<<std::endl;
    }
  }

return 0;
}



std::string getInputHostUrl(void){
  int device_number;
  std::cout<<"\nWhat device are you standing nearest to? (1-3)"<<std::endl;
  std::cin>>(device_number);
  if(device_number == 1){
    return "http://localhost:8381";
  }
  else if(device_number == 2){
    return "http://localhost:8382";
  }
  else {
    return "http://localhost:8383";
  }
}

std::string checkHostUrl(void)
{
  if (std::find(server_1_student_names.begin(), server_1_student_names.end(), student_name) != server_1_student_names.end())
    return "is in Server 1!";
  else if (std::find(server_2_student_names.begin(), server_2_student_names.end(), student_name) != server_2_student_names.end())
    return "is in Server 2!";
  else if (std::find(server_3_student_names.begin(), server_3_student_names.end(), student_name) != server_3_student_names.end())
    return "is in Server 3!";

  return 0;
}

bool CheckStudentPresence(std::string arg_host_url, std::string arg_student_name){
  if ((arg_host_url) == "http://localhost:8381"){
    for(int i = 0; i < size(server_1_student_names); i++){
      if (arg_student_name == server_1_student_names[i]) {return true;}
    }
    return false;
  }
  else if((arg_host_url) == "http://localhost:8382"){
    for(int i = 0; i < size(server_2_student_names); i++){
      if (arg_student_name == server_2_student_names[i]) {return true;}
    }
    return false;
  }
  else{
    for(int i = 0; i < size(server_3_student_names); i++){
      if (arg_student_name == server_3_student_names[i]) {return true;}
    }
    return false;
  }
}

void getStudentInfo(std::string arg_host_url, std::string arg_student_name) {
  if (arg_host_url == "http://localhost:8381"){
    for (int i = 0; i < size(server_1_student_names); i++){
      if(arg_student_name == server_1_student_names[i]){

        HttpClient httpclient((arg_host_url).c_str());
        finalClient myClient(httpclient, JSONRPC_CLIENT_V2);

        Json::Value myv;

        try {
          myv = myClient.getStudentInfo("getStudentInfo1", "Getting student info",
      			      arg_student_name, arg_host_url);
          cout << myv.toStyledString() << endl;
        } catch (JsonRpcException &e) {
          cerr << e.what() << endl;
        }

        std::cout<< (myv).toStyledString();
      }
    }

  }
  else if (arg_host_url == "http://localhost:8382"){
    for (int i = 0; i < size(server_2_student_names); i++){
      if(arg_student_name == server_2_student_names[i]){

        HttpClient httpclient((arg_host_url).c_str());
        finalClient myClient(httpclient, JSONRPC_CLIENT_V2);

        Json::Value myv;

        try {
          myv = myClient.getStudentInfo("getStudentInfo2", "Getting student info",
      			      arg_student_name, arg_host_url);
          cout << myv.toStyledString() << endl;
        } catch (JsonRpcException &e) {
          cerr << e.what() << endl;
        }

        std::cout<< (myv).toStyledString();
      }
    }
  }
  else {
    for (int i = 0; i < size(server_3_student_names); i++){
      if(arg_student_name == server_3_student_names[i]){

        HttpClient httpclient((arg_host_url).c_str());
        finalClient myClient(httpclient, JSONRPC_CLIENT_V2);

        Json::Value myv;

        try {
          myv = myClient.getStudentInfo("getStudentInfo3", "Getting student info",
      			      arg_student_name, arg_host_url);
          cout << myv.toStyledString() << endl;
        } catch (JsonRpcException &e) {
          cerr << e.what() << endl;
        }

        std::cout<< (myv).toStyledString();
      }
    }
  }
}
