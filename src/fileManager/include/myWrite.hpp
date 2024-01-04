#pragma once

#include <string>
#include <fstream>

void myWrite(std::string name);

void writeASCII(std::ifstream& name, std::string& result);

void writeBinary(std::ifstream& name, std::string& result);