//
// Created by malikmontana on 05.06.18.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>

namespace academia{

    class TeacherId{
    public:
        explicit TeacherId(int id):id_(id){};
        operator int() const;
    private:
        int id_;
    };


    class Teacher{
    public:
        Teacher(TeacherId id,std::string name,std::string department):id_(id),name_(name),department_(department){};
        TeacherId Id() const ;
        std::string Name() const;
        std::string Department() const;

        bool operator !=(const Teacher &teacher) const;
        bool operator ==(const Teacher &teacher) const;
    private:
        TeacherId id_;
        std::string name_;
        std::string department_;

    };

    class TeacherHash{
    public:
        TeacherHash() = default;
        size_t operator()(const Teacher &teacher) const;
    };




}


#endif //JIMP_EXERCISES_TEACHERHASH_H
