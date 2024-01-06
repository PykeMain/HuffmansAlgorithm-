#pragma once
#include <string>
#include <iostream>
#include <fstream>

std::string myRead(std::string name);

void readASCII(std::ifstream& name, std::string& result);

void readBinary(std::ifstream& name, std::string& result);