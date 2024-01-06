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

}