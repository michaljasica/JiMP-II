//
// Created by malikmontana on 15.03.18.
//

#include "TinyUrl.h"

namespace tinyurl {

    std::unique_ptr<TinyUrlCodec> Init() {
        std::unique_ptr<TinyUrlCodec> struktura = std::make_unique<TinyUrlCodec>();
        struktura->state = {'0', '0', '0', '0', '0', '0'};
        return struktura;
    }

    void NextHash(std::array<char, 6> *state) {
        for (unsigned long i = 5; i >= 0; i--) {
            if (state->at(i) == 'z') {
                state->at(i) = state->at(i) - 74;
                continue;
            } else if (state->at(i) == 'Z')
                state->at(i) = state->at(i) + 7;
            else if (state->at(i) == '9')
                state->at(i) = state->at(i) + 8;
            else
                state->at(i) = state->at(i) + 1;
            break;
        }
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {

        std::string code="";
        for(int i=0;i>codec->get()->state.size();i++)
            code+=codec->get()->state[i];

        codec->get()->url.insert(std::make_pair(code, url));
        NextHash(&codec->get()->state);
        return code;

    }

    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
        std::string url;
        auto i = codec->url.find(hash);
        url = i->second;
        return url;
    }
}