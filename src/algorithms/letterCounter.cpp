#include "include/letterCounter.hpp"

std::vector<myPair> letterCounter(std::string input){
    std::vector<std::size_t> alphabet;
    std::vector<myPair> used;

    for(std::size_t i = 0; i < 256; ++i){
        alphabet.push_back(0);
    }

    for(auto ch : input){
        ++alphabet[ch];
    }

    for(std::size_t i = 0; i < 256; ++i){
        if(alphabet[i] > 0){
            used.push_back(std::make_pair(i, alphabet[i]));
        }
    }
    std::sort(used.begin(), used.end(), [](myPair a, myPair b){return a.second > b.second;});
    return used;
}

binaryTree* createHuffmanTree(std::vector<myPair> occurrenceTable){
    std::queue<binaryTree*> leafs, trees;

    for(myPair p : occurrenceTable){
        leafs.push(new binaryTree(p.first, p.second));
    }

    binaryTree *firstT, *secondT;
    while(leafs.size() != 0 && trees.size() != 1){
        if(leafs.size() == 1 && trees.size() == 0){
            return leafs.front();
        }

        if(trees.size() == 0){
            firstT = leafs.front();
            leafs.pop();
            secondT = leafs.front();
            leafs.pop();
            trees.push(new binaryTree('\0',firstT->getOccurrence() + secondT->getOccurrence(), firstT, secondT));
            continue;
        }

        if()
    }

    return trees.front();
        
}