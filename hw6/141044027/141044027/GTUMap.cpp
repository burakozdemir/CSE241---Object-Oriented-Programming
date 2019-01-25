
#include "GTUMap.h"

namespace myspace{

    template<class K,class V>
    GTUMap<K,V>::GTUMap():GTUSet<pair<K,V>>(){
    }

    template <class K,class V>
    bool GTUMap<K,V>::empty() noexcept {
        return GTUSet<std::pair<K,V>>::empty();
    }

    template <class K,class V>
    int GTUMap<K,V>::size() const{
        return GTUSet<std::pair<K,V>>::size();
    }

    template <class K,class V>
    int GTUMap<K,V>::max_size() const{
        return GTUSet<std::pair<K,V>>::max_size();
    }

    template <class K,class V>
    bool GTUMap<K,V>::insert(pair<K, V> element) {
        return GTUSet<std::pair<K,V>>::insert(element);
    }

    template <class K,class V>
    void GTUMap<K,V>::erase(pair<K, V> element) {
        GTUSet<std::pair<K,V>>::erase(element);
    }

    template <class K,class V>
    void GTUMap<K,V>::clear() noexcept {
        this->value.reset(new pair<K,V>());
        this->Size=0;
    }

    template <class K,class V>
    GTUIterator<pair<K, V>> GTUMap<K,V>::find(pair<K, V> element) {
        return GTUSet<std::pair<K,V>>::find(element);
    }

    template <class K,class V>
    bool GTUMap<K,V>::count(pair<K, V> element) {
        return GTUSet<std::pair<K,V>>::count(element);
    }

    template <class K,class V>
    GTUIterator<pair<K, V>> GTUMap<K,V>::begin() const{
        return GTUSet<std::pair<K,V>>::begin();
    }

    template <class K,class V>
    GTUIterator<pair<K, V>> GTUMap<K,V>::end() const{
        return GTUSet<std::pair<K,V>>::end();
    }

    template <class K,class V>
    void GTUMap<K,V>::maxSizeKontroller() {
        GTUSet<std::pair<K,V>>::maxSizeKontroller();
    }

    template <class K,class V>
    V &GTUMap<K,V>::operator[](const K &k) {
        bool flag=false;
        for (int j = 0; j < this->size(); ++j) {
            if(this->value.get()[j].first==k){
                flag=true;
            }
        }
        if(flag==true){
            for (int i = 0; i < this->size(); ++i) {
                if(this->value.get()[i].first==k){
                    return this->value.get()[i].second;
                }
            }
        }
        else
            throw invalid_argument("there is no key for []operator \n");
    }


}