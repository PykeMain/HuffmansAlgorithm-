// #include "letterCounter.hpp"
// #include "generateHuffmanTree.hpp"
// #include "binaryTree.hpp"
// #include "myRead.hpp"
// #include "myWrite.hpp"
// #include <iostream>
// #include <bitset>

// int main(){

//     // std::vector<std::pair<char,std::size_t>> test = letterCounter(content);
//     // std::vector<std::pair<std::string, bool>> lookUpTable(256, std::make_pair("", false));
//     // std::vector<std::pair<std::string, bool>> lookUpTable2(256, std::make_pair("", false));

//     // printHuffmanTree(tree, 0, 0, lookUpTable);

//     // for(int i = 0; i < 256; ++i){
//     //     if(lookUpTable[i].second){
//     //         std::cout << (char) i << " " << lookUpTable[i].first << std::endl;
//     //     }
//     // }

//     // for(std::size_t t = 0; t < content.size(); ++t){
//     //     encoded += lookUpTable[content[t]].first;
//     // }

//     // std::cout << "Original size: " << content.size() * 8 << " bits and " << content.size() << "characters" << std::endl
//     //           << "New size: " << encoded.size() <<  std::endl
//     //           << "Compresion: ~" << (encoded.size() * 100) / (content.size() * 8)  << "%"<< std::endl;

//     // //myWrite("test_abra", encoded, false);
//     // myWrite("test2_abra.dat", encoded, true);

//     // std::cout << readingBinary;

//     // std::cout << "Decoded size: " << decoded.size()<< std::endl
//     //           << "Encoded Debug mode: " << byteToNumber(encoded) << std::endl
//     //           << "Tree to string: " << tree->toString() << std::endl;


//     std::string name = "abra.txt";
//     std::string content = myRead(name);
//     std::string encoded, decoded;
//     binaryTree *tree = createHuffmanTree(letterCounter(content));
//     std::string readingBinary= myRead("test2_abra.dat");
//     //decoded = decodeHuffman(tree, readingBinary);
//     std::string huh = "test.dat";

//     //myWrite(huh, tree->toString(), true);


//     std::string rB = myRead("key_test.dat");

//     std::cout << "Reading tree: " << rB << std::endl;
//     // myWrite("test_from_read_abra1.txt", decoded, false);

//     binaryTree* root  = new binaryTree();
//     root->fromString(rB);
//     std::cout << std::boolalpha << root->getLeft()->noChildren() << " " << root->getLeft()->getChar() << std::endl;
//     std::string testing = decodeHuffman(root, readingBinary);
//     myWrite("test_bugfix.txt", testing, false);

//     return 0;
// }

#include "IO.hpp"

int main(){
    try{
        IO::getInstance().menu();
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    return 0;
}