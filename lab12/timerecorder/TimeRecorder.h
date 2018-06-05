//
// Created by malikmontana on 23.05.18.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <chrono>
#include <utility>

namespace profiling{
    template <typename T>
    auto TimeRecorder(T type){

        auto start = std::chrono::system_clock::now();
        auto object = type();
        auto end = std::chrono::system_clock::now();

        std::chrono::duration<double,std::milli> elapsed_seconds = end-start;

        return std::make_pair(object,elapsed_seconds.count());
    }


}


#endif //JIMP_EXERCISES_TIMERECORDER_H
