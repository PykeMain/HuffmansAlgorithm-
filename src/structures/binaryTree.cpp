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
    std::cout << other->getChar() << " ";
        this->letter = other->getChar();
        this->occurrence = other->getOccurrence();
        return;
    }
    this->letter = other->getChar();
    this->occurrence = other->getOccurrence();
    this->left = new binaryTree (other->getLeft());
    this->right = new binaryTree (other->getRight());
}

binaryTree* binaryTree::createFromString(const std::string& str, std::size_t &current){
    std::cout << current << std::endl;
    if(current >= str.size()){
        std::cout << "did i enter?" << std::endl;
        return nullptr;
    }
    if(str[current] == '0'){
        binaryTree* buffer = new binaryTree(std::stoul(str.substr(current + 1, 8), 0, 2));
        std::cout << "stoul: " << std::stoul(str.substr(current + 1, 8), 0, 2) << std::endl;
        current+=9;
        return buffer;
    }
    current++;
    binaryTree* left = createFromString( str, current);
    binaryTree* right = createFromString( str, current);
    return new binaryTree('\0', 0, left, right);
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
        std::cout << this->letter << std::endl;
        for(int i = 0; i < 8; ++i){
            temp = ((((this->letter >> i) & 1 )== 0) ? "0" : "1") + temp;
        }
        return "0" + temp;
    }
    std::cout << "1" << std::endl;
    return "1" + this->left->toString() + this->right->toString();
}

void binaryTree::fromString(const std::string& str){
    std::size_t current = 0;
    this->copyFrom(createFromString(str, current));
}