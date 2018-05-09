//
// Created by malikmontana on 30.03.18.
//

#include <iostream>
#include "Matrix.h"
using namespace algebra;

int main(){

    Matrix m1{{0.0, 0.0 - 1.0i}, {1.0i, 0.0}};
    std::cout<<m1.Print()<<std::endl;
    std::cout<<m1.Pow(2).Print()<<std::endl;
    //std::cout<<m1.Print()<<std::endl;
    //std::cout<<m2.Print()<<std::endl;
    //Matrix x(3,3);

    return 0;
}