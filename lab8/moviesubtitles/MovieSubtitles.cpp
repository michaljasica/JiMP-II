//
// Created by malikmontana on 28.04.18.
//

#include <iosfwd>
#include <sstream>
#include <locale>
#include <vector>
#include <memory>
#include <bits/basic_string.h>
#include <iostream>
#include <string>
#include <regex>
#include "MovieSubtitles.h"

void moviesubs::MicroDvdSubtitles::delay(const char *in, const char *out, int delay, int fps) {

}

void moviesubs::MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream*in, std::stringstream* out) {
    delay_=delay;
    fps_=fps;
    in_=in;
    //out_=out;

    std::string tmp =in->str();
    int tmplen=tmp.length();
    int fpsdelay=(delay*fps)/1000;
    std::string liczba;
    bool isnumber=false;
    bool flaga;
    bool flagi;
    std::vector<int> pary;
    int linia=1;
    std::string text_linia;

    if(fps<0){
        throw moviesubs::NegativeFrameAfterShift();
    }

    std::string tmpout;
    for(int i=0;i<tmplen;i++){

        /////linia
        text_linia+=tmp[i];
        if(tmp[i]=='\n'){
            linia++;
            text_linia="";
        }

        //std::cout<<text_linia<<std::endl;
        //////////////////////////////////////
        //if(pary.size()==1 && tmp[i]=='}' && isalpha(tmp[i+1]))
            //throw InvalidSubtitleLineFormat();

        if(pary.size()==1 && tmp[i-1]=='}'){
            if(tmp[i]!='{')
                throw InvalidSubtitleLineFormat();
        }


        ///////////////////////////////////////
        //std::cout<<tmp[i]<<std::endl;
        if(tmp[i]=='{'){
            liczba="";
            isnumber=true;
            tmpout+="{";


        }
        if(isnumber){
            if(tmp[i]=='}' ){
                flagi=1;
                for (char j : liczba) {
                    if(isalpha(j)){
                        flagi=0;
                        break;
                    }
                }

                if(liczba == "")
                    throw InvalidSubtitleLineFormat();

                //std::cout<<liczba<<std::endl;
                if (flagi) {

                    int x = std::stoi(liczba);
                    ///////
                    if(pary.size()==2)
                        pary.clear();
                    pary.emplace_back(x);
                    std::cout<<text_linia<<std::endl;

////////////////////////////////////////////////////////////////////////////
                    if(pary[0]>pary[1] && pary.size()==2){
                        std::string final=text_linia;
                        i++;
                        while(tmp[i]!='\n'){
                            final+=tmp[i];
                            i++;

                        }
                        throw SubtitleEndBeforeStart(linia,final);
                    }
                    ///////////////////////////////////////////////////////////
                    if(x+fpsdelay<0)
                        throw NegativeFrameAfterShift();

                    tmpout += std::to_string(x + fpsdelay);
                } else tmpout += liczba;

                isnumber=false;
                tmpout+="}";

            }
            else if(tmp[i]!='{'){
                liczba+=tmp[i];
            }
        }else{
            tmpout+=tmp[i];
        }
    }
    //std::cout<<fpsdelay;
    *out<<tmpout.c_str();


}

moviesubs::MicroDvdSubtitles::MicroDvdSubtitles() {

}

moviesubs::MicroDvdSubtitles::~MicroDvdSubtitles() {

}

moviesubs::MovieSubtitles::~MovieSubtitles() {

}

int moviesubs::SubtitleEndBeforeStart::LineAt() const {
    return where_;
}


