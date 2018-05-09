//
// Created by malikmontana on 28.04.18.
//

#include <memory>
#include <sstream>
#include <iostream>
#include "MovieSubtitles.h"

int main(){
    auto subs = std::make_unique<moviesubs::SubRipSubtitles>();
    std::stringstream in {"1\n00:05:54,555 --> 00:05:56,722\nText\n\n2\n00:06:06,433 --> 00:06:07,801\nNEWLINE\n"};
    std::stringstream out;
    subs->ShiftAllSubtitlesBy(300, 24, &in, &out);
    
    
    
    return 0;
}