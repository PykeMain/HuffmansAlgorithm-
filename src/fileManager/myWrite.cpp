#include "include/myWrite.hpp"

void myWrite(std::string name, std::string content, bool isEncoded){
    if(!isEncoded){
        std::ofstream out("../../text/" + name + ".txt");
        writeASCII(out, content);
        out.close();
    }else{
        std::ofstream out("../../text/" + name + ".dat", std::ios::binary);
        writeBinary(out, content);
        out.close();
    }
}

void writeASCII(std::ofstream& out, std::string content){
    out << content;
}

void writeBinary(std::ofstream& out, std::string content){
    std::string temp;
    for(int i = 0; i < content.size() / 8; ++i){
        temp = "";
        for(int j = 0; j < 8; ++j){
            temp += content[i * 8 + j];
        }
        std::cout << std::stoi(temp, nullptr, 2) << " ";
    }
    if(content.size() % 8 != 0){
        temp = "";
        for(int k = 1; k <= content.size() % 8 ; ++k){
            temp = content[content.size() - k] + temp;
        }
        std::cout << std::stoi(temp, nullptr, 2);
    }
}