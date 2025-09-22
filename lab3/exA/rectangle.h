/*
* File Name: rectangle.h
* Assignment: Lab 3, Exercise A
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Sept 26, 2025
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "square.h"
using namespace std;

class Rectangle: virtual public Square{
protected:
  double side_b;
public:
  Rectangle(double x, double y, double a, double b, const char* name);
  Rectangle(const Rectangle& other);
  Rectangle& operator =(const Rectangle& rhs);
  const double get_side_b()const;
  virtual void set_side_b(double b);
  
  virtual double area()const;
  virtual double perimeter()const;
  virtual void display()const;
};
#endif



