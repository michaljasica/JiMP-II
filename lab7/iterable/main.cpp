//
// Created by malikmontana on 27.04.18.
//
#include "Iterable.h"
#include <iostream>
#include <vector>

int main(){

    std::vector<int> vi {4, 77, -91,7,8};
    std::vector<std::string> vs {"4", "9991", "adfskld"};

    for(int i= static_cast<int>(vs.size()); i < vi.size(); ++i)
        vs.emplace_back(vs.back());

    for(auto &p:vs)
        std::cout<<p<<std::endl;

    return 0;
}