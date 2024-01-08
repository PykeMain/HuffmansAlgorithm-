#pragma once

#include <cstddef>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>

typedef std::pair<char,std::size_t> myPair;

class binaryTree{
    private:
        binaryTree* left;
        binaryTree* right;
        std::size_t occurrence;
        char letter;

        void dealocate();
        void copyFrom(binaryTree*);
        binaryTree* createFromString(const std::string&, std::size_t&);
    
    public:
        binaryTree(char letter = '\0', std::size_t occurrence = 0, binaryTree* left = nullptr, binaryTree* right = nullptr):
            letter(letter), occurrence(occurrence), left(left), right(right)
        {};

        binaryTree(binaryTree* other){
            this->copyFrom(other);
        };


        ~binaryTree();

        binaryTree& operator= (binaryTree*);

        char getChar() const;
        std::size_t getOccurrence() const;
        bool noChildren() const;

        binaryTree* getLeft();
        binaryTree* getRight();
        
        std::string toString() const;
        void fromString(const std::string&);
};