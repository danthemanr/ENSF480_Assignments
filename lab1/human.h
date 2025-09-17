/*
* File Name: human.h
* Assignment: Lab 1 Exercise D
* Lab section: B01
* Completed by: Daniel Rey
* Submission Date: Sept 15, 2025
*/

#ifndef HUMAN_H
#define HUMAN_H
#include <cstring>
#include <iostream>

using namespace std;
class Point{
private:
  double x;       // x coordinate of a location on Cartisian Plain
  double y;       // y coordinate of a location on Cartisian Plain
public:
  Point(double a =0, double b =0);

  double get_x() const;
  //PROMISSES: Returns the x coordinate.

  double get_y() const;
  //PROMISSES: Returns the y coordinate.

  void set_x(double a);
  //PROMISSES: Sets the x coordinate to a.

  void set_y(double a);
  //PROMISSES: Sets the y coordinate to a.
};

class Human {
private:
  Point location;   // Location of an object of Human on a Cartisian Plain
  char *name;       // Human's name
public:
  Human(const char* nam="", double x=0, double y=0);
  ~Human();
  
  const char* get_name() const;
  //PROMISSES: Returns the Human's name
  
  void set_name(char* name);
  //PROMISSES: Human's name is changed to the name passed to this function

  Point get_point() const;
  //PROMISSES: Returns the Human's location as a Point object

  void set_point(double x, double y);
  //PROMISSES: Human's location coordinates are changed to x and y.

  void display() const;
  //PROMISSES: Prints the information about the Human to the ouput stream
};

#endif