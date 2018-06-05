//
// Created by malikmontana on 05.06.18.
//

#include "TeacherHash.h"

academia::TeacherId::operator int() const {
    return id_;
}

academia::TeacherId academia::Teacher::Id() const {
    return id_;
}

std::string academia::Teacher::Name() const{
    return name_;
}

std::string academia::Teacher::Department() const{
    return department_;
}

bool academia::Teacher::operator!=(const academia::Teacher &teacher) const {
    return !(id_==teacher.id_ && name_==teacher.name_ && department_==teacher.department_ );
}

bool academia::Teacher::operator==(const academia::Teacher &teacher) const {
    return (id_==teacher.id_ && name_==teacher.name_ && department_==teacher.department_ );
}

size_t academia::TeacherHash::operator()(const academia::Teacher &teacher) const {
    return std::hash<int>()(teacher.Id()) + std::hash<std::string>()(teacher.Name()) + std::hash<std::string>()(teacher.Department()) ;
}
