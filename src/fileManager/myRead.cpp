#include "include/myRead.hpp"

std::string myRead(const std::string name){
    std::string result;
    if(name.find(".txt") != std::string::npos){
        std::ifstream in("../../text/" + name);
        readASCII(in, result);
        in.close();
    }else if(name.find(".dat") != std::string::npos){
        std::ifstream in("../../text/" + name, std::ios::binary);
        readBinary(in, result);
        in.close();
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
    if(!in.eof()){
        std::getline(in, temp);
        result += temp;
    }
    while(!in.eof()){
        result += "\n";
        std::getline(in, temp);
        result += temp;
    }
}

void readBinary(std::ifstream& in, std::string& result){
    std::size_t lenght;
    in.seekg(0, std::ios::end);
    lenght = in.tellg();
    std::cout << lenght;
    in.seekg(0);
    unsigned char *data = new unsigned char[lenght];
    in.read((char *)data, lenght);
    result = reinterpret_cast<char const*>(data);
}