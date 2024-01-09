#pragma once

/** @file letterCounter.hpp
 *  @brief Implementation of a letter counter in a given text and a sort it requires 
 *  @author Momchil Mladenov, 5MI0800232, Group 3
*/

#include <vector>
#include <string>
#include <cstddef>
#include <iostream>


typedef std::pair<char,std::size_t> myPair;

//! Treats the array as a tree and swaps the children if they have larger values than their partent.
//! @param array Array of pairs of chars and std::size_t
//! @param sizeTree The max amount a child can be. If larger then that then it's ignored
//! @param root The parent index
void heapify(std::vector<myPair>& array,const std::size_t& sizeTree, const std::size_t& root);

//! Starts a heap sort using the heapify function
//! @param array Array of pairs of chars and std::size_t
void heapSort(std::vector<myPair>& array);

//! Counts the letters in a given text one after another. Sorts the used letters after the counting has finished.
//! @param input Text
//! @return Sorted array of letters and the times each has occured
std::vector<myPair> letterCounter(std::string input);