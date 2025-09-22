/*
* File Name: point.h
* Assignment: Lab 3, Exercise A
* Lab Section: B01
* Completed by: Daniel Rey
* Submission Date: Sept 26, 2025
*/

#ifndef POINT_H
#define POINT_H
using namespace std;

class Point{
private:
  double x;
  double y;
  static int count;
  const int id;
public:
  Point(double x, double y);
  Point(const Point& other);
  Point& operator=(const Point& rhs);
  double getx() const;
  void setx(double a);
  double gety() const;
  void sety(double a);
  
  void display()const;
  const static int counter();
  static double distance(const Point& the_point, const Point& other);
  double distance(const Point& other)const;
};
#endif



