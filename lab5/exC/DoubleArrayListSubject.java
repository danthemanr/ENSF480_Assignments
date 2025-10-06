/*
* File Name: DoubleArrayListSubject.java
* Assignment: Lab 4, Exercise C
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Oct 20, 2025
*/

package exC;

import java.util.ArrayList;
import java.util.Iterator;

public class DoubleArrayListSubject implements Subject{
    private ArrayList<Observer> observers;
    private ArrayList<Double> data;

    DoubleArrayListSubject(){
        observers = new ArrayList<Observer>();
        data = new ArrayList<Double>();
    }
    
    public void addData(Double datum){
        data.add(datum);
        notifyAllObservers();
    }
    public void setData(Double datum, int i){
        data.set(i, datum);
        notifyAllObservers();
    }
    public void populate(ArrayList<Double> data){
        this.data = data;
        notifyAllObservers();
    }
    public void populate(double[] data){
        for (double x : data){
            this.data.add(x);
        }
        notifyAllObservers();
    }

    public void registerObserver(Observer o){
        observers.add(o);
        o.update(data);
    }
    public void remove(Observer o){
        observers.remove(o);
    }
    public void notifyAllObservers(){
        observers.forEach(o -> o.update(data));
    }

    public void display(){
        if (data.size()==0){
            System.out.println("Empty List: ...");
        } else {
            for(Iterator<Double> itr = data.iterator(); itr.hasNext();){
                System.out.print(itr.next().toString()+" ");
            }
            System.out.println("");
        }
        
    }
}



