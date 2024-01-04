#include "../algorithms/include/letterCounter.hpp"
#include "../algorithms/include/generateHuffmanTree.hpp"
#include "../structures/include/binaryTree.hpp"
#include <iostream>
#include <bitset>
#include <fstream>

int main(){
    std::string name = "wibawoba.txt";
    std::string content;
    std::ifstream in("../../text/" + name);

    if(!in.is_open()){
        throw std::invalid_argument("lmao");
    }
    std::string temp;
    while(!in.eof()){
        std::getline(in, temp);
        content += temp;
    }
    std::vector<std::pair<char,std::size_t>> test = letterCounter(content);
    std::vector<std::pair<std::string, bool>> lookUpTable(256, std::make_pair("", false));
    std::vector<std::pair<std::string, bool>> lookUpTable2(256, std::make_pair("", false));
    printHuffmanTree(createHuffmanTree(test), 0, 0, lookUpTable);

    for(int i = 0; i < 256; ++i){
        if(lookUpTable[i].second){
            std::cout << (char) i << " " << lookUpTable[i].first << std::endl;
        }
    }

}