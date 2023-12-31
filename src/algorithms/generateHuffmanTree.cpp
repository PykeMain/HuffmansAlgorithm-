#include "include/generateHuffmanTree.hpp"

binaryTree* pickTree(LinkedQueue<binaryTree*>& first, LinkedQueue<binaryTree*>& second){
    if(first.empty() && second.empty()){
        return nullptr;
    }

    if(second.empty() || (!first.empty() && first.front()->getOccurrence() < second.front()->getOccurrence())){
        binaryTree* buffer = first.front();
        first.dequeue();
        return buffer;
    }

    binaryTree* buffer = second.front();
    second.dequeue();
    return buffer;
}


binaryTree* createHuffmanTree(std::vector<myPair> occurrenceTable){
    LinkedQueue<binaryTree*> leafs, trees;

    for(myPair p : occurrenceTable){
        leafs.enqueue(new binaryTree(p.first, p.second));
    }


    binaryTree *firstT, *secondT;
    while(!leafs.empty() || trees.size() != 1){
        firstT = pickTree(leafs, trees);
        secondT = pickTree(leafs, trees);
        if(secondT != nullptr && firstT != nullptr){
            trees.enqueue(new binaryTree('\0', firstT->getOccurrence() + secondT->getOccurrence(), firstT, secondT));
        }else if(firstT != nullptr){
            trees.enqueue(firstT);
        }
    }

    return trees.front();
}

void printHuffmanTree(binaryTree* root, std::size_t code, std::size_t codeSize, std::vector<std::pair<std::string, bool>>& lookUpTable){
    if(root == nullptr){
        throw std::invalid_argument("Somehow there is a stick in the tree");
    }

    if(root->noChildren()){
        lookUpTable[root->getChar()] = std::make_pair(leafToBinary(code, codeSize) , true);
        return;
    }

    printHuffmanTree(root->getLeft(), (code << 1) + 1, codeSize + 1, lookUpTable);
    printHuffmanTree(root->getRight(), (code << 1), codeSize + 1, lookUpTable);
}

std::string leafToBinary(std::size_t code, std::size_t codeSize){
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

std::string byteToNumber(std::string encoded){
    std::string result;
    for(std::size_t i = 0; i < encoded.size() / 8; ++i){
        result += std::to_string(std::stoi(encoded.substr(i*8, 8), 0, 2)) + " ";
    }
    if(encoded.size() % 8 != 0 && encoded.size() >= 8){
        result += std::to_string(std::stoi(encoded.substr(encoded.size() - encoded.size() % 8 + 1, encoded.size() % 8), 0, 2));
    }else if(encoded.size() % 8 != 0){
        result += std::to_string(std::stoi(encoded.substr(0, encoded.size()), 0, 2));
    }
    return result;
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
