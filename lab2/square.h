/*
* File Name: square.h
* Assignment: Lab 2, Exercise B
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Sept 22, 2022
*/

#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
using namespace std;

class Square: public Shape{
protected:
  double side_a;
public:
  Square(double x, double y, double a, char* name);
  Square(const Square& other);
  Square& operator =(const Square& rhs);
  const double get_side_a()const;
  void set_side_a(double a);
  
  double area()const;
  double perimeter()const;
  virtual void display()const;
};
#endif



