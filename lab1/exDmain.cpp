/*
* File Name: exDmain.cpp
* Assignment: Lab 1 Exercise D
* Lab section: B01
* Completed by: Daniel Rey
* Submission Date: Sept 15, 2025
*/

#include <iostream>
#include "human.h"
using namespace std;


int main(int argc, char **argv)
{
  double x = 2000, y = 3000;
  Human h("Ken Lai", x , y); 
  h.display();
  return 0;
}
