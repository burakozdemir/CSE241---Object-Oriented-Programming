/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg141044027;

import pkg141044027.GTUSetInt.GTUIterator;

import java.security.InvalidParameterException;
import javafx.util.*;


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author burki
 */
public class mainTest {
    
    /**
     *
     */
    public static void gtuSetTest(){
        try{
            System.out.println("---------------------------GTUSET TEST------------------------");
           System.out.println("---------------GTUSet.intersection()");
           GTUSet<Integer> a = new GTUSet<>();
           GTUSet<Integer> b = new GTUSet<>();
           System.out.println("objectA={0,1,2,3,4,5,6,7,8,9}");
           System.out.println("objectB={5,6,7,8,9}");
           a.resize(10);
           b.resize(5);
           for (Integer i = 0; i < 10; i++) {
               a.insert(i);
           }
           for (Integer i = 5; i < 10; i++) {
               b.insert(i);
           }
           GTUSet<Integer> c = new GTUSet<>();//c.resize(5);
           c = (GTUSet<Integer>) a.intersection(b);
           GTUIterator<Integer> it = c.begin();
           System.out.print("a.intersection(b):");
           while(it.hasNext()){
               System.out.print(it.next()+" ");
           }
           System.out.println();
           System.out.println("----------------GTUSet=>empty(),size(),maxSize(),erase(),insert()");
           GTUSet<Integer> obj1 = new GTUSet<>();
           obj1.resize(10);
           System.out.print("obj1.empty():");System.out.println(obj1.empty());
           System.out.print("obj1.size():");System.out.println(obj1.size());
           System.out.print("obj1.max_size():");System.out.println(obj1.max_size());
           System.out.println("obj1.insert(0..9)");System.out.print("obj1==>");
            for (int i = 0; i < 10; i++) {
               obj1.insert(i);
             }
            //obj1.insert(5);
           GTUIterator<Integer> iter = obj1.begin();
           while(iter.hasNext()){
               System.out.print(iter.next()+" ");
           }
           System.out.println();
           System.out.println("--------------------");
           System.out.print("obj1.erase(2), ");obj1.erase(2);
           System.out.print("obj1.erase(4), ");obj1.erase(4);
           System.out.println("obj1.erase(6)");obj1.erase(6);
           System.out.print("obj1=>");
           iter = obj1.begin();
           while(iter.hasNext()){
               System.out.print(iter.next()+" ");
           }
           System.out.println();
           System.out.print("obj1.empty():");System.out.println(obj1.empty());
           System.out.print("obj1.size():");System.out.println(obj1.size());
           System.out.print("obj1.max_size():");System.out.println(obj1.max_size());
           System.out.println("----------------GTUSet=>clear(),find(),count(),begin(),end() and GTUIterator methods"); 
           
           int myindex=0;
           iter=obj1.begin();
           System.out.print("begin(),next(),hasNext()==>");
           while(iter.hasNext()){
               System.out.print(iter.next()+" ");
           }
           System.out.println();
           iter=obj1.end();
           System.out.print("end(),previous(),hasPrevious()==>");
           while(iter.hasPrevious()){
               System.out.print(iter.previous()+" ");
           }
           System.out.println();
           System.out.println("-------------------");
           System.out.println("count():");
            for (int i = 0; i < 10; i++) {
                if(obj1.count(i)){
                    System.out.println("temp.count():"+obj1.count(i)+" value:"+i);
                }
                else{
                    System.out.println("temp.count():"+obj1.count(i)+" value:"+i);
                }
            }
            System.out.print("obj1.find(5):");
           iter=obj1.find(5);
           while(iter.hasPrevious()){
              System.out.print(iter.previous()+" ");
           }
           System.out.println();
           System.out.println("--------------");
           System.out.println("obj1.clear():");
           obj1.clear();
           System.out.println("obj1.insert(1)");obj1.insert(1);
           System.out.println("obj1.insert(2)");obj1.insert(2);
           System.out.println("obj1.insert(3)");obj1.insert(3);
           iter=obj1.begin();
           System.out.print("obj1==>");
           while(iter.hasNext()){
               System.out.print(iter.next()+" ");
           }
           System.out.println();
        }catch(InvalidParameterException a){
            System.out.println(a.toString());
        }
        
    }

