#include "letterCounter.hpp"
#include "generateHuffmanTree.hpp"
#include "binaryTree.hpp"
#include "myRead.hpp"
#include "myWrite.hpp"
#include <iostream>
#include <bitset>

int main(){
    std::string name = "wibo.txt";
    std::string content = myRead(name);
    std::string encoded, decoded;

    std::vector<std::pair<char,std::size_t>> test = letterCounter(content);
    std::vector<std::pair<std::string, bool>> lookUpTable(256, std::make_pair("", false));
    std::vector<std::pair<std::string, bool>> lookUpTable2(256, std::make_pair("", false));
    binaryTree *tree = createHuffmanTree(test);

    printHuffmanTree(tree, 0, 0, lookUpTable);

    for(int i = 0; i < 256; ++i){
        if(lookUpTable[i].second){
            std::cout << (char) i << " " << lookUpTable[i].first << std::endl;
        }
    }

    for(std::size_t t = 0; t < content.size(); ++t){
        encoded += lookUpTable[content[t]].first;
    }

    std::cout << "Original size: " << content.size() * 8 << " bits and " << content.size() << "characters" << std::endl
              << "New size: " << encoded.size() <<  std::endl
              << "Compresion: ~" << (encoded.size() * 100) / (content.size() * 8)  << "%"<< std::endl;

    myWrite("test_wibo", encoded, false);
    myWrite("test2_wibo", encoded, true);

    std::string readingBinary = myRead("test2_wibo.dat");
    std::cout << readingBinary;

    decoded = decodeHuffman(tree, readingBinary);
    std::cout << "Decoded size: " << decoded.size()<< std::endl;

    myWrite("test_from_read_wibo", decoded, false);
    return 0;
}