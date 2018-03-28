//
// Created by malikmontana on 23.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#include <string>
#include <unordered_map>

using std::string;

namespace nets{

    class View{
    public:
        View(string templates);
        ~View(){};


        string Render(const std::unordered_map <std::string, std::string> &model) const;

    private:
        string templates;

    };
};




#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