    /**
     *
     */
    public static void gtuMapTest(){
        try{
            System.out.println("---------------------------GTUMAP TEST------------------------");
            System.out.println("---------------GTUMAP.intersection()");
            GTUMap<String,Integer> a = new GTUMap<String,Integer>();a.resize(5);//resize function ile er alınıyor
            GTUMap<String,Integer> b = new GTUMap<String,Integer>();b.resize(5);
            Pair<String,Integer> temp;
            
            temp=new Pair<>("burak",22);
            a.insert(temp);
            temp=new Pair<>("emre",21);
            a.insert(temp);
            temp=new Pair<>("tahir",20);
            a.insert(temp);
            temp=new Pair<>("omer",19);
            a.insert(temp);
            temp=new Pair<>("enis",18);
            a.insert(temp);
            
            temp=new Pair<>("burak",25);
            b.insert(temp);
            temp=new Pair<>("emre",21);
            b.insert(temp);
            temp=new Pair<>("tahir",20);
            b.insert(temp);
            temp=new Pair<>("omer",19);
            b.insert(temp);
            temp=new Pair<>("enis",16);
            b.insert(temp);
            
            GTUSet<Pair<String,Integer>> m;
            System.out.println("objectA={(burak,22),(emre,21),(tahir,20),(omer,19),(enis,18)}");
            System.out.println("objectB={(burak,25),(emre,21),(tahir,20),(omer,19),(enis,16)}");
            
            m = (GTUSet<Pair<String,Integer>>)a.intersection(b);
            GTUIterator<Pair<String,Integer>> iter=m.begin();
            for(Pair<String,Integer> x : iter){
                System.out.println(x.getKey() + x.getValue());
            }
            
            System.out.println("----------------GTUMap=>empty(),size(),maxSize(),erase(),insert()");
           GTUMap<String,Integer> obj2 = new GTUMap<>();obj2.resize(6);
           System.out.print("obj2.empty():");System.out.println(obj2.empty());
           System.out.print("obj2.size():");System.out.println(obj2.size());
           System.out.print("obj2.max_size():");System.out.println(obj2.max_size());
           
           System.out.print("obj2.insert(pair(burak,22)) ,");temp=new Pair<>("burak",22);obj2.insert(temp);
           System.out.print("obj2.insert(pair(emre,21)) ,");temp=new Pair<>("emre",21);obj2.insert(temp);
           System.out.print("obj2.insert(pair(deniz,20)) ,");temp=new Pair<>("deniz",20);obj2.insert(temp);
           System.out.print("obj2.insert(pair(lemi,19)) ,");temp=new Pair<>("lemi",19);obj2.insert(temp);
           System.out.print("obj2.insert(pair(omer,18)) ,");temp=new Pair<>("omer",18);obj2.insert(temp);
           System.out.println("obj2.insert(pair(fatih,17))");temp=new Pair<>("fatih",17);obj2.insert(temp);
           
           System.out.println("obj2:");
           iter=obj2.begin();
           int ind=0;
           for(Pair<String,Integer> x:iter){
               System.out.println(ind +" " + x.getKey()+" "+ x.getValue() );
               ind++;
           }
           System.out.println("-----------");
           System.out.print("obj2.erase(emre,21) , ");temp=new Pair<>("emre",21);obj2.erase("emre");
           System.out.print("obj2.erase(deniz,20)");temp=new Pair<>("deniz",20);obj2.erase("deniz");
           System.out.println();
           iter=obj2.begin();
           ind=0;  
           for(Pair<String,Integer> x:iter){
               System.out.println(ind +" " + x.getKey()+" "+ x.getValue() );
               ind++;
           }
           System.out.print("obj2.empty():");System.out.println(obj2.empty());
           System.out.print("obj2.size():");System.out.println(obj2.size());
           System.out.print("obj2.max_size():");System.out.println(obj2.max_size());
           System.out.println("----------------GTUMap=>clear(),find(),count(),begin(),end() and GTUIterator methods"); 
           iter=obj2.begin();
           ind=0;
           System.out.println("begin(),next(),hasNext():");
           while(iter.hasNext()){
               temp=iter.next();
               System.out.println(ind +" "+ temp.getKey() + " " + temp.getValue());
               ind++;
           }
           System.out.println();
           iter=obj2.end();
           ind=0;
           System.out.println("end(),previous(),hasPrevious():");
           while(iter.hasPrevious()){
               temp=iter.previous();
               System.out.println(ind +" "+ temp.getKey() + " " + temp.getValue());
               ind++;
           }
           System.out.println();
           System.out.println("-------------------");
           System.out.print("count(pair<lemi,19>) :");temp=new Pair<>("lemi",19);
           System.out.println(obj2.count(temp));
           System.out.print("count(pair<omer,17>):");temp=new Pair<>("omer",17);
           System.out.println(obj2.count(temp));
           
           System.out.println("obj2.find(lemi):");
           temp=new Pair<>("lemi",19);
           iter=obj2.find("lemi");
           ind=0;
           while(iter.hasNext()){
               temp=iter.next();
               System.out.println(ind +" "+ temp.getKey() + " " + temp.getValue());
               ind++;
           }
           System.out.println();
           System.out.println("--------------");
           System.out.println("obj2.clear():");
           obj2.clear();
           System.out.println("obj2.insert(pair(kasım,22))");temp=new Pair<>("kasım",22);obj2.insert(temp);
           System.out.println("obj2.insert(pair(mehmet,19))");temp=new Pair<>("mehmet",19);obj2.insert(temp);
           System.out.println("obj2.insert(pair(ahmet,20))");temp=new Pair<>("ahmet",20);obj2.insert(temp);
           iter=obj2.begin();
           System.out.println("obj2:");
           ind=0;
           while(iter.hasNext()){
               temp=iter.next();
               System.out.println(ind +" "+ temp.getKey() + " " + temp.getValue());
               ind++;
           }
           System.out.println();
           System.out.println("--------------");
           System.out.println("obj2.at(mehmet) :" + obj2.at("mehmet"));
                      
            
        }catch(InvalidParameterException a){
            System.out.println(a.toString());
        }
    
    }
    
    /**
     *
     * @param args
     */
    public static void main(String [] args){
        gtuSetTest();
        gtuMapTest();
        System.out.println("-----------------------PROGRAM IS FINISHED---------------------");
    }
}
