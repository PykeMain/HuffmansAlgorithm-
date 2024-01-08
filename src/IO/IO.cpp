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
        std::cout << "Type \"help\" for more info." << std::endl;
        std::cin >> input;

        

        if(input == "e"){
            if(!opened){
                break;
            }
            std::cout << "You are still have a file opened." << std::endl;
        }
        
        else if(input == "h"){
            help();
        }else if(input == "i"){
            inputting();
        }else if(input == "o"){
            outputting();
        }else if(input == "g"){
            debug();
        }else if(input == "c"){
            encode();
        }else if(input == "d"){
            decode();
        }else{
            std::cout << "Not a command. Type \"help\" to learn what is." << std::endl;
        }
    }
}

void IO::help(){
    
}

void IO::inputting(){
    std::cin >> input;

    if(!fileExist("../../text" + input)){
        std::cout << "File doesn't exist and no point creating an empty file to read." << std::endl;
        return;
    }

    if(input.find(".dat") == input.size() - 5){
        if(!fileExist("../../text/key_" + input)){
            std::cout << "The Huffman tree to the coresponding file ins't in the folder." << std::endl;
            return;
        }
        root = new binaryTree(myRead("key_" + input));
    }
    content = myRead(input);
    opened = true;
}

void IO::outputting(){
    if(!opened){
        std::cout << "There is no text in memory to output to a file." << std::endl;
        return;
    }

    std::cin >> input;

    if(input.find("key_") == 0){
        std::cout << "Can't name a file with \"key_\" at the beginning of the name." << std::endl;
        return;
    }

    if(fileExist("../../text" + input)){
        std::string answer;
        std::cout << "File already exists. Do you want to override it? [y/n]" << std::endl;

        while(true){
            std::cin >> answer;

            if(answer == "y" || answer == "Y"){
                myWrite(input, content, encoded);
                break;
            }else if(answer == "n" || answer == "N"){
                return;
            }else{
                std::cout << "You didn't answer. Do you want to override it? [y/n]" << std::endl;
            }
        }
    }

    myWrite(input, content, encoded);

    if(encoded){
        myWrite("key_" + input, root->toString(), encoded);
    }

}

void IO::debug(){
    if(!opened){
        std::cout << "There is no text in memory to debug." << std::endl;
        return;
    }
    if(!encoded){
        std::cout << "The text isn't currently encoded." << std::endl;
        return;
    }

    std::cout << byteToNumber(content) << std::endl;
}

void IO::encode(){
    std::vector<std::pair<char,std::size_t>> frequencyTable = letterCounter(content);
    std::vector<std::pair<std::string, bool>> lookUpTable(256, std::make_pair("", false));
    std::string encodedBuffer;

    root = createHuffmanTree(frequencyTable);
    printHuffmanTree(root, 0, 0, lookUpTable);


    for(std::size_t t = 0; t < content.size(); ++t){
        encodedBuffer += lookUpTable[content[t]].first;
    }    

    std::cout << "File has been encoded." << std::endl
              << "Original size in bits: " << content.size() * 8 << std::endl
              << "Encoded size in bits: " << encodedBuffer.size() << std::endl
              << "Compression rate is " <<  (encodedBuffer.size() * 100) / (content.size() * 8)  << "%"<< std::endl;

    content = encodedBuffer;
    encoded == true;
}

void IO::decode(){

}
