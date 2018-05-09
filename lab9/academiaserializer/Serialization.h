//
// Created by jasimich on 09.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <functional>
#include <vector>

namespace academia{

    class Serializable{

    };

    class Serializer {
    public:
        Serializer()=default;
        Serializer(std::ostream *out){};
        virtual void Serialize(Serializer *serializer) const =0;
        virtual void IntegerField(const std::string &field_name, int value) =0;
        virtual void DoubleField(const std::string &field_name, double value) =0;
        virtual void StringField(const std::string &field_name, const std::string &value) =0;
        virtual void BooleanField(const std::string &field_name, bool value) =0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) =0;
        virtual void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) =0;
        virtual void Header(const std::string &object_name) =0;
        virtual void Footer(const std::string &object_name) =0;

    };

    class Room:public Serializer {
    public:
        Room()=default;
        enum Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASS_ROOM,
        };
        Room(int id,const std::string &name, Type room_type){

        }
        void Serialize(Serializer *serializer)const override ;
    };

    class XmlSerializerTest:public Serializer{

    };
}



#endif //JIMP_EXERCISES_SERIALIZATION_H
