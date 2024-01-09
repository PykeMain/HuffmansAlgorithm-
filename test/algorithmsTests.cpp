#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "letterCounter.hpp"
#include "generateHuffmanTree.hpp"
#include "binaryTree.hpp"
#include "linkedQueue.hpp"

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

TEST_CASE("pickTree test"){
    LinkedQueue<binaryTree*> one, two;
    binaryTree  *result1 = new binaryTree('a', 1),
                *result2 = new binaryTree('a', 2),
                *result3 = new binaryTree('b', 3),
                *result4 = new binaryTree('c', 4);
    one.enqueue(result1);
    one.enqueue(result3);
    two.enqueue(result2);
    two.enqueue(result4);

    CHECK(pickTree(one, two) == result1);
    CHECK(pickTree(one, two) == result2);
    CHECK(pickTree(one, two) == result3);
    CHECK(pickTree(one, two) == result4);
}

TEST_CASE("createHuffmanTree test"){
    binaryTree  *tree1 = new binaryTree('a', (std::size_t)1),
                *tree2 = new binaryTree('d', (std::size_t)2),
                *tree3 = new binaryTree('b', (std::size_t)3),
                *tree4 = new binaryTree('c', (std::size_t)4);

    

    binaryTree *result = createHuffmanTree(letterCounter("caccbcbdbd"));

    CHECK(result->getLeft()->getOccurrence() == tree4->getOccurrence()); 
    CHECK(result->getLeft()->getChar() == tree4->getChar());
    CHECK(result->getRight()->getRight()->getOccurrence() == tree3->getOccurrence());
    CHECK(result->getRight()->getRight()->getChar() == tree3->getChar());
    CHECK(result->getRight()->getLeft()->getLeft()->getChar() == tree1->getChar());
    CHECK(result->getRight()->getLeft()->getLeft()->getOccurrence() == tree1->getOccurrence());
    CHECK(result->getRight()->getLeft()->getRight()->getChar() == tree2->getChar());
    CHECK(result->getRight()->getLeft()->getRight()->getOccurrence() == tree2->getOccurrence());

}

TEST_CASE("leafToBinary test"){
    CHECK(leafToBinary(1, 1) == "1"); 
    CHECK(leafToBinary(0, 2) == "00");
    CHECK(leafToBinary(3, 3) == "011");
    CHECK(leafToBinary(2, 3) == "010");
}

TEST_CASE("printHuffmanTree test"){
    std::vector<std::pair<std::string, bool>> testing(256, std::make_pair("",false));
    binaryTree* root = createHuffmanTree(letterCounter("caccbcbdbd"));
    printHuffmanTree(root, 0, 0, testing);

    CHECK(testing['c'].first == "1");
    CHECK(testing['b'].first == "00");
    CHECK(testing['a'].first == "011");
    CHECK(testing['d'].first == "010");
}


TEST_CASE("byteToNumber"){
    CHECK(byteToNumber("000110") == "6");
    CHECK(byteToNumber("11011") == "27");
    CHECK(byteToNumber("00011011") == "27 ");
    CHECK(byteToNumber("0001101100") == "27 0");
    CHECK(byteToNumber("00011011000001") == "27 1");
    CHECK(byteToNumber("1") == "1");
}

TEST_CASE("decodeHuffman"){
    std::vector<std::pair<std::string, bool>> testing(256, std::make_pair("",false));
    std::string encodedBuffer, content = "caccbcbdbd";
    binaryTree* root = createHuffmanTree(letterCounter(content));
    printHuffmanTree(root, 0, 0, testing);

    for(std::size_t t = 0; t < content.size(); ++t){
        encodedBuffer += testing[content[t]].first;
    };

    CHECK(decodeHuffman(root, encodedBuffer) == content);
}
