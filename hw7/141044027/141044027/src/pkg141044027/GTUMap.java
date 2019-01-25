/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg141044027;
import java.security.InvalidParameterException;
import javafx.util.Pair;
import pkg141044027.GTUSet;

/**
 *
 * @author burki
 * @param <K>
 * @param <V>
 */
public class GTUMap<K,V> extends GTUSet<javafx.util.Pair<K,V>> {
    
    public GTUMap(){
     
    }

    
    public static void main(String[]args){
    }
    //bu fonksiyon referance dondurcek
    public V at(K k) throws InvalidParameterException {
        boolean flag=false;
        for (int i = 0; i < this.currentSize; i++) {
            if(this.getVal(i).getKey().equals(k)){
                flag=true;
            }
        }
        if(flag==true){
            for (int i = 0; i < this.currentSize; i++) {
                if(this.getVal(i).getKey().equals(k)){
                    return this.getVal(i).getValue();
                }
            }
        }
        else
            throw new InvalidParameterException("there is no key for at() function.");
    return this.value[0].getValue();
    }
    
    public final void erase(Object element) throws InvalidParameterException{
        boolean flag=false;
        for (int i = 0; i < this.currentSize; i++) {
            if(this.getVal(i).getKey().equals(element)){
                flag=true;
            }
        }
        if(flag==false) throw new InvalidParameterException("There is no element for erasing");
        
        int index ;
        for (index = 0; index < this.currentSize; ++index) {
            if(this.getVal(index).getKey().equals(element)){
                this.currentSize-=1;
                break;
            }
        }
        Pair<K,V>[] temp = (Pair[]) new Pair[this.currentSize];
        int tempindex=0;
        for (int i = 0; i < this.currentSize+1; ++i) {
            if(i==index){}
            else {
                temp[tempindex] = this.getVal(i);
                
                tempindex++;
            }
        }
        this.value=temp;
        
        
    }
    
    public GTUIterator<javafx.util.Pair<K,V>> find(Object element) throws InvalidParameterException{
        int index = 0; 
        for (int i = index ; i < this.currentSize; ++i) {
            if(this.getVal(i).getKey().equals(element)){
                index=i;
            }    
        }    
        if(index!=0)
            return new GTUIterator<javafx.util.Pair<K,V>>(this.value,index);
        else
            throw new InvalidParameterException("there is no element for find function ");
    }
    
    
}
