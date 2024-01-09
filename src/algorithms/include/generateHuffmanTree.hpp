#pragma once

/** @file generateHuffmanTree.hpp
 *  @brief A class for generating a Huffman tree, encoding and decoding a text with it
 *  @author Momchil Mladenov, 5MI0800232, Group 3
*/

#include "../../structures/include/binaryTree.hpp"
#include "../../structures/include/linkedQueue.hpp"

//! Chooses the smallest tree from both queue and dequeues the element.
//! @param first A queue made from a linked list consisting entirely of leafs
//! @param second A queue made from a linked list consisting of nonleafs
//! @return The smallest tree 
binaryTree* pickTree(LinkedQueue<binaryTree*>& first, LinkedQueue<binaryTree*>& second);

//! Generates a Huffman tree. By getting the 2 smallest trees it combines then into a new tree with a root their combined occurrence. It stops when there is only 1 element left in both, which is the Huffman tree.
//! @param occurrenceTable Created from letterCounter.cpp and tells how often each symbol occurs.
//! @return The Huffman tree.
binaryTree* createHuffmanTree(std::vector<myPair> occurrenceTable);

//! Generates recursively the encoded values for every used symbol from the Huffman tree. Going left gives a 1, while going right - 0.
//! @param root The Huffman tree
//! @param code Current binary encoding
//! @param codeSize Used for remembering the leading zeros
//! @param lookUpTable Vector remembering which symbol is used and what is the given code.
void printHuffmanTree(binaryTree* root, std::size_t code, std::size_t codeSize, std::vector<std::pair<std::string, bool>>& lookUpTable);

//! From a given code and codeSize it returns the binary in string format.
//! @param code Binary encoding
//! @param codeSize Used for remembering the leading zeros
//! @return Encoded binary representation of the symbol
std::string leafToBinary(std::size_t code, std::size_t codeSize);

//! From an exact binary sequence it creates the decimal number it represents.
//! @param encoded Binary sequence
//! @return The decimal number behind the binary sequence
std::string byteToNumber(std::string encoded);

//! Decodes the text from a given tree. The function goes down the tree and when it reaches a leaf it records the symbol connected to it.
//! @param encoded Binary sequence
//! @param root The Huffman tree
//! @return The decoded version of the text
std::string decodeHuffman(binaryTree* root, std::string encoded);