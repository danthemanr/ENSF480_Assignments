/*
* File Name: Subject.java
* Assignment: Lab 4, Exercise C
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Oct 20, 2025
*/

package exC;

public interface Subject {
    abstract void registerObserver(Observer o);
    abstract void remove(Observer o);
    abstract void notifyAllObservers();
}



