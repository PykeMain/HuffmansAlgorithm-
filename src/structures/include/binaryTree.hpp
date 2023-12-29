#pragma once

#include <vector>

class binaryTree{
    private:
        binaryTree* left;
        binaryTree* right;
        std::size_t occurrence;
        char letter;

        void dealocate();
        // binaryTree* copy(binaryTree*);
    
    public:
        binaryTree(char, std::size_t, binaryTree*, binaryTree*);

        void increment();
        char getChar() const;
};