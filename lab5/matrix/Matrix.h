//
// Created by malikmontana on 30.03.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <vector>
#include <complex>

namespace algebra{

    class Matrix {
    public:
        Matrix();
        ~Matrix();
        Matrix(int x,int y);
        Matrix(std::string text);
        Matrix(const Matrix &tmp);
        Matrix(std::initializer_list<std::vector<std::complex<double>>> init);

        Matrix Add(const Matrix &tmp) const;
        Matrix Sub(const Matrix &tmp);
        Matrix Mul(const Matrix &tmp);
        Matrix Pow(int n);

        Matrix set(std::complex<double>,int x,int y);

        std::string Print() const;

        int sizex() const;
        int sizey() const;
        std::pair<size_t ,size_t> Size();

    private:
        std::vector<std::vector<std::complex<double>>> values;
        int x,y;
    };

    std::string toStr(double old);
}



#endif //JIMP_EXERCISES_MATRIX_H
