/*
* File Name: shape.cpp
* Assignment: Lab 2, Exercise B
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Sept 22, 2025
*/

#include <iostream>
#include <cstring>
#include "shape.h"
using namespace std;

Shape::Shape(double x, double y, const char* name):
origin(Point(x,y)),
shapeName(new char[strlen(name)+1]){
  strcpy(this->shapeName, name);
}

Shape::Shape(const Shape& other):
origin(Point(other.getOrigin())),
shapeName(new char[strlen(other.getName())+1]){
  strcpy(this->shapeName, other.getName());
}

Shape::~Shape(){
  delete [] shapeName;
}

Shape& Shape::operator=(const Shape& rhs){
  if (this!=&rhs){
    delete [] shapeName;
    shapeName = new char[strlen(rhs.getName())+1];
    strcpy(this->shapeName, rhs.getName());
    origin = rhs.getOrigin();
  }
  return *this;
}

const Point& Shape::getOrigin()const{
  const Point& p=origin;
  return p;
}

const char* Shape::getName()const{return shapeName;}


void Shape::display()const{
  cout << "Shape Name: " << shapeName << endl;
  origin.display();
}

double Shape::distance(const Shape& other)const{
  return Point::distance(this->origin, other.getOrigin());
}
double Shape::distance(const Shape& the_shape, const Shape& other){
  return Point::distance(the_shape.getOrigin(), other.getOrigin());
}

void Shape::move(double dx, double dy){
  origin.setx(origin.getx()+dx);
  origin.sety(origin.gety()+dy);
}

double area(){return 0;}
double perimeter(){return 0;}



