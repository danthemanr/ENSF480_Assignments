/*
* File Name: circle.h
* Assignment: Lab 3, Exercise A
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Sept 26, 2025
*/

#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
using namespace std;

class Circle: virtual public Shape{
protected:
  double radius;
public:
  Circle(double x, double y, double r, const char* name);
  Circle(const Circle& other);
  Circle& operator =(const Circle& rhs);
  
  const double getRadius()const;
  virtual void setRadius(double r);
  
  virtual double area()const;
  virtual double perimeter()const;
  virtual void display()const;
};
#endif



