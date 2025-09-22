/*
* File Name: circle.cpp
* Assignment: Lab 3, Exercise A
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Sept 26, 2025
*/

#include <cmath>
#include <iostream>
#include "circle.h"
using namespace std;

Circle::Circle(double x, double y, double r, const char* name):
Shape(x,y,name),
radius(r){}

Circle::Circle(const Circle& other):
Shape(other),
radius(other.getRadius()){}

Circle& Circle::operator=(const Circle& rhs){
  if (this!=&rhs){
    Shape::operator=(rhs);
    radius = rhs.getRadius();
  }
  return *this;
}

const double Circle::getRadius()const{return radius;}
void Circle::setRadius(double r){radius=r;}

double Circle::area()const{return radius*radius*M_PI;}
double Circle::perimeter()const{return 2*radius*M_PI;}

void Circle::display()const{
  cout << "Circle Name: " << shapeName << endl;
  origin.display();
  cout << "Radius: " << radius << endl
       << "Area: " << area() << endl
       << "Perimeter: " << perimeter() << endl;
}



