//
// Created by malikmontana on 23.03.18.
//

#include "SimpleJson.h"

namespace nets{

    JsonValue::JsonValue(int number1) {
        this->number1=number1;
    }
    JsonValue::JsonValue(double number2){
        this->number2=number2;
    }
    JsonValue::JsonValue(std::string text){
        this->text=text;
    }
    JsonValue::JsonValue(bool tof){
        this->tof=tof;
    }
    JsonValue::JsonValue(std::vector<JsonValue> tab){
        this->tab=tab;
    }
    JsonValue::JsonValue(std::map<std::string,JsonValue> map){
        this->map=map;
    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const{
        if(map){
            if(map->find(name)!=map->end()){
                JsonValue tmp = this->map->find(name)->second;
                return std::experimental::make_optional(tmp);
            }
            else
                return {};
        }
        else {};
    }


    std::string JsonValue::ToString() const {
        if (this->number1)
            return std::to_string(*number1);
        else if (number2) {
            std::string tmp1, tmp = std::to_string(*number2);
            int i = std::to_string(*number2).length() - 1;
            for (; i >= 0; i--) {
                if (tmp[i] != '0')
                    break;
            }
            for (int j = 0; j < i + 1; j++)
                tmp1 += tmp[j];

            return tmp1;
        } else if (tof) {
            if (*tof)
                return "true";
            else
                return "false";
        }
        else if (text){
            std::string tmp="\"";
            for(int i=0;i<(*text).length();i++){
                if((*text)[i]=='\\')
                    tmp+="\\\\";
                else if((*text)[i]=='\"'){
                    tmp+="\\\"";
                }
                else
                    tmp+=(*text)[i];
            }
            tmp+="\"";

            return tmp;
        }
        else if (tab) {
            std::string tmp1, tmp = "[";
            for(int i=0;i<(*tab).size();i++)
                tmp += (*tab)[i].ToString() + ", ";

            tmp = tmp.substr(0, tmp.length() - 2);
            tmp += "]";

            return tmp;
        }
        else if(map){
            std::string done = "{";
            for(auto i: (*map)) {

                std::string tmp = i.first;
                int k=0;
                for(int j=0;j<tmp.length();j++) {
                    if(((i.first)[j]=='\"' )|| ((i.first)[j]== '\\')) {
                        tmp.insert(j+k, "\\");
                        k++;
                    }
                }
                done += "\"" + tmp + "\": " + i.second.ToString() +", ";
            }
            done = done.substr(0,done.length()-2);
            done += "}";
            return done;

        }
        }
    };



