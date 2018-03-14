//
// Created by jasimich on 14.03.18.
//

#include <iostream>
#include "MinimalTimeDifference.h"

namespace minimaltimedifference{
    unsigned int ToMinutes(std::string time_HH_MM){
        std::string h,m;
        unsigned int x,y;
        if(time_HH_MM.length()==5){
            h=time_HH_MM.substr(0,2);
            x=((h[0]-48)*10)+h[1]-48;
            m=time_HH_MM.substr(3,2);
            y=((m[0]-48)*10)+m[1]-48;
        }
        else if (time_HH_MM.length()==4){
            h=time_HH_MM.substr(0,1);
            x=h[0]-48;
            m=time_HH_MM.substr(2,2);
            y=((m[0]-48)*10)+m[1]-48;
        }
        else
            return 0;

        return x*60+y;

    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times){
        unsigned int min=abs(ToMinutes(times[0])-ToMinutes(times[1])),x=720;
        for(int i=0;i<times.size();i++){
            for(int j=i+1;j<times.size();j++){
                if(abs(ToMinutes(times[i])-ToMinutes(times[j]))>=720)
                    x=abs(ToMinutes(times[i])-ToMinutes(times[j]))-1440;
                else
                    x=abs(ToMinutes(times[i])-ToMinutes(times[j]));

                if(x<min){
                    min=x;
                }
            }
        }
    return min;
    }
}


