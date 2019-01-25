
#ifndef HW6_GTUMAP_H
#define HW6_GTUMAP_H
#include "GTUSet.h"

namespace myspace{
    template<class K,class V>
    class GTUMap : public GTUSet<std::pair<K,V>>{
    public:
        GTUMap();
        ~GTUMap(){}//this->value.reset();};
        ///member functions
        virtual bool empty()noexcept ;
        virtual int size() const;
        virtual int max_size() const;
        virtual bool insert(pair<K,V> element);
        virtual void erase(pair<K,V> element);
        virtual void clear()noexcept ;
        virtual GTUIterator<pair<K,V>> find(pair<K,V> element);
        virtual bool count(pair<K,V> element);
        virtual GTUIterator<pair<K,V>> begin() const;
        virtual GTUIterator<pair<K,V>> end() const;
        ///my functions
        V& operator[] (const K& k);
        void maxSizeKontroller();
        //void printSet();

    };

}



#endif //HW6_GTUMAP_H
