#include "include/letterCounter.hpp"

void heapify(std::vector<myPair>& array,const std::size_t& sizeTree, const std::size_t& root){
    std::size_t max = root, left = 2*root +1, right = 2*root + 2;

    if(left < sizeTree && array[left].second > array[max].second){
        max = left;
    }

    if(right < sizeTree && array[right].second > array[max].second){
        max = right;
    }

    if(max != root){
        myPair temp = array[root];
        array[root] = array[max];
        array[max] =  temp;

        heapify(array, sizeTree, max);
    }
}

void heapSort(std::vector<myPair>& array){
    for(std::size_t i = array.size() / 2 - 1; i > 0; i--){
        heapify(array, array.size(), i);
    }
    heapify(array, array.size(), 0);
    for(std::size_t i = array.size() - 1; i > 0; i--){
        myPair temp = array[i];
        array[i] = array[0];
        array[0] =  temp;
        heapify(array, i, 0);
    }
}

std::vector<myPair> letterCounter(std::string input){
    std::vector<std::size_t> alphabet(256, 0);
    std::vector<myPair> used;

    for(auto ch : input){
        ++alphabet[ch];
    }

    for(std::size_t i = 0; i < 256; ++i){
        if(alphabet[i] > 0){
            used.push_back(std::make_pair(i, alphabet[i]));
        }
    }
    heapSort(used);
    return used;
}