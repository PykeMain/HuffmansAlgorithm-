#include "include/binaryTree.hpp"

void binaryTree::dealocate(){
    if(!this){
        return;
    }

    this->left->dealocate();
    this->right->dealocate();
    delete this;
}

binaryTree::~binaryTree(){
    this->dealocate();
}


void binaryTree::increment(){
    ++this->occurrence;
}

std::size_t binaryTree::getOccurrence() const{
    return this->occurrence;
}

char binaryTree::getChar() const{
    return this->letter;
}


bool binaryTree::noChildren() const{
    if(!this->left && !this->right){
        return true;
    }
    return false;
}

binaryTree* binaryTree::getLeft(){
    return this->left;
}

binaryTree* binaryTree::getRight(){
    return right;
}