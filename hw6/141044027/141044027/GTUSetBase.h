
#ifndef HW6_GTUSETBASE_H
#define HW6_GTUSETBASE_H
#include <memory>
#include <iostream>

using namespace std;

namespace myspace {

    template<class T>
    class GTUIterator {
    public:
        GTUIterator(){val=new T(1);};
        GTUIterator(T* x):val(x){};
        //virtual ~GTUIterator(){delete val;};

        T* getValue(){return val;}
        //shared_ptr<GTUSet<T> > shGetValue();
        GTUIterator<T> operator++(){val ++;return *this;};
        GTUIterator<T> operator++(int ){GTUIterator<T> res = *this;val++;return  res;};

        GTUIterator<T> operator--(){val --;return *this;};
        GTUIterator<T> operator--(int ){GTUIterator<T> res = *this;val--;return  res;};

        T& operator *(){return *val;};
        T* operator->(){return val;};
        bool operator==(const GTUIterator<T>& obj){return (val==obj.val);};
        bool operator!=(const GTUIterator<T>& obj){return !(val==obj.val);};

        GTUIterator<T>& operator =(const GTUIterator& other){if(&other==this)return *this;this->val = other;return
                    *this;};
    private:
        T* val;
    };

    template<class T>
    class GTUSetBase {
    public:
        GTUSetBase();
        GTUSetBase(int number);
        virtual ~GTUSetBase();
        virtual bool empty() noexcept =0;
        virtual int size() const=0;
        virtual int max_size() const=0;
        virtual bool insert(T element)=0;
        virtual void erase(T element)=0;
        virtual void clear() noexcept =0;
        virtual GTUIterator<T> find(T element)=0;
        virtual bool count(T element)=0;
        virtual GTUIterator<T> begin() const=0;
        virtual GTUIterator<T> end() const=0;
        //virtual void printSet();
        virtual shared_ptr<T> getValue() const;
        virtual shared_ptr<T> myreset(){this->value.reset();};
        //virtual void printMap() const;

        //friend ostream& operator<< (std::ostream& stream, const GTUSetBase<T>& obj);

    protected:
        int maxSize;
        int Size;
        shared_ptr<T> value;

    };


    template <class T>
    ostream & operator<<(std::ostream &stream,const GTUSetBase<T>& obj) {
        for (int i = 0; i < obj.size(); ++i) {
            stream<<obj.getValue().get()[i]<<endl;
        }
        return stream;
    }

}

#endif //HW6_GTUSETBASE_H
