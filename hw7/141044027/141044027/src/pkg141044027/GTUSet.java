/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg141044027;
import java.lang.reflect.Array;
import java.io.*;
import java.security.InvalidParameterException;
import java.lang.Class;
import java.util.Arrays;

/**
 *
 * @author burki
 */
public class GTUSet<T> implements GTUSetInt<T>{
    protected T[] value;
    protected Integer Size;
    protected Integer maxSize;
    protected Integer currentSize;
    
    public GTUSet(){
        Size=0;maxSize=100;currentSize=0;
        value = (T[]) new Object[0];
    }   
    public T getVal(int index){
        return this.value[index];
    }
    public T[] getValue(){
        return this.value;
    }
    public void setValue(T[] elem){
        value=elem;
    }
    public int curSize(){return this.currentSize;}
    public static void main(String[] args) {
      
    }
    
    public void resize(int value) throws InvalidParameterException{
        if(value<0)
            throw new InvalidParameterException("Invalid value for resize() method.");
        else
            this.Size=value;
        maxSizeKontrol();
    }
    @Override
    public boolean empty() {
        return (this.currentSize==0);
    }
    @Override
    public int size() {
        return this.currentSize;
    }
    @Override
    public int max_size() {
        return this.maxSize;
    }
    @Override
    public boolean insert(T element) throws InvalidParameterException {
        if(this.Size-this.currentSize<1){
            throw new InvalidParameterException("There is not enough place.PLease use resize() method.");
        }
        boolean flag=false;
        T[] temp = (T[]) new Object[this.currentSize+1];
        for (int i = 0; i < this.currentSize; i++) {
            if(this.value[i].equals(element)){
                flag=true;
            }
        }
        if(flag==false && this.currentSize!=0){
            for (int i = 0; i < this.currentSize; ++i) {
                temp[i]=this.value[i];
            }
            temp[this.currentSize]=element;
            this.currentSize+=1;
            maxSizeKontrol();
            this.value=temp;
        }
        else if(flag==false && this.currentSize==0){
            temp[0]=element;
            this.currentSize+=1;
            maxSizeKontrol();
            this.value=temp;
        }
        else
            throw new InvalidParameterException("Element is already have been in set");
        return true;
    }
    @Override
    public GTUSetInt<T> intersection(GTUSetInt<T> object) {
        GTUSet<T> result = new GTUSet<T>();
        result.resize(100);
        GTUSet<T> result2 = (GTUSet<T>) object;
        for (int i = 0; i < this.currentSize; i++) {
            for (int j = 0; j < result2.curSize(); j++) {
                if(this.value[i].equals(result2.getVal(j))){
                    result.insert(this.value[i]);
                
                }
            }
        }
        return result;
    }
    @Override
    public void erase(Object element) throws InvalidParameterException{
        if(!count(element)){
            throw new InvalidParameterException("There is no element for erasing");
        }
        int index ;
        for (index = 0; index < this.currentSize; ++index) {
            if(this.value[index].equals(element)){
                this.currentSize-=1;
                break;
            }
        }
        T[] temp = (T[]) new Object[this.currentSize];
        int tempindex=0;
        for (int i = 0; i < this.currentSize+1; ++i) {
            if(i==index){}
            else {
                temp[tempindex] = this.value[i];
                tempindex++;
            }
        }
        this.value=temp;
    }
    @Override
    public void clear() {
        this.currentSize=0;
        this.value = (T[]) new Object[this.currentSize];
    }
    @Override
    public GTUIterator<T> find(Object element) throws InvalidParameterException{
        int index = 0; 
        for (int i = index ; i < this.currentSize; ++i) {
            if(this.value[i].equals(element)){
                index=i;
            }    
        }    
        if(index!=0)
            return new GTUIterator<T>(this.value,index);
        else
            throw new InvalidParameterException("there is no element for find function ");
    }
    @Override
    public boolean count(Object element) {
        for (int i = 0; i < this.currentSize; ++i) {
            if(this.value[i].equals(element))
                return true;
        }
        return false;
    }
    @Override
    public GTUIterator<T> begin() {
        return new GTUIterator<T>(this.value);
    }
    @Override
    public GTUIterator<T> end() {
        return new GTUIterator<T>(this.value,this.currentSize-1);
    } 
    public void maxSizeKontrol(){
        if(this.Size>=this.maxSize){
            this.maxSize=this.Size;
        }
    }   
    @Override
    public String toString(){
        StringBuilder result=new StringBuilder();
        return null;
    }
}