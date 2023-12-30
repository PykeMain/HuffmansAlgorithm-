#include "include/letterCounter.hpp"

std::vector<std::pair<char,std::size_t>> letterCounter(std::string input){
    std::vector<std::size_t> alphabet;
    std::vector<std::pair<char,std::size_t>> used;

    for(std::size_t i = 0; i < 256; ++i){
        alphabet.push_back(0);
    }

    for(auto ch : input){
        ++alphabet[ch];
    }

    for(std::size_t i = 0; i < 256; ++i){
        if(alphabet[i] > 0){
            used.push_back(std::make_pair(i, alphabet[i]));
        }
    }

    return used;
}