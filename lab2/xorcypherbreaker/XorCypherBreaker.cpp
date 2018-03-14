//
// Created by malikmontana on 11.03.18.
//

#include "XorCypherBreaker.h"


bool CheckDirectory(const vector<string> &dictionary, string word) {

    for (int i=0;i<dictionary.size();i++){
        if(dictionary[i].compare(word)==0)
            return true;
    }
    return false;
}

std::string XorCypherBreaker(const std::vector<char> &cryptogram, int key_length, const std::vector<string> &dictionary){
    string key = "",tmp="";
    char ch;
    int x=0;

    for (int i=97; i<123; ++i){
        for (int j=97; j<123; ++j) {
            for (int k = 97; k < 123; ++k) {
                key = {(char)i, (char)j, (char)k};

                for(int l=0;l<cryptogram.size();l++){
                    ch=cryptogram[l]^key[l%key_length];
                    if(isalpha(ch))
                        tmp+=ch;
                    else if(ch==' ' && tmp.length()!=0){
                        if(CheckDirectory(dictionary,tmp))
                            x++;
                        tmp="";
                    }
                }
                if(x>17)
                    return key;
                else
                    x=0;
                }
            }
        }
    return "";
    }

