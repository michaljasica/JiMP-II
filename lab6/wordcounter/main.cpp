//
// Created by malikmontana on 10.04.18.
//

#include "WordCounter.h"
using datastructures::Word;
int main(){
    datastructures::WordCounter counter {Word("a"), Word("a"), Word("a"), Word("c"), Word("d"), Word("e")};
    std::cout<<counter.DistinctWords()<<" ";
    std::cout<<counter.TotalWords()<<" ";


    return 0;
}