//
// Created by malikmontana on 29.03.18.
//

#include "TextPool.h"

namespace pool {

    TextPool::TextPool() {
    }

    TextPool::~TextPool(){
    }

    TextPool & TextPool::operator=(TextPool &&tmp){
        if(this==&tmp)
            return tmp;
        swap(texts,tmp.texts);
        return *this;

    }

    TextPool::TextPool( TextPool &&tmp){
        swap(texts,tmp.texts);
    }

    TextPool::TextPool(const std::initializer_list<std::experimental::string_view> &strings) {
            for(auto &i :strings)
                texts.insert(i);
    }

    std::experimental::string_view TextPool::Intern(const std::string &str){
        for(auto i: texts)
            if(i==str)
                return i;
        texts.insert(str);
        return str;
    }

    size_t TextPool::StoredStringCount() const{
        return texts.size();
    }

}