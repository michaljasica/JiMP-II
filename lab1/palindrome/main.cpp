//
// Created by malikmontana on 05.03.18.
//

#include <iostream>
#include "Palindrome.h"

int main(){
    char wybor;
    while(true){
        std::cout<<"Wybierz:"<<std::endl;
        std::cout<<"1.Sprawdz palindrom"<<std::endl;
        std::cout<<"2.Wyjście"<<std::endl;
        std::cin>>wybor;
        switch(wybor){
            case '1':
            {
                std::string napis;
                std::cout<<"Podaj palindrom"<<std::endl;
                std::cin>>napis;
                if(is_palindrome(napis)== true)
                    std::cout<<"Napis jest plaindromem"<<std::endl;
                else
                    std::cout<<"Napis nie jest plaindromem"<<std::endl;
                break;
            }
            case '2':
                return 0;
            default:
                std::cout<<"Wpisz 1 lub 2!"<<std::endl;
                break;
        }
        std::cout<<std::endl;
    }

}