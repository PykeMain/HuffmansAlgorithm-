#pragma once

#include <cstddef>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

typedef std::pair<char,std::size_t> myPair;

class binaryTree{
    private:
        binaryTree* left;
        binaryTree* right;
        std::size_t occurrence;
        char letter;

        void dealocate();
        // binaryTree* copy(binaryTree*);
    
    public:
        binaryTree(char = '\0', std::size_t = 0, binaryTree* = nullptr, binaryTree* = nullptr);

        void increment();
        char getChar() const;
        std::size_t getOccurrence() const;
        bool noChildren() const;

        binaryTree* getLeft();
        binaryTree* getRight();
};