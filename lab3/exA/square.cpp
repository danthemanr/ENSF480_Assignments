/*
* File Name: square.cpp
* Assignment: Lab 3, Exercise A
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Sept 26, 2025
*/

#include <iostream>
#include "square.h"
using namespace std;

Square::Square(double x, double y, double a, const char* name): Shape(x,y,name), side_a(a){}

Square::Square(const Square& other): Shape(other), side_a(other.get_side_a()){}

Square& Square::operator=(const Square& rhs){
  if (this!=&rhs){
    Shape::operator=(rhs);
    side_a = rhs.get_side_a();
  }
  return *this;
}

const double Square::get_side_a()const{return side_a;}
void Square::set_side_a(double a){side_a=a;}

double Square::area()const{return side_a*side_a;}
double Square::perimeter()const{return side_a*4;}

void Square::display()const{
  cout << "Square Name: " << shapeName << endl;
  origin.display();
  cout << "Side a: " << side_a << endl
       << "Area: " << area() << endl
       << "Perimeter: " << perimeter() << endl;
}



