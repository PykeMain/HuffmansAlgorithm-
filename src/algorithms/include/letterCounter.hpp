#include <vector>
#include <string>
#include <cstddef>
#include "../structures/include/binaryTree.hpp"
#include <queue>
#include<algorithm>

typedef std::pair<char,std::size_t> myPair;

std::vector<std::pair<char,std::size_t>> letterCounter(std::string);

binaryTree* createHuffmanTree(std::vector<std::pair<char,std::size_t>>);