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
    if(other->noChildren()){
        this->letter = other->getChar();
        this->occurrence = other->getOccurrence();
        this->left = nullptr;
        this->right = nullptr;
        return;
    }
    this->letter = other->getChar();
    this->occurrence = other->getOccurrence();
    this->left = new binaryTree (other->getLeft());
    this->right = new binaryTree (other->getRight());
}

binaryTree* binaryTree::createFromString(const std::string& str, std::size_t &current){
    if(current >= str.size()){
        return nullptr;
    }
    if(str[current] == '0'){
        binaryTree* buffer = new binaryTree(std::stoul(str.substr(current + 1, 8), 0, 2));
        current+=9;
        return buffer;
    }else{
        current++;
        binaryTree* left = createFromString( str, current);
        binaryTree* right = createFromString( str, current);
        return new binaryTree('\0', 0, left, right);
    }
}

binaryTree::~binaryTree(){
    this->dealocate();
}

binaryTree& binaryTree::operator= (binaryTree* rhs){
    if(this != rhs){
        if(this->left != nullptr){
            this->left->dealocate();
        }
        if(this->right != nullptr){
            this->right->dealocate();
        }
        copyFrom(rhs);
    }
    return *this;
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
    return this->right;
}

std::string binaryTree::toString() const{
    if(this->noChildren()){
        std::string temp = "";
        unsigned char copy = this->letter;
        for(int j = 0; j < 8; ++j){
            temp = ((copy % 2 == 0) ? '0' : '1') + temp;
            copy /= 2; 
        }
        return "0" + temp;
    }
    return "1" + this->left->toString() + this->right->toString();
}

void binaryTree::fromString(const std::string& str){
    std::size_t current = 0;
    this->copyFrom(createFromString(str, current));
}