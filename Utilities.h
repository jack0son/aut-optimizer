#ifndef UTILITIES_H
#define UTILITIES_H

#using <System.dll>
#include <string>
#include <vector>

void systemStringToStandardString(System::String^ in, std::string& out);
std::string urlToString(std::string url);
std::vector<std::string> split(std::string in, std::vector<std::string> delimiters);
std::string replace(std::string str, std::string out, std::string in);
std::string newLeft(std::string str, int len, int spaces);

#endif