/*
* File Name: curveCut.h
* Assignment: Lab 3, Exercise A
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Sept 26, 2025
*/

#ifndef CURVECUT_H
#define CURVECUT_H
#include "circle.h"
#include "rectangle.h"
using namespace std;

class CurveCut: public Rectangle, public Circle{
public:
  CurveCut(double x, double y, double a, double b, double r, const char* name);
  CurveCut(const CurveCut& other);
  CurveCut& operator =(const CurveCut& rhs);
  
  void setRadius(double r);
  void set_side_b(double b);
  void set_side_a(double a);
  
  double area()const;
  double perimeter()const;
  void display()const;
};
#endif



