/*
* File Name: SelectionSorter.java
* Assignment: Lab 4, Exercise B
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Oct 20, 2025
*/

package exA;

import java.util.ArrayList;

public class SelectionSorter<E extends Number & Comparable<E>> implements Sorter<E>{
    public void sort(ArrayList<Item<E>> list){
        int s = list.size();
        for(int j=0; j<s; j++){
            int min = j;
            for(int i=j+1; i<s; i++){
                if (list.get(i).getItem().compareTo(list.get(min).getItem())<0){
                    min = i;
                }
            }
            Item<E> temp = list.get(min);
            list.set(min,list.get(j));
            list.set(j,temp);
        }
    }
}



