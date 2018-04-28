//
// Created by malikmontana on 18.04.18.
//

#include "Iterable.h"

utility::ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left_begin,
                                        std::vector<std::string>::const_iterator right_begin,
                                        std::vector<int>::const_iterator left_end,
                                        std::vector<std::string>::const_iterator right_end) {
    int_iterator=left_begin;
    string_iterator=right_begin;

    int_iterator_end=left_end;
    string_iterator_end=right_end;

}

std::pair<int, std::string> utility::ZipperIterator::Dereference() const {
    return std::make_pair(*int_iterator,*string_iterator);
}

utility::IterableIterator &utility::ZipperIterator::Next() {
    this->int_iterator=this->int_iterator+1;
    this->string_iterator=this->string_iterator+1;
    return *this;
}

utility::ZipperIterator::~ZipperIterator() {

}

utility::ZipperIterator::ZipperIterator() {

}

bool utility::ZipperIterator::NotEquals(const std::unique_ptr<utility::IterableIterator> &other) const {
    //if (this->getto().first==other->getto().first && this->getto().second==other->getto().second)
    if(int_iterator==other->int_iterator && string_iterator==other->string_iterator)
        return false;
    return true;
}

std::vector<int>::const_iterator utility::ZipperIterator::getint() {
    return int_iterator;
}

std::vector<std::string>::const_iterator utility::ZipperIterator::getstring() {
    return string_iterator;
}

utility::ZipperIterator::ZipperIterator(std::vector<int>::const_iterator a,
                                        std::vector<std::string>::const_iterator b) {
    int_iterator=a;
    string_iterator=b;
}


std::pair<int, std::string> utility::IterableIterator::getto() const {
    return item;
}


utility::IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<utility::IterableIterator> iterator) {
    //wsk_iter->item=iterator->item;
    //wsk_iter->string_iterator=iterator->string_iterator;
    //wsk_iter->int_iterator=iterator->int_iterator;
    wsk_iter=std::move(iterator);
}

bool utility::IterableIteratorWrapper::operator!=(const utility::IterableIteratorWrapper &other) {
    if(wsk_iter->NotEquals(other.wsk_iter))
        return true;
    return false;
}

std::pair<int, std::string> utility::IterableIteratorWrapper::operator*() {
    return wsk_iter->Dereference();
}

utility::IterableIteratorWrapper &utility::IterableIteratorWrapper::operator++() {
    wsk_iter->Next();
    return *this;
}


utility::IterableIteratorWrapper utility::Iterable::cbegin() const {
    return ConstBegin();
}

utility::IterableIteratorWrapper utility::Iterable::cend() const {
    return ConstEnd();
}

utility::IterableIteratorWrapper utility::Iterable::begin() const {
    return cbegin();
}

utility::IterableIteratorWrapper utility::Iterable::end() const {
    return cend();
}

std::unique_ptr<utility::IterableIterator> utility::Zipper::ConstBegin() const {
    return std::make_unique<ZipperIterator>(pairs.first.begin(),pairs.second.begin());
}

std::unique_ptr<utility::IterableIterator> utility::Zipper::ConstEnd() const {
    return std::make_unique<ZipperIterator>(pairs.first.end(),pairs.second.end());
}

utility::Zipper::Zipper(std::vector<int> v_int, std::vector<std::string> v_string) {
    pairs.first.clear();
    pairs.second.clear();

    pairs.first= std::move(v_int);
    pairs.second= std::move(v_string);

    int i =pairs.second.size();
    for(; i < pairs.first.size();i++)
        pairs.second.push_back(pairs.second.back());

    i =pairs.first.size();
    for(; i < pairs.second.size();i++)
        pairs.first.push_back(pairs.first.back());

}

std::unique_ptr<utility::IterableIterator> utility::Product::ConstBegin() const {
    return std::make_unique<ZipperIterator>(pairs.first.begin(),pairs.second.begin());
}

std::unique_ptr<utility::IterableIterator> utility::Product::ConstEnd() const {
    return std::make_unique<ZipperIterator>(pairs.first.end(),pairs.second.end());
}

utility::Product::Product(std::vector<int> v_int, std::vector<std::string> v_string) {
    pairs.first.clear();
    pairs.second.clear();
    for(int j=0;j<v_int.size();j++){
        for(int i=0;i<v_string.size();i++){
            pairs.first.emplace_back(v_int[j]);
        }
        for(int i=0;i<v_string.size();i++){
            pairs.second.emplace_back(v_string[i]);
        }
    }
}

std::unique_ptr<utility::IterableIterator> utility::Enumerate::ConstBegin() const {
    return std::make_unique<ZipperIterator>(pairs.first.begin(),pairs.second.begin());
}

std::unique_ptr<utility::IterableIterator> utility::Enumerate::ConstEnd() const {
    return std::make_unique<ZipperIterator>(pairs.first.end(),pairs.second.end());
}

utility::Enumerate::Enumerate(std::vector<std::string> v_string) {
    pairs.first.clear();
    for(int i=1;i<=v_string.size();i++)
        pairs.first.emplace_back(i);
    pairs.second= std::move(v_string);

}
