#include "letterCounter.hpp"
#include "generateHuffmanTree.hpp"
#include "binaryTree.hpp"
#include "myRead.hpp"
#include <iostream>

int main(){
    std::string name = "wibawoba.txt";
    std::string content = myRead(name);
    std::string encoded;

    std::vector<std::pair<char,std::size_t>> test = letterCounter(content);
    std::vector<std::pair<std::string, bool>> lookUpTable(256, std::make_pair("", false));
    std::vector<std::pair<std::string, bool>> lookUpTable2(256, std::make_pair("", false));
    printHuffmanTree(createHuffmanTree(test), 0, 0, lookUpTable);

    for(int i = 0; i < 256; ++i){
        if(lookUpTable[i].second){
            std::cout << (char) i << " " << lookUpTable[i].first << std::endl;
        }
    }

    for(std::size_t t = 0; t < content.size(); ++t){
        encoded += lookUpTable[content[t]].first;
    }

    std::cout << "Original size: " << content.size() * 8 << std::endl
              << "New size: " << encoded.size() <<  std::endl
              << "Compresion: ~" << (encoded.size() * 100) / (content.size() * 8)  << "%"<< std::endl;

    return 0;
}