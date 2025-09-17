/*
* File Name: company.cpp
* Assignment: Lab 1 Exercise C
* Lab section: B01
* Completed by: Daniel Rey
* Submission Date: Sept 15, 2025
*/
#include <string>
#include <vector>
using namespace std;

/*struct Company {
  string companyName;
  string companyAdderss;
  
  vector<string> employees;       // vector of information about employees’ information
                                  // (name, address, date of birth)
  string dateEstablished;         // the date that company was established
  vector <string> employeeState;  // information about employees' current states
                                  //(active, suspended, retired, fired)
  vector <string> customers;      // vector of information about customers
                                  // (name, address, phone)
};*/

class Person {
friend class Company;
protected:
  string nameM;
  string phoneM;
  string addressM;
};

class Employee: public Person {
friend class Company;
private:
  const string dateOfBirthM;      // employee's birth date (YYYY/MM/DD)
  string stateM;                  // (active, suspended, retired, fired)
};

class Company {
private:
  string nameM;                   // company's name
  string addressM;                // company's address
  const string foundingDateM;     // the date that company was established
  
  vector<Employee> employeesM;    // vector of employees

  vector <Person> customersM;     // vector of customers

};
