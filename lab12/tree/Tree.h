//
// Created by malikmontana on 05.06.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <memory>

namespace tree {

    template <class T>
    class Tree{
    public:
        Tree(){};
        Tree(T tree):size_{1},left_{nullptr},right_{nullptr}{};
        T Value(){ return value_;};
        int Size(){ return size_;};
        int Depth(){ return depth_;};
        void Insert(T tree);
    private:
        int size_;
        T value_;
        int depth_;
        std::unique_ptr<Tree> left_;
        std::unique_ptr<Tree> right_;
    };

    template<class T>
    void Tree<T>::Insert(T tree) {

    }


}


#endif //JIMP_EXERCISES_TREE_H
