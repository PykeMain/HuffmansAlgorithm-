#include "include/IO.hpp"

bool IO::fileExist(const std::string& fileName){
    std::ifstream file(fileName);
    bool result = file.good();
    file.close();

    return result;
}

IO& IO::getInstance(){
    static IO object;
    object.saved = true;
    return object;
}

void IO::menu(){
    while(true){
        std::cout << "Type \"help\" for more info.\n";
        std::cin >> input;

        

        if(input == "e"){
            if(!opened){
                break;
            }
            std::cout << "You are still have a file opened.\n";
        }
        
        else if(input == "h"){
            help();
        }else if(input == "i"){
            inputting();
        }else if(input == "o"){
            outputting();
        }else if(input == "g"){
            if(encode){
                debug();
            }
            std::cout << "The text isn't currently encoded.\n";
        }else if(input == "c"){
            encode();
        }else if(input == "d"){
            decode();
        }else{
            std::cout << "Not a command. Type \"help\" to learn what is.\n";
        }
    }
}

void IO::inputting(){
    std::cin >> input;
    if(!fileExist("../../text" + input)){
        throw std::invalid_argument("File doesn't exist and no point creating an empty file to read.")
    }
    catalog.setName(input);
    catalog.fill();
    opened = true;
}

