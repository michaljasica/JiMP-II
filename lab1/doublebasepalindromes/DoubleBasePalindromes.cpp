//
// Created by malikmontana on 05.03.18.
//

#include "DoubleBasePalindromes.h"

std::string ToStr(int value,int base){
    std::string str;
    std::string tmp;
    while(value>0){
        tmp=(value%base)+'0';
        value=value/base;
        str=tmp+str;
    }
    return str;
}

bool is_palindrome(std::string str){
    int dlugosc=str.length();
    for(int i=0;i<(dlugosc/2);i++)
        if(str[i]!=str[dlugosc-1-i])
            return false;
    return true;

}

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    std::string base2;
    std::string base10;
    int lenght2=0;
    int lenght10=0;
    bool isPalindrome;

    uint64_t suma=0;

    for(int i=0;i<=max_vaule_exculsive;i++){
        isPalindrome=true;
        base2=ToStr(i,2);
        base10=ToStr(i,10);

        isPalindrome=is_palindrome(base2);

        if(isPalindrome == true)
            isPalindrome=is_palindrome(base10);

        if(isPalindrome == true)
            suma=i+suma;
    }
    return suma;

}