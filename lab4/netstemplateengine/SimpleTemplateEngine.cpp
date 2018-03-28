//
// Created by malikmontana on 23.03.18.
//
#include <SimpleTemplateEngine.h>

using std::string;

namespace nets{

    View::View(string templates){
        this->templates=templates;
    };

    string View::Render(const std::unordered_map <std::string, std::string> &model) const{
        string render,tmp;

        for(int i=0;i<templates.length();i++){
            if(templates[i]=='{' && templates[i+1]=='{' && isalpha(templates[i+2])){
                i=i+2;
                for(;i<templates.length();i++){
                    tmp+=templates[i];
                    if(templates[i+2]== '}' && templates[i+1]=='}')
                        break;
                }

                if(tmp.find('{')!=std::string::npos || tmp.find('}')!=std::string::npos)
                    render+="{{"+tmp+"}}";
                else
                    if(model.find(tmp)!=model.end())
                        render+=model.at(tmp);
                

                tmp="";
                i+=2;
                if(i==templates.length()-1)
                    break;
            }
            else
                render+=templates[i];
        }
        return render;
    }
};
