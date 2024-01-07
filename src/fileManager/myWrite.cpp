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

const int LOOP = sizeof(int) * 8;

void writeBinary(std::ofstream& out, std::string content){
    unsigned int temp;

    for(int i = 0; i < content.size() / LOOP; ++i){
        temp = 0;
        for(int j = 0; j < LOOP; ++j){
            temp = (temp << 1) + ((content[i * LOOP + j] == '0') ? 0 : 1);
            //std::cout << (content[i * LOOP + j] == '0') ? 0 : 1;
        }
        out.write((const char*)&temp, sizeof(int));
        //std::cout << "=" << temp << " ";
    }

    if(content.size() % LOOP != 0){
        temp = 0;
        for(int k = 0; k < content.size() % LOOP ; ++k){
            temp = (temp << 1) + ((content[content.size() - content.size() % LOOP + k] == '0') ? 0 : 1);
        }
        out.write((const char*)&temp, sizeof(int));
    }
    // command to read the binary: xxd -b ../../text/test2_wibo.dat !!
}