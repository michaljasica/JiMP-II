//
// Created by malikmontana on 30.03.18.
//

#include <iostream>
#include "Matrix.h"


algebra::Matrix::Matrix(int x, int y) {
    for(int i=0;i<x;i++){
        values.push_back({0,0});
        for(int j=0;j<y;j++)
            values[i].push_back({0,0});
    }
    this->x=x;
    this->y=y;

}

algebra::Matrix::Matrix(std::string text) {

}

algebra::Matrix::Matrix(const algebra::Matrix &tmp) {

    for(int i=0;i<tmp.x;i++){
        values.push_back({0,0});
        for(int j=0;j<tmp.y;j++)
            values[i].push_back({0,0});
    }

    for(int i=0;i<tmp.x;i++){
        for(int j=0;j<tmp.y;j++){
            values[i][j]=tmp.values[i][j];
        }
    }
    x=tmp.x;
    y=tmp.y;
}

algebra::Matrix algebra::Matrix::Add(const algebra::Matrix &tmp) const {

    if(x==tmp.sizex() && y==tmp.sizey()){
        Matrix result(x, y);
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++) {
                result.values[i][j] = values[i][j]+tmp.values[i][j];
            }
        }
        result.x=x;
        result.y=y;
        return result;
    }
    else
        return Matrix();
}

algebra::Matrix algebra::Matrix::Sub(const algebra::Matrix &tmp) {

    if(x==tmp.sizex() && y==tmp.sizey()){
        Matrix result(x, y);
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++) {
                result.values[i][j] = values[i][j]-tmp.values[i][j];
            }
        }
        result.x=x;
        result.y=y;
        return result;
    }
    else
        return Matrix();
}

algebra::Matrix algebra::Matrix::Mul(const algebra::Matrix &tmp) {

    if(y==tmp.sizex()){
        Matrix result(x, tmp.y);
        for(int i=0;i<x;i++)
            for(int j=0;j<tmp.y;j++)
                for(int k=0;k<tmp.x;k++){
                    result.values[i][j]+= values[i][k]*tmp.values[k][j];
                }

        result.x=x;
        result.y=tmp.y;
        return result;
    }
    else
        return Matrix();
}

algebra::Matrix algebra::Matrix::Pow(int n) {
    if(x==y){
        Matrix result(x,y);
        if(n==0){
            for(int i=0;i<x;i++)
                result.values[i][i]=1.;
        }
        else if(n==1)
            return Matrix(*this);
        else
        {
            result=(*this);
            for(int i=1;i<n;i++)
                result = result.Mul(*this);
        }
        return result;

    } else
        return Matrix();
}

algebra::Matrix algebra::Matrix::set(std::complex<double>, int x, int y) {
    return algebra::Matrix();
}

int algebra::Matrix::sizex() const {
    return this->x;
}

int algebra::Matrix::sizey() const {
    return this->y;
}

std::pair<size_t, size_t> algebra::Matrix::Size() {
    return std::pair<size_t, size_t>{x,y};
}

algebra::Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> init) {
    int tmp=0;

    for(int i=0;i<init.size();i++){
        values.push_back({0,0});
        for(int j=0;j<init.size();j++)
            values[i].push_back({0,0});
    }
    int k;
    for (auto i: init) {
        for (k=0;k<i.size();k++){
            values[tmp][k]=i[k];
        }
        tmp++;

    }

    this->x=tmp;
    this->y=k;


}

std::string algebra::Matrix::Print() const {

    if (x==0 || y==0)
        return "[]";

    std::string result="[";
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            result+=toStr(values[i][j].real());
            result+="i";
            result+=toStr(values[i][j].imag());
            if(j!=y-1)
                result+=", ";
            else
                result+="; ";
        }

    }
    result=result.substr(0,result.length()-2);
    result+="]";


    return result;

}

algebra::Matrix::Matrix() {
    x=0;
    y=0;
}

algebra::Matrix::~Matrix() {

}

std::string algebra::toStr(double old) {
    std::string tmp1, tmp = std::to_string(old);
    bool x=true;
    int i = tmp.length() - 1;


    for (; i >= 0; i--) {
        if (tmp[i] != '0' && tmp[i] != '.')
            break;
        if (tmp[i] == '.'){
            i=i-1;
            break;
        }

    }
    for (int j = 0; j < i+1; j++)
        tmp1 += tmp[j];
    if(tmp1=="")
        return "0";
    return tmp1;
}
