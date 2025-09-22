/*
* File Name: curveCut.cpp
* Assignment: Lab 3, Exercise A
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Sept 26, 2025
*/


#include <iostream>
#include <cstdlib>
#include "curveCut.h"
using namespace std;

CurveCut::CurveCut(double x, double y, double a, double b, double r, const char* name):
Shape(x,y,name),
Square(x,y,a,name),
Rectangle(x,y,a,b,name),
Circle(x,y,r,name){
  if (r>a||r>b) {
    cout << "Radius must not be greater than either of the rectangle's sides" << endl;
    exit(1);
  }
}

CurveCut::CurveCut(const CurveCut& other):
Shape(other),
Square(other),
Rectangle(other),
Circle(other){}

CurveCut& CurveCut::operator=(const CurveCut& rhs){
  if (this!=&rhs){
    Rectangle::operator=(rhs);
    radius = rhs.getRadius();
  }
  return *this;
}

void CurveCut::setRadius(double r){
  if (r>side_a||r>side_b) {
    cout << "Radius must not be greater than either of the rectangle's sides" << endl;
    exit(1);
  }
  radius=r;
}
void CurveCut::set_side_b(double b){
  if (radius>b) {
    cout << "Radius must not be greater than either of the rectangle's sides" << endl;
    exit(1);
  }
  side_b=b;
}
void CurveCut::set_side_a(double a){
  if (radius>a) {
    cout << "Radius must not be greater than either of the rectangle's sides" << endl;
    exit(1);
  }
  side_a=a;
}

double CurveCut::area()const{return Rectangle::area()-Circle::area()/4;}
double CurveCut::perimeter()const{return Rectangle::perimeter()-radius*2+Circle::perimeter()/4;}

void CurveCut::display()const{
  cout << "CurveCut Name: " << shapeName << endl;
  origin.display();
  cout << "Width: " << side_a << endl
       << "Length: " << side_b << endl
       << "Radius of the cut: " << radius << endl;
}



