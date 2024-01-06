#pragma once

#include <string>
#include <fstream>
#include <iostream>

void myWrite(std::string name, std::string content, bool isEncoded);

void writeASCII(std::ofstream& out, std::string content);

void writeBinary(std::ofstream& out, std::string content);