//
// Created by jasimich on 09.05.18.
//

#ifndef JIMP_EXERCISES_ACADEMIASERIALIER_H
#define JIMP_EXERCISES_ACADEMIASERIALIER_H

#include <string>
#include <functional>
#include <vector>
#include <iostream>

namespace academia{

    class Serializer;

    class Serializable{
    public:
        virtual void Serialize(Serializer *serializer) const =0;
    };

    class Serializer {
    public:
        //Serializer()=default;
        Serializer(std::ostream *out):tmp{*out}{};
        virtual void IntegerField(const std::string &field_name, int value) =0;
        virtual void DoubleField(const std::string &field_name, double value) =0;
        virtual void StringField(const std::string &field_name, const std::string &value) =0;
        virtual void BooleanField(const std::string &field_name, bool value) =0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) =0;
        virtual void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) =0;
        virtual void Header(const std::string &object_name) =0;
        virtual void Footer(const std::string &object_name) =0;

        int integer_field_called = 0;
        int double_field_called = 0;
        int boolean_field_called = 0;
        int serializable_field_called = 0;
        int string_field_called = 0;
        int array_field_called = 0;
        int header_field_called = 0;
        int footer_field_called = 0;

    protected:
        std::ostream &tmp;

    };

    class Room:public Serializable {
    public:
        Room()=default;
        enum Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        Room(int id,const std::string &name, Type room_type):id_{id},name_{name},Type_{room_type}{

        }

        std::string StringEnum(Type Enum_) const{
            if(Enum_==0)
                return "COMPUTER_LAB";
            if(Enum_==1)
                return "LECTURE_HALL";
            return "CLASSROOM";
        };

        void Serialize(Serializer *serializer)const override{
            serializer->Header("room");
            serializer->IntegerField("id",id_);
            serializer->StringField("name",name_);
            serializer->StringField("type",StringEnum(Type_));
            serializer->Footer("room");

        } ;
    private:
        int id_;
        std::string name_;
        Type Type_;
    };

    class Building:public Serializable {
    public:
        Building()=default;
        enum Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        Building(int id,const std::string &name, const std::vector<std::reference_wrapper<const Serializable>> x):id_{id},name_{name},x_{x}{
        }

        std::string StringEnum(Type Enum_) const{
            if(Enum_==0)
                return "COMPUTER_LAB";
            if(Enum_==1)
                return "LECTURE_HALL";
            //if(Enum_==2)
            return "CLASSROOM";

        };

        void Serialize(Serializer *serializer)const override{
            serializer->Header("building");
            serializer->IntegerField("id",id_);
            serializer->StringField("name",name_);
            serializer->ArrayField("rooms",x_);

            serializer->Footer("building");
        } ;
    private:
        int id_;
        std::string name_;
        const std::vector<std::reference_wrapper<const Serializable>> x_;
    };

    class JsonSerializer:public Serializer{
    public:
        JsonSerializer(std::ostream *out) : Serializer(out) {

        };
        virtual void IntegerField(const std::string &field_name, int value) override {
            std::string x="\""+field_name+"\": "+std::to_string(value);
            this->tmp<<x;
            //<<'<'<<field_name<<'>';
        }
        virtual void DoubleField(const std::string &field_name, double value) override {};
        virtual void StringField(const std::string &field_name, const std::string &value) override {
            std::string x=", \""+field_name+"\": \""+value+"\"";
            this->tmp<<x;
        };
        virtual void BooleanField(const std::string &field_name, bool value) override {};
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) override {};
        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override {
            tmp<<", \""+field_name+"\": [";
            for(int i=0;i<value.size();i++){
                JsonSerializer json(&tmp);
                value[i].get().Serialize(&json);
                if(i!=value.size()-1){
                    tmp<<", ";
                }
            }
            tmp<<"]";
        };

        virtual void Header(const std::string &object_name) override {
            std::string x="{";
            this->tmp<<x;
        };
        virtual void Footer(const std::string &object_name) override {
            std::string x="}";
            this->tmp<<x;
        };

    protected:
        std::string id;
        std::ostream *tmp_;
    };

    class XmlSerializer:public Serializer{
    public:
        XmlSerializer(std::ostream *out) : Serializer(out) {

        };
        virtual void IntegerField(const std::string &field_name, int value) override {
            std::string x="<"+field_name+">"+std::to_string(value)+"<\\"+field_name+">";
            this->tmp<<x;
            //<<'<'<<field_name<<'>';
        }
        virtual void DoubleField(const std::string &field_name, double value) override {};
        virtual void StringField(const std::string &field_name, const std::string &value) override {
            std::string x="<"+field_name+">"+value+"<\\"+field_name+">";
            this->tmp<<x;
        };
        virtual void BooleanField(const std::string &field_name, bool value) override {};
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) override {};
        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override {
          tmp<<'<'+field_name+'>';
          for(int i=0;i<value.size();i++){
              XmlSerializer xml(&tmp);
              value[i].get().Serialize(&xml);
          }
            tmp<<"<\\"+field_name+'>';

        };

        virtual void Header(const std::string &object_name) override {
            std::string x="<"+object_name+">";
            this->tmp<<x;
        };
        virtual void Footer(const std::string &object_name) override {
            std::string x="<\\"+object_name+">";
            this->tmp<<x;
        };

    protected:
        std::string id;
        std::ostream *tmp_;
    };

    class BuildingRepository{
    public:
        BuildingRepository() = default;

        void Add(Building tmp){};
        void StoreAll(Serializer *serializer){};

    };
}



#endif //JIMP_EXERCISES_ACADEMIASERIALIER_H
