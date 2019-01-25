

#include "GTUSet.h"


namespace myspace{

    template <class T>
    GTUSet<T>::GTUSet():GTUSetBase<T>(){
    }
    template <class T>
    GTUSet<T>::GTUSet(int number):GTUSetBase<T>(){

    }
    template<class T>
    GTUSet<T>::GTUSet(const GTUSet<T> &object):GTUSetBase<T>(){

    }
    template<class T>
    GTUSet<T>::~GTUSet() {
        this->value.reset();
    }
    template<class T>
    GTUSet<T> &GTUSet<T>::operator = (const GTUSet<T> &object){

    }

    template<class T>
    bool GTUSet<T>::empty()noexcept {
        return (this->Size==0);
    }

    template<class T>
    int GTUSet<T>::size() const{
        return this->Size;
    }

    template<class T>
    int GTUSet<T>::max_size() const{
        return this->maxSize;
    }

    template<class T>
    bool GTUSet<T>::insert(T element) {
        shared_ptr<T> temp(new T[this->Size+1],default_delete<T[]>());
        bool flag=false;
        for (int j = 0; j < this->size(); ++j) {
            if(this->value.get()[j]==element){
                flag=true;
            }
        }
        if(flag==false && this->Size!=0){
            for (int i = 0; i < this->Size; ++i) {
                temp.get()[i]=this->value.get()[i];
            }
            temp.get()[this->Size]=element;
            this->Size+=1;
            maxSizeKontroller();
            this->value=temp;
        }
        else if(flag==false && this->Size==0){
            temp.get()[0]=element;
            this->Size+=1;
            maxSizeKontroller();
            this->value=temp;
        }
        else
            throw std::invalid_argument("Element is already have been in set");
    }

    template<class T>
    void GTUSet<T>::erase(T element) {
        if(!count(element))
            throw invalid_argument("There is no element for erasing");
        int index ;
        for (index = 0; index < this->Size; ++index) {
            if(this->value.get()[index]==element){
                this->Size-=1;
                break;
            }
        }
        shared_ptr<T> temp(new T[this->Size],default_delete<T[]>());
        int tempindex=0;
        for (int i = 0; i < this->Size+1; ++i) {
            if(i==index){}
            else {
                temp.get()[tempindex] = this->value.get()[i];
                tempindex++;
            }
        }
        this->value=temp;
        /*
        shared_ptr<Node<T>> temp=value;
        shared_ptr<Node<T>> before=nullptr,after=nullptr;
        while(temp->getLink()!=nullptr){
            after=temp->getLink();
            if(temp->getData()==element && before==nullptr){
                value->setLink(value->getLink());
                Size--;
            }

            before=temp;
            temp=value->getLink();
        }
        cerr<<"Wrong element to erase"<<endl;
         */
    }

    template<class T>
    void GTUSet<T>::clear() noexcept {
        this->value.reset(new T());
        this->Size=0;
    }

    template<class T>
    GTUIterator<T> GTUSet<T>::find(T element) {
        for (int i = 0; i < this->Size; ++i) {
            if(this->value.get()[i]==element)
                return GTUIterator<T>(this->value.get()+i);
        }
        throw invalid_argument("there is no element for find function \n");
    }

    template<class T>
    bool GTUSet<T>::count(T element) {
        for (int i = 0; i < this->Size; ++i) {
            if(this->value.get()[i]==element)
                return true;
        }
        return false;
    }

    template<class T>
    GTUIterator<T> GTUSet<T>::begin() const{
        return GTUIterator<T>(this->value.get());
    }

    template<class T>
    GTUIterator<T> GTUSet<T>::end() const{
        return GTUIterator<T>(this->value.get() + this->Size);
    }

    template<class T>
    void GTUSet<T>::maxSizeKontroller() {
        if(this->Size>=this->maxSize){
            this->maxSize=this->Size;
        }
    }


    template <class T>
    T & GTUSet<T>::operator[](int index) {
        assert(index<this->Size);
        return this->value.get()[index];
    }


}