#pragma once

#include <vector>

class binaryTree{
    private:
        binaryTree* left;
        binaryTree* right;
        std::size_t occurrence;
        char letter;

        void dealocate();
        void copy(binaryTree* other);
};