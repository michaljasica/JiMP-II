//
// Created by malikmontana on 15.03.18.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <utility>
#include <iostream>
#include <array>
#include <memory>
#include <string>
#include <map>

namespace tinyurl {

    struct TinyUrlCodec{
        std::array<char, 6> state;
        std::map <std::string,std::string> url;

    };

    std::unique_ptr<TinyUrlCodec> Init();

    void NextHash(std::array<char, 6> *state);

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec);

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash);
}



#endif //JIMP_EXERCISES_TINYURL_H
