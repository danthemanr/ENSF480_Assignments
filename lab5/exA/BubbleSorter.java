/*
* File Name: BubbleSorter.java
* Assignment: Lab 4, Exercise A
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Oct 20, 2025
*/

package exA;

import java.util.ArrayList;

public class BubbleSorter<E extends Number & Comparable<E>> implements Sorter<E>{
    public void sort(ArrayList<Item<E>> list){
        int s = list.size();
        for(int j=1; j<s; j++){
            for(int i=0; i<s-j; i++){
                if (list.get(i).getItem().compareTo(list.get(i+1).getItem())>0){
                    Item<E> temp = list.get(i);
                    list.set(i,list.get(i+1));
                    list.set(i+1,temp);
                }
            }
        }
    }
}



