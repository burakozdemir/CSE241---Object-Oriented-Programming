
#include "GTUSetBase.h"

namespace myspace{

    template<class T>
    GTUSetBase<T>::GTUSetBase():maxSize(0),Size(0){
        shared_ptr<T> a(new T[1],default_delete<T[]>());
        this->value= a;
    }
    template <class T>
    GTUSetBase<T>::~GTUSetBase() {
        this->value.reset();
    }
    template <class T>
    shared_ptr<T> GTUSetBase<T>::getValue() const{
        return value;
    }
    template <class T>
    GTUSetBase<T>::GTUSetBase(int number) {
    }



}

