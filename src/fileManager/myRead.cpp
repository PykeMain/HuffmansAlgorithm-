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
    unsigned char mod;
    in.seekg(0);
    in.read((char *)& mod, sizeof(char));
    if(mod == 0){
        mod = 32;
    }
    in.seekg(1, std::ios::end);
    lenght = in.tellg();
    
    in.seekg(1);
    unsigned int temp;
    std::string byte1;
    while(in.tellg() < lenght - 5){
        temp = 0;
        byte1 = "";
        in.read((char *)&temp, sizeof(int));
        for(int j = 0; j < sizeof(int) * 8; ++j){
            byte1 = ((temp % 2 == 0) ? '0' : '1') + byte1;
            temp /= 2; 
        }
        result += byte1; 
    }

    temp = 0;
    byte1 = "";
    in.read((char *)&temp, sizeof(int));
    for(int j = 0; j < mod ; ++j){
        byte1 = ((temp % 2 == 0) ? '0' : '1') + byte1;
        temp /= 2; 
    }
    result += byte1; 
}