void
moviesubs::SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, std::stringstream *in, std::stringstream *out) {
    std::regex pattern{"(([0-9]{2}):([0-9]{2}):([0-9]{2}),([0-9]{3}) --> ([0-9]{2}):([0-9]{2}):([0-9]{2}),([0-9]{3}))"};
    std::string tmp = in->str();
    std::vector<std::string> linie;
    std::vector<std::string> linie2;
    std::vector<std::string> czasy;
    std::string tmpx2;
    std::string tmpout;

    std::cout<<tmp;
    if(fps<0)
        throw NegativeFrameRateAfterShift();

    int minsek=0,sek=0,min=0,h=0;

    for (int i=0;i<tmp.length();i++){
        while(tmp[i]!='\n'){
            tmpx2+=tmp[i];
            i++;
        }
        i++;
        linie.emplace_back(tmpx2);
        tmpx2="";

        while(tmp[i]!='\n'){
            tmpx2+=tmp[i];
            i++;
        }
        i++;
        linie.emplace_back(tmpx2);
        tmpx2="";

        while(tmp[i]!='\n'){
            tmpx2+=tmp[i];
            i++;
        }
        linie.emplace_back(tmpx2);
        tmpx2="";
        i++;
        if(i+1<tmp.length() && !isdigit(tmp[i+1])){
            std::cout<<tmp[i]<<"xdxxdx"<<tmp[i+1];
            i++;
            while(tmp[i]!='\n'){
                tmpx2+=tmp[i];
                i++;
            }
            linie.emplace_back(tmpx2);
            tmpx2="";
            i++;
        }
    }

    ///////////////////Delay///////////////////
    if(delay>=1000){
        minsek=delay%1000;
        delay=delay/1000;
        if(delay>=60){
            sek=delay%60;
            delay=delay/60;
            if(delay>=60){
                min=delay%60;
                delay=delay/60;
                if(delay>=60){
                    h=delay%60;
                } else
                    h=delay;
            } else
                min=delay;
        } else
            sek=delay;
    } else
        minsek=delay;
    ///////////////////////////////////////////
    int liczba=0;
    std::string czas;
    for(int i=1;i<=linie.size();i=i+3){
        std::cmatch wynik;
        czas="";
        /////////////Strart>End/////////////////
        //if(stoi(wynik[3])>stoi(wynik[7]))

        ///////////////////////////////////
        if(regex_search(linie[i].c_str(),wynik,pattern)){
            /////////////////////////Klatki//////////////////
            if(i>1)
                if(stoi(linie[i-1])-stoi(linie[i-4])!=1)
                    throw OutOfOrderFrames();

            //////////////////////////////////////////////////


            /////////////Strart>End/////////////////
            //if(stoi(wynik[3])>stoi(wynik[7]))



            if(std::to_string(stoi(wynik[2])+h).length()==1)
                czas+="0"+std::to_string(stoi(wynik[2])+h)+":";
            else
                czas+=std::to_string(stoi(wynik[2])+h)+":";
            if(std::to_string(stoi(wynik[3])+min).length()==1)
                czas+="0"+std::to_string(stoi(wynik[3])+min)+":";
            else
                czas+=std::to_string(stoi(wynik[3])+min)+":";
            if(std::to_string(stoi(wynik[4])+sek).length()==1)
                czas+="0"+std::to_string(stoi(wynik[4])+sek)+",";
            else
                czas+=std::to_string(stoi(wynik[4])+sek)+",";
            if(std::to_string(stoi(wynik[5])+minsek).length()==1)
                czas+="0"+std::to_string(stoi(wynik[5])+minsek);
            else
                czas+=std::to_string(stoi(wynik[5])+minsek);

            czas+=" --> ";
            std::string wynik9=std::to_string((stoi(wynik[9])+minsek));
            std::string wynik8=std::to_string((stoi(wynik[8])+sek));

            if(stoi(wynik[9])+minsek>=1000){
                if(stoi(wynik[9])+minsek>=2000){
                    wynik8=std::to_string((stoi(wynik[8])+sek+2));
                    wynik9=std::to_string((stoi(wynik[9])+minsek-2000));
                }else{
                    wynik8=std::to_string((stoi(wynik[8])+sek+1));
                    wynik9=std::to_string((stoi(wynik[9])+minsek-1000));
                }

            }
            //std::cout<<wynik8<<std::endl;

            if(std::to_string(stoi(wynik[6])+h).length()==1)
                czas+="0"+std::to_string(stoi(wynik[6])+h)+":";
            else
                czas+=std::to_string(stoi(wynik[6])+h)+":";
            if(std::to_string(stoi(wynik[7])+min).length()==1)
                czas+="0"+std::to_string(stoi(wynik[7])+min)+":";
            else
                czas+=std::to_string(stoi(wynik[7])+min)+":";

            if(std::to_string(stoi(wynik8)).length()==1)
                czas+="0"+wynik8+",";
            else
                czas+=wynik8+",";

            if(std::to_string(stoi(wynik9)).length()==1)
                czas+="00"+std::to_string(stoi(wynik9));
            else if(std::to_string(stoi(wynik9)).length()==2)
                czas+="0"+std::to_string(stoi(wynik9));
            else
                czas+=std::to_string(stoi(wynik9));

            if(stoi(wynik[3])>stoi(wynik[7]))
                throw SubtitleEndBeforeStart(stoi(linie[i-1]),linie[i]);



            czasy.emplace_back(czas);
        }else{
            throw InvalidSubtitleLineFormat();
        }
    }

    if(delay<0)
        throw NegativeFrameAfterShift();

    for(int i=0;i<linie.size();i=i+3){
        tmpout+=linie[i]+"\n";
        tmpout+=czasy[i/3]+"\n";

        if(linie2.size()==1){
            tmpout+=linie2[0];
        }
        tmpout+=linie[i+2]+"\n\n";
    }

    linie.clear();
    czasy.clear();

    *out<<tmpout.c_str();
}

moviesubs::SubRipSubtitles::~SubRipSubtitles() {

}
