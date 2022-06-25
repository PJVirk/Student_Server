#ifndef _MAJOR_H_
#define _MAJOR_H_

#include <string>
#include <iostream>
#include <stdio.h>

class Major
{
private:
public:
  std::string action;
  std::string arguments;
  std::string major;
  std::string host_url;

  Major(std::string arg_action, std::string arg_arguments, std::string arg_major, std::string arg_host_url);
  std::string getMajorStudents();

};
#endif
