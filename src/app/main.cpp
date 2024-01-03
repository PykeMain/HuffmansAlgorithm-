#include "../algorithms/include/letterCounter.hpp"
#include "../algorithms/include/generateHuffmanTree.hpp"
#include "../structures/include/binaryTree.hpp"
#include <iostream>
#include <bitset>

int main(){
    std::vector<std::pair<char,std::size_t>> test;
    std::vector<std::pair<std::string, bool>> lookUpTable(256, std::make_pair("", false));
    std::vector<std::pair<std::string, bool>> lookUpTable2(256, std::make_pair("", false));
    std::string table = "";
    test = letterCounter("this is an example of a huffman tree");
    printHuffmanTree(createHuffmanTree(test), 0, 0, lookUpTable);

    std::string temp;
    for(int i = 0; i < 256; ++i){
        if(lookUpTable[i].second){
            std::cout << (char) i << " " << lookUpTable[i].first << std::endl;
        }
    }

}