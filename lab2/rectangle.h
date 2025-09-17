/*
* File Name: rectangle.h
* Assignment: Lab 2, Exercise B
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Sept 22, 2022
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "square.h"
using namespace std;

class Rectangle: public Square{
private:
  double side_b;
public:
  Rectangle(double x, double y, double a, double b, char* name);
  Rectangle(const Rectangle& other);
  Rectangle& operator =(const Rectangle& rhs);
  const double get_side_b()const;
  void set_side_b(double b);
  
  double area()const;
  double perimeter()const;
  void display()const;
};
#endif



