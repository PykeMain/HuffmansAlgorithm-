#include "../algorithms/include/letterCounter.hpp"
#include <iostream>

int main(){
    std::vector<std::pair<char,std::size_t>> test;

    test = letterCounter("amsa1256");

    for(auto t : test){
        std::cout << t.first << " " << t.second << std::endl;
    }
}