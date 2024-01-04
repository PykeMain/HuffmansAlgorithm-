#include "include/myRead.hpp"

std::string myRead(const std::string name){
    std::string result;
    if(name.find(".txt") != std::string::npos){
        std::ifstream in("../../text/" + name);
        readASCII(in, result);
    }else if(name.find(".dat") != std::string::npos){
        std::ifstream in("../../text/" + name);
        readBinary(in, result);
    }else{
        throw std::invalid_argument("Not a readable file.");
    }

    return result;
}

void readASCII(std::ifstream& in, std::string& result){
    if(!in.is_open()){
        throw std::invalid_argument("File doesn't exist.");
    }
    std::string temp;
    while(!in.eof()){
        std::getline(in, temp);
        result += temp;
    }
}

void readBinary(std::ifstream& in, std::string& result){}