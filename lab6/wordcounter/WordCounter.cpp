//
// Created by malikmontana on 10.04.18.
//

#include "WordCounter.h"


    datastructures::WordCounter::WordCounter(){

    }
    datastructures::WordCounter::~WordCounter(){

    }
    datastructures::WordCounter::WordCounter(std::initializer_list<Word> words){
        for(auto &i: words){
            bool next=true;
            for(auto &j: pairs){
                if(j.first == i){
                    ++j.second;
                    next=false;
                    break;
                }
            }
            if(next){
                pairs.emplace_back(std::make_pair(i,Counts(1)));////////////////
            }

        }
    }


std::ostream datastructures::WordCounter::operator<<(std::ostream &os){
    sort(pairs.begin(),pairs.end(),customLess);
    for(auto &i: pairs){
        os<<"Word: ";
        os<<i.first.Getword();
        os<<" ,Count: ";
        os<<i.second.Getcounts();
        os<<std::endl;
    }
}

int datastructures::WordCounter::DistinctWords() {
    int tmp=0;
    for(auto i : this->pairs){
        tmp++;
    }
    return tmp;
}

int datastructures::WordCounter::TotalWords() {
    int tmp=0;
    for(auto i: this->pairs){
        tmp+=i.second.Getcounts();
    }
    return tmp;
}

std::set<datastructures::Word> datastructures::WordCounter::Words() {
    std::set<Word> tmp;
    for(auto i: this->pairs){
        tmp.insert(i.first);
    }
    return tmp;
}

datastructures::WordCounter datastructures::WordCounter::FromInputStream(std::istream &is) {
    return datastructures::WordCounter();
}

int datastructures::WordCounter::operator[](std::string expected){
    for(auto i: pairs){
        if(i.first.Getword()==expected)
            return i.second.Getcounts();
    }
}


bool datastructures::Word::operator==(const datastructures::Word &one) const{
    return one.Getword() == this->Getword();
}

std::string datastructures::Word::Getword() const {
    return word;
}

datastructures::Word::Word() {

}

datastructures::Word::~Word() {

}

datastructures::Word::Word(std::string str) {
    word=str;
}

bool datastructures::Word::operator<(datastructures::Word wordelement) const {
    return false;
}

datastructures::Counts::Counts() {
    counts=0;
}

int datastructures::Counts::Getcounts() {
    return counts;
}

datastructures::Counts::Counts(std::initializer_list<datastructures::Word> words) {

}

datastructures::Counts::Counts(int number) {
    counts=number;
}

datastructures::Counts::~Counts() {

}

bool datastructures::Counts::operator==(datastructures::Counts countselement) const {
    return countselement.counts==counts;
}

void datastructures::Counts::operator++() {
    counts++;
}

bool datastructures::Counts::operator<(datastructures::Counts countselement) const {
    if(this->counts<countselement.counts)
        return true;
    return false;
}

bool datastructures::Counts::operator>(datastructures::Counts countselement) const {
    if(this->counts>countselement.counts)
        return true;
    return false;
}

