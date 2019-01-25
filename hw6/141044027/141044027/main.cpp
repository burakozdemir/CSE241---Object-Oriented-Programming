/**
 * Homework6_Burak_Özdemir_141044027
 ****************************************
 * Created on 03.11.2017 by Burak_Özdemir
 ****************************************
 *              ==Notes==
 *
 */
#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <assert.h>
#include "GTUSet.h"
#include "GTUSet.cpp"
#include "GTUMap.h"
#include "GTUMap.cpp"
#include <utility>
#include "GTUSetBase.h"
#include "GTUSetBase.cpp"
#include <typeinfo>
#include <bits/shared_ptr_base.h>

using namespace std;
using namespace myspace;

int testGtuSet();
int testGtuMap();

template <class T>
std::shared_ptr<GTUSetBase<T> > setIntersection(const GTUSetBase<T>& a, const GTUSetBase<T>& b);
int main()
{
    try{
        ///intersection gtuset
        cout<<"==================Intersection GTUSET TEST=================="<<endl;
        GTUSet<int> obj;
        obj.insert(1);
        obj.insert(2);
        obj.insert(3);
        obj.insert(4);

        GTUSet<int> obj2;
        obj2.insert(1);
        obj2.insert(2);
        obj2.insert(3);
        obj2.insert(5);

        shared_ptr<GTUSetBase<int>> a=setIntersection(obj,obj2);
        cout<<*a.get()<<endl;
        /////////////////////////////////////////////////////////

        ///intersection gtmap
        cout<<"==================Intersection GTUMAP TEST=================="<<endl;
        cout<<endl;
        GTUMap<string,int> objMap;
        std::pair <std::string,int> temp;
        temp=make_pair("burak",22);
        objMap.insert(temp);
        temp=make_pair("emre",21);
        objMap.insert(temp);
        temp=make_pair("tahir",20);
        objMap.insert(temp);
        temp=make_pair("lemi",19);
        objMap.insert(temp);

        GTUMap<string,int> objMap2;
        temp=make_pair("burak",22);
        objMap2.insert(temp);
        temp=make_pair("emre",21);
        objMap2.insert(temp);
        temp=make_pair("tahir",20);
        objMap2.insert(temp);
        temp=make_pair("omer",19);
        objMap2.insert(temp);

        shared_ptr<GTUSetBase<pair<string,int>>> b=setIntersection(objMap,objMap2);
        for (GTUIterator<pair<string,int>> it = b.get()->begin(); it!=b.get()->end(); ++it) {
            cout<<"pair_first:"<<it.getValue()->first<<","<<" pair_second:"<<it.getValue()->second <<endl;
        }
    }catch (invalid_argument a){
        cout<<a.what()<<endl;
    }

    cout<<endl;
    ///gtuset test
    testGtuSet();
    ///gtumap test
    testGtuMap();

    cout<<"-----------------------PROGRAM IS FINISHED-----------------------"<<endl;
    return 0;
}
template <class T>
std::shared_ptr<GTUSetBase<T> > setIntersection(const GTUSetBase<T>& a, const GTUSetBase<T>& b){
    shared_ptr<GTUSet<T>> result(new GTUSet<T>);
    int index=0;
    for (GTUIterator<T> i =a.begin(); i!=a.end(); ++i) {
        for (GTUIterator<T> j = b.begin(); j!= b.end(); ++j) {
            if(*i==*j){
                result.get()->insert(*i);
                index++;
            }
        }
    }

    return result;
}
int testGtuMap(){
    ///gtumap denemesi
    cout<<"=================GTUMAP Fonksiyonlarin Denenmesi=================="<<endl;
    try {

        GTUMap<string,int> object;cout<<"temp empty():"<<object.empty()<<endl;
        cout<<"temp size():"<<object.size()<<endl;
        cout<<"temp maxsize():"<<object.max_size()<<endl;

        cout<<"-----------"<<endl;
        std::pair <std::string,int> temp;
        cout<<"obj.insert(lemi,22),";cout<<"obj.insert(burak,21),";cout<<"obj.insert(tahir,20),"<<endl;
        cout<<"obj.insert(omer,19),";cout<<"obj.insert(yagiz,18),";cout<<"obj.insert(emre,17),"<<endl;
        temp=make_pair("lemi",22);
        object.insert(temp);
        temp=make_pair("burak",21);
        object.insert(temp);
        temp=make_pair("tahir",20);
        object.insert(temp);
        temp=make_pair("omer",19);
        object.insert(temp);
        temp=make_pair("yagiz",18);
        object.insert(temp);
        temp=make_pair("emre",17);
        object.insert(temp);
        //obj.insert(temp);
        cout<<"print....."<<endl;
        cout<<"temp empty():"<<object.empty()<<endl;
        cout<<"temp size():"<<object.size()<<endl;
        cout<<"temp maxsize():"<<object.max_size()<<endl;

        cout<<"-----------"<<endl;
        cout<<"obj.erase(pair<emre,17>)"<<endl;temp=make_pair("emre",17);object.erase(temp);
        cout<<"obj.erase(pair<burak,21>)"<<endl;temp=make_pair("burak",21);object.erase(temp);
        cout<<"print....."<<endl;
        for (GTUIterator<pair<string,int>> j=object.begin() ; j!=object.end() ; ++j) {
            cout<<"first:"<<j->first<<","<<"second:"<<j->second<<endl;
        }
        cout<<"temp empty():"<<object.empty()<<endl;
        cout<<"temp size():"<<object.size()<<endl;
        cout<<"temp maxsize():"<<object.max_size()<<endl;

        cout<<"-----------"<<endl;
        cout<<"find(),count(),begin(),end(),operator[] fonskyionlarının testi :"<<endl;
        cout<<"obj[lemi]=1"<<endl;object["lemi"]=1;
        cout<<"obj[tahir]=1"<<endl;object["tahir"]=1;
        cout<<"obj.find(pair<omer,19>)"<<endl;temp=make_pair("omer",19);GTUIterator<pair<string,int>> it=object.find(temp);
        cout<<"count1=obj.count(lemi,1)"<<endl;temp=make_pair("lemi",1);int count1=object.count(temp);
        cout<<"count2=obj.count(tahir,2)"<<endl;temp=make_pair("tahir",2);int count2=object.count(temp);
        cout<<"print....."<<endl;
        cout<<"count1:"<<count1<<endl;
        cout<<"count2:"<<count2<<endl;
        cout<<"it-- : ";it--;cout<<"first:"<<it->first<<" second:"<<it->second<<endl;
        cout<<"it-- : ";it--;cout<<"first:"<<it->first<<" second:"<<it->second<<endl;


        cout<<"-----------"<<endl;
        cout<<"PRİNT......"<<endl;
        for (GTUIterator<pair<string,int>> j=object.begin() ; j!=object.end() ; ++j) {
            cout<<"first:"<<j->first<<" second:"<<j->second<<endl;
        }

        cout<<"-----------"<<endl;
        cout<<"obj.clear()"<<endl;object.clear();
        cout<<"-----------"<<endl;

        cout<<"object.insert(pair<osman,20>)";temp=make_pair("osman",20);
        object.insert(temp);
        cout<<"object.insert(pair<ferhat,19>)";temp=make_pair("ferhat",19);
        object.insert(temp);
        cout<<"object.insert(pair<kasim,21>)";temp=make_pair("kasim",21);
        object.insert(temp);cout<<endl;
        cout<<"print....."<<endl;

        for (GTUIterator<pair<string,int>> j=object.begin() ; j!=object.end() ; ++j) {
            cout<<"first:"<<j->first<<" second:"<<j->second<<endl;
        }
    }catch (std::invalid_argument a){
        cout<<a.what()<<endl;
    }
};
int testGtuSet(){
    ///gtuset denemesi
    cout<<"=================GTUSET Fonksiyonlarin Denenmesi=================="<<endl;
    try {
        GTUSet<int> temp;cout<<"temp empty():"<<temp.empty()<<endl;
        cout<<"temp size():"<<temp.size()<<endl;
        cout<<"temp maxsize():"<<temp.max_size()<<endl;

        cout<<"-----------"<<endl;
        cout<<"temp insert():0 dan 9'a";
        for (int i = 0; i < 10; ++i) {
            temp.insert(i);
        }
        //temp.insert(5);

        cout<<endl;
        cout<<"temp erase(2):"<<endl;temp.erase(2);
        cout<<"temp erase(4):"<<endl;temp.erase(4);
        cout<<"temp erase(6):"<<endl;temp.erase(6);
        cout<<"temp ==>";
        for (GTUIterator<int> l = temp.begin(); l != temp.end(); ++l) {
            cout<<*l<<" ";
        }
        cout<<endl;
        cout<<"-----------"<<endl;

        cout<<"temp empty():"<<temp.empty()<<endl;
        cout<<"temp size():"<<temp.size()<<endl;
        cout<<"temp maxsize():"<<temp.max_size()<<endl;
        cout<<"-----------"<<endl;

        GTUIterator<int> it=temp.find(5);cout<<"it=temp.find(5) :";cout<<*it<<endl;
        cout<<"it-- : ";it--;cout<<*it<<endl;
        cout<<"it-- : ";it--;cout<<*it<<endl;

        cout<<"-----------"<<endl;
        cout<<"begin(),end(),count() function test:"<<endl;
        int myindex=0;
        for (GTUIterator<int> j = temp.begin(); j != temp.end() ; ++j) {
            cout<<"İTERATOR:"<<*j<<endl;
            if(temp.count(myindex)){
                cout<<"temp.count():"<< temp.count(myindex)<<" value:" << myindex<<" true"<<endl;
                myindex++;
            }
            else{
                cout<<"temp.count():"<< temp.count(myindex)<<" value:" << myindex<<" false"<<endl;
                myindex++;}
        }
        cout<<endl;
        cout<<"-----------"<<endl;
        cout<<"temp.clear()"<<endl;temp.clear();
        cout<<"-----------"<<endl;

        cout<<"object.insert(21) ";temp.insert(21);
        cout<<"object.insert(22) ";temp.insert(22);
        cout<<"object.insert(23)";temp.insert(23);cout<<endl;
        cout<<"print....."<<endl;

        for (GTUIterator<int> k = temp.begin(); k != temp.end(); ++k) {
            cout<<*k<<endl;
        }

    }
    catch (invalid_argument a){
        cout<<a.what()<<endl;
    }
}

