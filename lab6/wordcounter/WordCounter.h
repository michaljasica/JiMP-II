//
// Created by malikmontana on 10.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <initializer_list>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <iomanip>

namespace datastructures{

    class Word{
    public:
        Word();
        Word(std::string str);
        ~Word();

        bool operator==(const Word &one) const;
        bool operator<(Word wordelement) const ;

        std::string Getword() const;
    private:
        std::string word;


    };

    class Counts{
    public:
        Counts();
        Counts(std::initializer_list<Word> words);
        Counts(int number);
        ~Counts();

        int Getcounts();

        bool operator==(Counts countselement) const ;
        bool operator<(Counts countselement) const ;
        bool operator>(Counts countselement) const ;
        void operator++() ;

    private:
        int counts;

    };

    class WordCounter{
    public:
        WordCounter();
        WordCounter(std::initializer_list<Word> words);
        ~WordCounter();


        int DistinctWords();
        int TotalWords();
        int operator[](std::string expected);
        std::set<Word> Words();

        static WordCounter FromInputStream(std::istream &is);
        std::ostream operator<<(std::ostream &os);


    private:
        std::vector<std::pair<Word,Counts>> pairs;

    };

    struct{
        bool operator()(std::pair<Word,Counts> a, std::pair<Word,Counts> b) const{
            return a.first.Getword()<b.first.Getword();
        }
    }customLess;

}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
