//
// Created by malikmontana on 29.03.18.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>

namespace pool{

    class TextPool{
    public:
        TextPool();
        ~TextPool();
        TextPool &operator=(TextPool &&tmp);
        TextPool( TextPool &&tmp);
        TextPool(const std::initializer_list<std::experimental::string_view> &strings);

        std::experimental::string_view Intern(const std::string &str);
        size_t StoredStringCount() const;

    private:
        std::set<std::experimental::string_view> texts;

    };
}


#endif //JIMP_EXERCISES_TEXTPOOL_H
