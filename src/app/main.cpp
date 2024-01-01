#include "../algorithms/include/letterCounter.hpp"
#include "../algorithms/include/generateHuffmanTree.hpp"
#include "../structures/include/binaryTree.hpp"
#include <iostream>
#include <bitset>

int main(){
    std::vector<std::pair<char,std::size_t>> test;
    std::vector<std::pair<std::size_t, std::size_t>> lookUpTable(256, std::make_pair(0,0));

    test = letterCounter("this is an example of a huffman tree");
    printHuffmanTree(createHuffmanTree(test), 0, 0, lookUpTable);

    for(std::size_t j = 0; j < 256; ++j){
        if(lookUpTable[j].second > 0){
            std::size_t copy = lookUpTable[j].first;
            std::string binary = "";

            while(copy > 0){
                binary = (copy%2 ? "1" : "0") + binary;
                copy /= 2;
            }

            while(binary.size() < lookUpTable[j].second){
                binary= "0" + binary;
            }
            std::cout << binary <<" \"" << (char) j << "\"" << std::endl; 
            //std::cout << lookUpTable[j].first <<" \"" << (char) j << "\"" << std::endl; 
        }
    }
}