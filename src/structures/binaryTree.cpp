#include "include/binaryTree.hpp"

void binaryTree::dealocate(){
    if(!this){
        return;
    }

    this->left->dealocate();
    this->right->dealocate();
    delete this;
}

/* binaryTree* binaryTree::createFromString(const std::string& str, std::size_t &current){
    if(str[current] == "0"){
        current += 9;
        return new binaryTree(std::stoi(str.substr(current - 8, 8)), 0, );
    }

    return new binaryTree('/0')

}*/ 

// binaryTree::binaryTree(const std::string& str){
//     this = createFromString(str);
// }

binaryTree::~binaryTree(){
    this->dealocate();
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
        for(int i = 0; i < 8; ++i){
            temp = ((((this->letter >> i) & 1 )== 0) ? "0" : "1") + temp;
        }
        return "0" + temp;
    }

    return "1" + this->left->toString() + "1" + this->right->toString();
}