/*
* File Name: FiveRowsTable_Observer.java
* Assignment: Lab 4, Exercise C
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Oct 20, 2025
*/

package exC;

import java.util.ArrayList;

public class FiveRowsTable_Observer implements Observer{
    private ArrayList<Double> state;

    FiveRowsTable_Observer(Subject s){
        state = new ArrayList<Double>();
        s.registerObserver(this);
    }

    public void display(){
        int s = state.size();
        for(int i=0; i<5; i++){
            for(int j=0; i+5*j<s; j++){
                System.out.print(state.get(i+5*j).toString()+" ");
            }
            System.out.println("");
        }
        System.out.println("");
    }
    public void update(ArrayList<Double> state){
        this.state = state;
        System.out.println("\nNotification to Five-Rows Table Observer: Data Changed:");
        display();
    }
}



