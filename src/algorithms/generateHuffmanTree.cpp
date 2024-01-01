#include "include/generateHuffmanTree.hpp"
#include <iostream>

binaryTree* pickTree(std::queue<binaryTree*>& first, std::queue<binaryTree*>& second){
    if(first.size() == 0 && second.size() == 0){
        return nullptr;
    }

    if(second.size() == 0 || first.front()->getOccurrence() >= second.front()->getOccurrence()){
        binaryTree* buffer = first.front();
        first.pop();
        return buffer;
    }

    binaryTree* buffer = second.front();
    second.pop();
    return buffer;
}


binaryTree* createHuffmanTree(std::vector<myPair> occurrenceTable){
    std::queue<binaryTree*> leafs, trees;

    for(myPair p : occurrenceTable){
        leafs.push(new binaryTree(p.first, p.second));
    }


    binaryTree *firstT, *secondT;
    while(leafs.size() != 0 || trees.size() != 1){
        firstT = pickTree(leafs, trees);
        secondT = pickTree(leafs, trees);
        if(secondT != nullptr && firstT != nullptr){
            trees.push(new binaryTree('\0', firstT->getOccurrence() + secondT->getOccurrence(), firstT, secondT));
        }else if(firstT != nullptr){
            trees.push(firstT);
        }
    }

    return trees.front();
}

void printHuffmanTree(binaryTree* root, std::size_t code, std::size_t codeSize, std::vector<std::pair<std::size_t, std::size_t>>& lookUpTable){
    if(root == nullptr){
        std::cout << "Huh";
        return;
    }

    if(root->noChildren()){
        lookUpTable[root->getChar()] = std::make_pair(code, codeSize);
        return;
    }

    printHuffmanTree(root->getLeft(), (code << 1) + 1, codeSize + 1, lookUpTable);
    printHuffmanTree(root->getRight(),(code << 1), codeSize + 1, lookUpTable);
}