#include "../algorithms/include/letterCounter.hpp"
#include "../algorithms/include/generateHuffmanTree.hpp"
#include "../structures/include/binaryTree.hpp"
#include <iostream>

int main(){
    std::vector<std::pair<char,std::size_t>> test;
    std::vector<std::pair<std::size_t, std::size_t>> lookUpTable(256, std::make_pair(0,0));

    test = letterCounter("this is an example of a huffman tree");
    printHuffmanTree(createHuffmanTree(test), 0, 1, lookUpTable);

    for(std::size_t j = 0; j < 256; ++j){
        if(lookUpTable[j].second > 0){
            std::size_t copy = lookUpTable[j].first;
            std::string binary = "";
            for(std::size_t i = 1; lookUpTable[j].first < (1 << (lookUpTable[j].second - i)) - 2; ++i){
                binary += "0";
            }

            if(copy == 0){
                binary += "0";
            }

            while(copy > 0){
                binary = (copy%2 ? "1" : "0") + binary;
                copy /= 2;
            }
            std::cout << binary <<" \"" << (char) j << "\"" << std::endl; 
        }
    }


}