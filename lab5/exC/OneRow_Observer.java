/*
* File Name: OneRow_Observer.java
* Assignment: Lab 4, Exercise C
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Oct 20, 2025
*/

package exC;

import java.util.ArrayList;
import java.util.Iterator;

public class OneRow_Observer implements Observer{
    private ArrayList<Double> state;

    OneRow_Observer(Subject s){
        state = new ArrayList<Double>();
        s.registerObserver(this);
    }

    public void display(){
        for(Iterator<Double> itr = state.iterator(); itr.hasNext();){
            System.out.print(itr.next().toString()+" ");
        }
        System.out.println("");
    }
    public void update(ArrayList<Double> state){
        this.state = state;
        System.out.println("\nNotification to One-Row Observer: Data Changed:");
        display();
    }
}



