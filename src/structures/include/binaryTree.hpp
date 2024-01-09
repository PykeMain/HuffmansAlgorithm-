#pragma once

/** @file binaryTree.hpp
 *  @brief A class for the binary Huffman tree
 *  @author Momchil Mladenov, 5MI0800232, Group 3
*/

/**
 * @class binaryTree
*/

#include <cstddef>
#include <vector>
#include <string>

//! Easer use of the pair char and size_t in code
typedef std::pair<char,std::size_t> myPair;

class binaryTree{
    private:
        binaryTree* left; //!< Location of left child
        binaryTree* right; //!< Location of right child
        std::size_t occurrence; //!< If leaf - count of the letter in the text. If not leaf - sum of children's occurrences.
        char letter; //!< The symbol that is being counted if it's a leaf. Otherwise - \0 

        //! Dealocation of the member and all descendents
        void dealocate();

        //! Deep copy function
        //! @param other The tree the deep copy is made of
        void copyFrom(binaryTree* other); 

        //! Recursively creates a tree from a given binary sequence
        //! @param str The binary sequence. 1 - go lower, 0 - next 8 bits are a leaf
        //! @param current The location of the function in the sequence
        binaryTree* createFromString(const std::string& str, std::size_t &current);
    
    public:
        //! Constructor
        binaryTree(char letter = '\0', std::size_t occurrence = 0, binaryTree* left = nullptr, binaryTree* right = nullptr):
            letter(letter), occurrence(occurrence), left(left), right(right)
        {};

        //! Copy contructor
        binaryTree(binaryTree* other){
            this->copyFrom(other);
        };

        //! Destuctor
        ~binaryTree();

        //! Operator =
        binaryTree& operator= (binaryTree*);

        //! Access to the letter
        //! @return The letter of the current node
        char getChar() const;

        //! Access to the times a letter has occured
        //! @return The times a letter has occured
        std::size_t getOccurrence() const;

        //! Checks whether both pointers are nullptr.
        //! @return Bool value
        bool noChildren() const;

        //! Access to the left child
        //! @return Pointer to left child
        binaryTree* getLeft();
        
        //! Access to right child
        //! @return Pointer to right child
        binaryTree* getRight();
        
        //! Writes the tree into string. 1 - go lower, 0 - next 8 bits are a leaf
        //! @return
        std::string toString() const;

        //! Calls createFromString with std::size_t = 0
        //! @param str Encoded tree
        void fromString(const std::string& str);
};