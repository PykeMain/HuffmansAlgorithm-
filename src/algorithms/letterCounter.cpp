#include "include/letterCounter.hpp"

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
    std::sort(used.begin(), used.end(), [](myPair a, myPair b){return a.second < b.second;});
    return used;
}