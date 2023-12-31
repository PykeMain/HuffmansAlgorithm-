#pragma once

#include <cstddef>

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
};