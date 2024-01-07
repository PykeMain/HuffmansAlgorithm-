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
    unsigned char mod = 'a';
    in.seekg(0);
    in.read((char *)& mod, sizeof(char));

    in.seekg(1, std::ios::end);
    lenght = in.tellg();
    std::cout << lenght * 8 << " " << lenght << std::endl;
    
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
    std::cout << temp << std::endl;
    for(int j = 0; j < mod ; ++j){
        byte1 = ((temp % 2 == 0) ? '0' : '1') + byte1;
        temp /= 2; 
    }
    result += byte1; 
    

    // for(std::size_t i = 0; i < lenght / 4; ++i ){
    //     byte4 = "";
    //     for(int k = 0; k < 4; ++k){
    //         copy = data[i*4 + k];
    //         std::cout << data[i*4 +k];
    //         byte1 = "";
    //         for(int j = 0; j < 8; ++j){
    //             byte1 = ((copy % 2 == 0) ? '0' : '1') + byte1;
    //             copy /= 2; 
    //         }
    //         byte4 = byte1 + byte4;
    //     }
    //     result += byte4;
    // }
    //result = reinterpret_cast<char const*>(data);
    // std::cout << result;
}