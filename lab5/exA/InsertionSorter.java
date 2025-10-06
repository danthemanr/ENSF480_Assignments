/*
* File Name: InsertionSorter.java
* Assignment: Lab 4, Exercise A
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Oct 20, 2025
*/

package exA;

import java.util.ArrayList;

public class InsertionSorter<E extends Number & Comparable<E>> implements Sorter<E>{
    public void sort(ArrayList<Item<E>> list){
        int s = list.size();
        for(int i=1; i<s; i++){
            Item<E> cur = list.get(i);
            for(int j=i; j>0 && list.get(j).getItem().compareTo(list.get(j-1).getItem())<0;j--){
                list.set(j,list.get(j-1));
                list.set(j-1,cur);
            }
        }
    }
}



