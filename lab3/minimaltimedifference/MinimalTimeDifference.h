//
// Created by jasimich on 14.03.18.
//

#ifndef JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
#define JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H



#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include <cmath>

namespace minimaltimedifference{
    unsigned int ToMinutes(std::string time_HH_MM);

    unsigned int MinimalTimeDifference(std::vector<std::string> times);
}




#endif //JIMP_EXERCISES_MINIMALTIMEDIFFERENCE_H
