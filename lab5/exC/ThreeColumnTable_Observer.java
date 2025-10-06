/*
* File Name: ThreeColumnTable_Observer.java
* Assignment: Lab 4, Exercise C
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Oct 20, 2025
*/

package exC;

import java.util.ArrayList;
import java.util.Iterator;

public class ThreeColumnTable_Observer implements Observer{
    private ArrayList<Double> state;

    ThreeColumnTable_Observer(Subject s){
        state = new ArrayList<Double>();
        s.registerObserver(this);
    }

    public void display(){
        for(Iterator<Double> itr = state.iterator(); itr.hasNext();){
            for(int i=0; i<2 && itr.hasNext(); i++){
                System.out.print(itr.next().toString()+" ");
            }
            System.out.println((itr.hasNext()) ? itr.next() : "");
        }
        System.out.println("");
    }
    public void update(ArrayList<Double> state){
        this.state = state;
        System.out.println("\nNotification to Three-Column Table Observer: Data Changed:");
        display();
    }
}



