/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package pkg141044027;
import java.security.InvalidParameterException;
import java.util.Iterator;


/**
 *
 * @author burki
 */
public interface GTUSetInt<T> {
    public class GTUIterator<T> implements Iterable<T> {
    private T[] val;
    private int itIndis;
    private int curInd = 0;
    
    public GTUIterator(T[] value){
        this.val = value;
        this.itIndis = this.val.length;
    }
    
    public GTUIterator(T[] value,int indis){
        this.val = value;
        this.itIndis = this.val.length;
        this.curInd = indis;
    }
            
    public T next() {
        return val[curInd++];
    }
            
    public T previous() {
        return val[curInd--];
    }
                       
    public boolean hasNext() {
        return curInd < itIndis && val[curInd] != null;
    }
            
    public boolean hasPrevious() {
        return curInd >= 0 && val[curInd] != null;
    }

    @Override
    public Iterator<T> iterator() {
        Iterator<T> res = new Iterator<T>() {
            private int curInd = 0;
            public T next() {return val[curInd++];}
            public T previous() {return val[curInd--];}
            public boolean hasNext() {return curInd < itIndis && val[curInd] != null;}
            public boolean hasPrevious() {return curInd > itIndis && val[curInd] != null;}
        };
        return res; 
    }
    
}
    
    public boolean empty();
    public int size();
    public int max_size();
    public boolean insert(T element) throws InvalidParameterException;
    public GTUSetInt<T> intersection(GTUSetInt<T> object);
    public void erase(Object element) throws InvalidParameterException ;
    public void clear();
    public GTUIterator<T> find(Object element) throws InvalidParameterException ;
    public boolean count(Object element);
    public GTUIterator<T> begin();
    public GTUIterator<T> end();
   
}