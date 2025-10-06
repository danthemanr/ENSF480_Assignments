/*
* File Name: Sorter.java
* Assignment: Lab 4, Exercise A
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Oct 20, 2025
*/

package exA;

import java.util.ArrayList;

public interface Sorter<E extends Number & Comparable<E>> {
    abstract void sort(ArrayList<Item<E>> list);
}



