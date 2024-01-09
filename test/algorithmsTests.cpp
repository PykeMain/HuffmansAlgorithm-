#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "letterCounter.hpp"
#include "generateHuffmanTree.hpp"

TEST_CASE("HeapSort testing"){
    std::vector<myPair> result, test;
    result.push_back(std::make_pair('h',(std::size_t)1));
    result.push_back(std::make_pair('e',(std::size_t)1));
    result.push_back(std::make_pair('o',(std::size_t)1));
    result.push_back(std::make_pair('l',(std::size_t)2));

    test.push_back(std::make_pair('h',(std::size_t)1));
    test.push_back(std::make_pair('l',(std::size_t)2));
    test.push_back(std::make_pair('e',(std::size_t)1));
    test.push_back(std::make_pair('o',(std::size_t)1));
    heapSort(test);
    CHECK(test == result);
}

TEST_CASE ("letterCounter testing"){
    std::vector<myPair> result1, result2;
    result1.push_back(std::make_pair('h',(std::size_t)1));
    result1.push_back(std::make_pair('e',(std::size_t)1));
    result1.push_back(std::make_pair('o',(std::size_t)1));
    result1.push_back(std::make_pair('l',(std::size_t)2));

    CHECK(letterCounter("hello") == result1);

    result2.push_back(std::make_pair('a',(std::size_t)1));
    result2.push_back(std::make_pair('l',(std::size_t)1));
    result2.push_back(std::make_pair('L',(std::size_t)3));

    CHECK(letterCounter("LLLla") == result2);
}

