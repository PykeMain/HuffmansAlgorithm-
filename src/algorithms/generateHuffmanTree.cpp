#include "include/generateHuffmanTree.hpp"
#include <iostream>

binaryTree* pickTree(std::queue<binaryTree*>& first, std::queue<binaryTree*>& second){
    if(first.size() == 0 && second.size() == 0){
        return nullptr;
    }

    if(second.size() == 0 || (first.size() != 0 && first.front()->getOccurrence() < second.front()->getOccurrence())){
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

void printHuffmanTree(binaryTree* root, std::size_t code, std::size_t codeSize, std::vector<std::pair<std::string, bool>>& lookUpTable){
    if(root == nullptr){
        std::cout << "Huh";
        return;
    }

    if(root->noChildren()){
        lookUpTable[root->getChar()] = std::make_pair(treeToBinary(code, codeSize) , true);
        return;
    }

    printHuffmanTree(root->getLeft(), (code << 1) + 1, codeSize + 1, lookUpTable);
    printHuffmanTree(root->getRight(), (code << 1), codeSize + 1, lookUpTable);
}

std::string treeToBinary(std::size_t code, std::size_t codeSize){
    std::string binary = "";

    while(code > 0){
        binary = (code%2 ? "1" : "0") + binary;
        code /= 2;
    }

    for(std::size_t i = codeSize - binary.size(); i > 0; --i){
        binary= "0" + binary;
    }
    return binary;
}

std::string decodeHuffman(binaryTree* root, std::string encoded){
    std::string result;
    binaryTree *temp = root;
    for(std::size_t i = 0; i < encoded.size(); ++i){
        if(encoded[i] == '1'){
            temp = temp->getLeft();
        }else{
            temp = temp->getRight();
        }

        if(temp->noChildren()){
            result += temp->getChar();
            temp = root;
        }
    }
    return result;
}
