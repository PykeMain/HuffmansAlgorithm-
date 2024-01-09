#pragma once

#include <vector>
#include <string>
#include <cstddef>
#include <iostream>

typedef std::pair<char,std::size_t> myPair;

void heapify(std::vector<myPair>&, const std::size_t&, const std::size_t& );

void heapSort(std::vector<myPair>&);

std::vector<myPair> letterCounter(std::string);