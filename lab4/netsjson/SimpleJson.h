//
// Created by malikmontana on 23.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H
#include <experimental/optional>
#include <string>
#include <vector>
#include <map>

namespace nets{

    class JsonValue{
    public:
        JsonValue();
        ~JsonValue();
        JsonValue(int number1);
        JsonValue(double number2);
        JsonValue(std::string text);
        JsonValue(bool tof);
        JsonValue(std::vector<JsonValue> tab);
        JsonValue(std::map<std::string,JsonValue> map);

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;

        std::string ToString() const;

    private:
        std::experimental::optional<int> number1;
        std::experimental::optional<double> number2;
        std::experimental::optional<std::string> text;
        std::experimental::optional<bool> tof;
        std::experimental::optional<std::vector<JsonValue>> tab;
        std::experimental::optional<std::map<std::string,JsonValue>> map;

    };



}




#endif //JIMP_EXERCISES_SIMPLEJSON_H
