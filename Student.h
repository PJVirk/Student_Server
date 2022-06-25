#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>
#include <iostream>

class Student {
public:
  std::string s_name;
  std::string s_email;
  std::string s_year;
  std::string s_resume_filename;

  Student(std::string name, std::string email, std::string year, std::string resume_filename) {
    s_name = name;
    s_email = email;
    s_year = year;
    s_resume_filename = resume_filename;

  }
};

#endif
