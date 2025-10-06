/*
* File Name: MyVector.java
* Assignment: Lab 4, Exercise A
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Oct 20, 2025
*/

package exA;

import java.util.ArrayList;
import java.util.Iterator;

public class MyVector<E extends Number & Comparable<E>> {
    private ArrayList<Item<E>> storageM;
    private Sorter<E> sorter;

    MyVector(int n){
        storageM = new ArrayList<Item<E>>(n);
    }
    MyVector(ArrayList<Item<E>> arr){
        storageM = new ArrayList<Item<E>>(arr);
    }

    public void add(Item<E> value){
        storageM.add(value);
    }
    public void setSortStrategy(Sorter<E> s){
        sorter = s;
    }
    public void performSort(){
        sorter.sort(storageM);
    }
    public void display(){
        for(Iterator<Item<E>> itr = storageM.iterator(); itr.hasNext();){
            System.out.print(itr.next().getItem().toString()+" ");
        }
        System.out.println("");
    }
}



