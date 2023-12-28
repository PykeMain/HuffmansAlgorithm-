#include "include/binaryTree.hpp"

void binaryTree::dealocate(){
    if(!this){
        return;
    }

    left->dealocate();
    right->dealocate();
    delete this;
}