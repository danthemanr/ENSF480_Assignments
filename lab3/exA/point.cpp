/*
* File Name: point.cpp
* Assignment: Lab 3, Exercise A
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Sept 26, 2025
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#ifndef POINT_H
#include "point.h"
int Point::count = 0;
#endif


Point::Point(double h, double v): x(h), y(v), id(++count+1000){}

Point::Point(const Point& other): x(other.getx()), y(other.gety()), id(++count+1000){}

Point& Point::operator=(const Point& rhs){
  x=rhs.getx();
  y=rhs.gety();
  return *this;
}

double Point::getx()const{return x;}
void Point::setx(double a){x=a;}
double Point::gety()const{return y;}
void Point::sety(double a){y=a;}

void Point::display()const{
  cout << "X-coordinate: ";
  cout << right << setw(9) << fixed << setprecision(2) << this->x << endl;
  cout << "Y-coordinate: ";
  cout << right << setw(9) << fixed << setprecision(2) << this->y << endl;
}

const int Point::counter(){return count;}

double Point::distance(const Point& the_point, const Point& other){
  double dx=the_point.getx()-other.getx();
  double dy=the_point.gety()-other.gety();
  return sqrt(dx*dx+dy*dy);
}
double Point::distance(const Point& other)const{
  double dx=this->x-other.getx();
  double dy=this->y-other.gety();
  return sqrt(dx*dx+dy*dy);
}



