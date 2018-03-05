//
// Created by malikmontana on 05.03.18.
//

#include "Palindrome.h"

bool is_palindrome(std::string str){
    int dlugosc=str.length();
    for(int i=0;i<(dlugosc/2);i++)
        if(str[i]!=str[dlugosc-1-i])
            return false;
    return true;

}