#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "binaryTree.hpp"
#include "linkedQueue.hpp"

// TEST_CASE("createFromString"){
//     CHECK(createFromString("001100001")->getChar() == 'a');
// }

TEST_CASE("getChar"){
    binaryTree *test = new binaryTree('a', 10);
    CHECK(test->getChar() == 'a');
}

TEST_CASE("getOccurrence"){
    binaryTree *test = new binaryTree('a', 10);
    CHECK(test->getOccurrence() == 10);
}

TEST_CASE("noChildren"){
    binaryTree *test = new binaryTree('a', 10);
    CHECK(test->noChildren() == true);
    binaryTree *test1 = new binaryTree('a', 10, test);
    CHECK(test1->noChildren() == false);
}

TEST_CASE("toString"){
    binaryTree *test = new binaryTree('a');
    CHECK(test->toString() == "001100001");

    binaryTree *test1 = new binaryTree('\0', 0, new binaryTree('a'), new binaryTree('a'));
    CHECK(test1->toString() =="1001100001001100001");
}

TEST_CASE("fromString"){
    binaryTree *test = new binaryTree();
    std::string str = "001100001";
    test->fromString(str);
    CHECK(test->getChar() == 'a');
}

TEST_CASE("front + enqueue"){
    LinkedQueue<int> q;
    q.enqueue(1);
    CHECK(q.front() == 1);
}

TEST_CASE("empty"){
    LinkedQueue<int> q;
    CHECK(q.empty() == true);
    q.enqueue(1);
    CHECK(q.empty() == false);
}

TEST_CASE("dequeue"){
    LinkedQueue<int> q;
    q.enqueue(1);
    q.dequeue();
    CHECK(q.empty() == true);
}