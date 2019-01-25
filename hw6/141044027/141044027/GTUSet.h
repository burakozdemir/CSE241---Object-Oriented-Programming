

#ifndef HW6_GTUSET_H
#define HW6_GTUSET_H
#include <memory>
#include "GTUSetBase.h"
#include <assert.h>

using namespace std;

namespace myspace{

    template<class T>
    class GTUSet : public GTUSetBase<T>{
    public:
        ///constructors
        GTUSet();
        GTUSet(int number);
        ///bigtree
        GTUSet(const GTUSet<T> &object);
        virtual ~GTUSet();
        GTUSet<T> &operator = (const GTUSet<T> &object);
        ///settters and getters
        virtual int getSize(){return this->Size;}
        virtual int setSize(int value){this->Size=value;}
        virtual int getMaxSize(){ return this->maxSize;}
        virtual int setMaxSize(int value){ this->maxSize=value;}
        ///member functions
        virtual bool empty()noexcept ;
        virtual int size() const;
        virtual int max_size() const;
        virtual bool insert(T element);
        virtual void erase(T element);
        virtual void clear() noexcept ;
        virtual GTUIterator<T> find(T element);
        virtual bool count(T element);
        virtual GTUIterator<T> begin() const;
        virtual GTUIterator<T> end() const;
        ///my functions
        T& operator [](int index);
        virtual void maxSizeKontroller();
        //virtual void printSet();

    };


}

#endif //HW6_GTUSET_H
