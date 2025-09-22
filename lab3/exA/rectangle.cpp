/*
* File Name: rectangle.cpp
* Assignment: Lab 3, Exercise A
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Sept 26, 2025
*/

#include <iostream>
#include "rectangle.h"
using namespace std;

Rectangle::Rectangle(double x, double y, double a, double b, const char* name):
Shape(x,y,name),
Square(x,y,a,name),
side_b(b){}

Rectangle::Rectangle(const Rectangle& other):
Shape(other),
Square(other),
side_b(other.get_side_b()){}

Rectangle& Rectangle::operator=(const Rectangle& rhs){
  if (this!=&rhs){
    Square::operator=(rhs);
    side_b = rhs.get_side_b();
  }
  return *this;
}

const double Rectangle::get_side_b()const{return side_b;}
void Rectangle::set_side_b(double b){side_b=b;}

double Rectangle::area()const{return side_a*side_b;}
double Rectangle::perimeter()const{return side_a*2+side_b*2;}

void Rectangle::display()const{
  cout << "Rectangle Name: " << shapeName << endl;
  origin.display();
  cout << "Side a: " << side_a << endl
       << "Side b: " << side_b << endl
       << "Area: " << area() << endl
       << "Perimeter: " << perimeter() << endl;
}



