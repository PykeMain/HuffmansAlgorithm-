#pragma once

/** @file generateHuffmanTree.hpp
 *  @brief A class for generating a Huffman tree, encoding and decoding a text with it
 *  @author Momchil Mladenov, 5MI0800232, Group 3
*/

#include "../../structures/include/binaryTree.hpp"
#include "../../structures/include/linkedQueue.hpp"


binaryTree* pickTree(std::queue<binaryTree*>& first, std::queue<binaryTree*>& second);

binaryTree* createHuffmanTree(std::vector<myPair> occurrenceTable);

void printHuffmanTree(binaryTree*, std::size_t, std::size_t, std::vector<std::pair<std::string, bool>>&);

std::string leafToBinary(std::size_t, std::size_t);

std::string byteToNumber(std::string);

std::string decodeHuffman(binaryTree*, std::string);