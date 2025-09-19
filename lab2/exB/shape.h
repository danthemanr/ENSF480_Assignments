/*
* File Name: shape.h
* Assignment: Lab 2, Exercise B
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Sept 22, 2025
*/

#ifndef SHAPE_H
#define SHAPE_H
#include "point.h"
using namespace std;

class Shape{
protected:
  Point origin;
  char* shapeName;
public:
  Shape(double x, double y, const char* name);
  Shape(const Shape& other);
  virtual ~Shape();
  Shape& operator=(const Shape& rhs);
  const Point& getOrigin() const;
  const char* getName() const;
  
  virtual void display()const;
  double distance(const Shape& other)const;
  static double distance(const Shape& the_shape, const Shape& other);
  void move(double dx, double dy);
};
#endif



