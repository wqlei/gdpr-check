#include<iostream>
#include<boost/regex.hpp>
#include<string>
#include<map>



int Get_Conf(std::map<std::string, std::string> &config);
int Regex_line(std::string RegBuf, std::string Regexp, char* ret);
int Regex_file(std::string File_Name);
