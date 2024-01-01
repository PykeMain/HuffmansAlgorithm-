#include "../algorithms/include/letterCounter.hpp"
#include "../algorithms/include/generateHuffmanTree.hpp"
#include "../structures/include/binaryTree.hpp"
#include <iostream>

int main(){
    std::vector<std::pair<char,std::size_t>> test;
    std::vector<std::pair<std::size_t, std::size_t>> lookUpTable(256, std::make_pair(0,0));

    test = letterCounter("amsa1256");
    printHuffmanTree(createHuffmanTree(test), 0, 1, lookUpTable);

    for(std::size_t j = 0; j < 256; ++j){
        if(lookUpTable[j].second > 0){
            int i = 0;
            if(lookUpTable[j].first < (1 << (lookUpTable[j].second - i))){
                std::cout << "0";
            }
            std::cout << lookUpTable[j].first << " \"" << (char) j << "\""; 
        }
    }

    for(auto t : test){
        std::cout << t.first << " " << t.second << std::endl;
    }


}