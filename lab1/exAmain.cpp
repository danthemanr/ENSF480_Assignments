// exAmain.cpp
// Lab 1 - Exercise A
// Author - M. Moussavi
// lowercase notes done by Daniel

#include <iostream>
using namespace std;
#include "mystring.h"

int main(void)
{
  Mystring *ar[3];
  Mystring c = 3; //int constructor
  ar[2] = &c;
  ar[1] = ar[0] = nullptr;
    
  // A BLOCK OF CODE BEGINS HERE
  {
    Mystring x[2]; //default constructor twice

    x[0].set_str("ENEL");
    x[1].set_str("0");
    Mystring* z = new Mystring("4"); //char* constructor
      
    x[0].append(*z).append(x[1]);
	/*The above line somehow uses the copy constructor twice
	because the arguments are passed by value.
	It also calls the destructor twice at the very end.*/
  
    Mystring mars = x[0]; //copy constructor

    x[1] = x[0]; //assignment
    
    Mystring jupiter("White"); //char* constructor

      ar[0] = new Mystring ("Yellow"); //char* constructor

  } // BLOCK ENDS HERE

  c.set_str("A");
  delete  ar [0];
 
  Mystring d = "Green";
  
  cout << "\nProgram terminated successfully." <<endl;
  return 0;
}

