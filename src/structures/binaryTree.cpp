#include "include/binaryTree.hpp"

void binaryTree::dealocate(){
    if(!this){
        return;
    }

    this->left->dealocate();
    this->right->dealocate();
    delete this;
}

void binaryTree::copyFrom(binaryTree* other){
    this->letter = other->getChar();
    this->occurrence = other->getOccurrence();

    this->left->copyFrom(other->getLeft());
    this->right->copyFrom(other->getRight());
}

binaryTree* binaryTree::createFromString(const std::string& str, std::size_t &current){
    if(str[current] == '0'){
        current += 9;
        return new binaryTree(std::stoi(str.substr(current - 8, 8)), 0);
    }
    ++current;
    return new binaryTree('\0', 0, createFromString( str, current), createFromString( str, current));

}

binaryTree::~binaryTree(){
    this->dealocate();
}

// binaryTree& operator= (const binaryTree* rhs){
//     if(this != &rhs){
//         this->left->dealocate();
//         this->right->dealocate();
//         copyFrom(rhs);
//     }
//     return *this;
// }


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
    return this->right;
}

std::string binaryTree::toString() const{
    if(this->noChildren()){
        std::string temp = "";
        for(int i = 0; i < 8; ++i){
            temp = ((((this->letter >> i) & 1 )== 0) ? "0" : "1") + temp;
        }
        return "0" + temp;
    }

    return "1" + this->left->toString() + "1" + this->right->toString();
}