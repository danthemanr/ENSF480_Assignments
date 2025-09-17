/*
* File Name: human.cpp
* Assignment: Lab 1 Exercise D
* Lab section: B01
* Completed by: Daniel Rey
* Submission Date: Sept 15, 2025
*/

#include <cstring>
#include <iostream>
#include "human.h"
using namespace std;


Point::Point(double a, double b): x(a), y(b) {}
double Point::get_x()const {return x;}
double Point::get_y()const {return y;}
void Point::set_x(double a) {x = a;};
void Point::set_y(double a) {y = a;};


Human::Human(const char* nam, double x, double y): name(new char[strlen(nam)+1]) {
  strcpy(this->name, nam);
  location.set_x(x);
  location.set_y(y);
}

Human::~Human(){
  delete [] name;
}

const char* Human::get_name()const {return name;}
void Human::set_name(char* name) {
  delete [] this->name;
  this->name = new char[strlen(name)+1];
  strcpy(this->name, name);
}

Point Human::get_point()const {return location;}
void Human::set_point(double x, double y) {
  location.set_x(x);
  location.set_y(y);
}

void Human::display()const {
  cout << "Human Name: " << name << "\nHuman Location: "
  << location.get_x() << " ,"
  << location.get_y() << ".\n" << endl;
}