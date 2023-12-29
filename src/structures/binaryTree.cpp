#include "include/binaryTree.hpp"

void binaryTree::dealocate(){
    if(!this){
        return;
    }

    this->left->dealocate();
    this->right->dealocate();
    delete this;
}

binaryTree::binaryTree(char letter = '\0', std::size_t occurrence = 0, binaryTree* left = nullptr, binaryTree* right = nullptr):
    letter(letter), occurrence(occurrence), left(left), right(right)
{};


void binaryTree::increment(){
    ++this->occurrence;
}

char binaryTree::getChar() const{
    return this->letter;
}
