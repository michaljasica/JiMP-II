//
// Created by malikmontana on 18.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#import <string>
#include <vector>
#include <bits/unique_ptr.h>

namespace utility{
    class IterableIterator {
    public:
        IterableIterator()= default;
        virtual ~IterableIterator()= default;
        virtual IterableIterator &Next() =0;
        virtual std::pair<int,std::string> Dereference() const=0;

        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const =0;

        std::pair<int, std::string> getto() const;

        friend class ZipperIterator;
        friend class IterableIteratorWrapper;
    protected:
        std::pair<int, std::string> item;

        std::vector<int>::const_iterator int_iterator;
        std::vector<std::string>::const_iterator string_iterator;

    };



    class ZipperIterator:public IterableIterator{
    public:
        ~ZipperIterator() override;
        ZipperIterator();
        ZipperIterator(std::vector<int>::const_iterator a ,std::vector<std::string>::const_iterator b);
        explicit ZipperIterator(std::vector<int>::const_iterator left_begin,
                                std::vector<std::string>::const_iterator right_begin,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);


        virtual std::pair<int,std::string> Dereference() const override ;

        virtual IterableIterator &Next() override ;

        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override;

        std::vector<int>::const_iterator getint();
        std::vector<std::string>::const_iterator getstring();

        friend class IterableIteratorWrapper;

    protected:
        std::vector<int>::const_iterator int_iterator_end;
        std::vector<std::string>::const_iterator string_iterator_end;
    };

    class IterableIteratorWrapper:public ZipperIterator{
    public:
        IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other);

        std::pair<int, std::string> operator*();
        IterableIteratorWrapper &operator++();


    protected:
        std::unique_ptr<IterableIterator> wsk_iter;
    };


    class Iterable{
    public:
        virtual std::unique_ptr<IterableIterator> ConstBegin()const=0 ;
        virtual std::unique_ptr<IterableIterator> ConstEnd() const=0 ;
        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper end() const;


    protected:
        std::pair<std::vector<int>, std::vector<std::string>> pairs;
    };

    class Zipper :public Iterable{
    public:
        Zipper(std::vector<int> v_int, std::vector<std::string> v_string);
        virtual std::unique_ptr<IterableIterator> ConstBegin()const override ;
        virtual std::unique_ptr<IterableIterator> ConstEnd() const override;

    };

    class Product :public Iterable{
    public:
        Product(std::vector<int> v_int, std::vector<std::string> v_string);
        virtual std::unique_ptr<IterableIterator> ConstBegin()const override ;
        virtual std::unique_ptr<IterableIterator> ConstEnd() const override;

    };

    class Enumerate :public Iterable{
    public:
        Enumerate(std::vector<std::string> v_string);
        virtual std::unique_ptr<IterableIterator> ConstBegin()const override ;
        virtual std::unique_ptr<IterableIterator> ConstEnd() const override;

    };

    class ProductIterator :public IterableIterator{
    };

    class EnumerateIterator :public IterableIterator{
    };

}



#endif //JIMP_EXERCISES_ITERABLE_H
