#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <functional>
#include <string>

using namespace std;

class Employee {
 private:
  string name;
  int salary;
  int seniority;


 public:
  Employee(string, int, int);
  string getName();
  int getSalary();
  int getSeniority();
  void setSalary(int);
  void setSeniority(int);

  virtual void employ(Employee *, function<bool(Employee *)>) = 0;
  virtual void dismiss(function<bool(Employee *)>) = 0;
  virtual void promote(function<void(Employee *)>) = 0;
  virtual void ask(function<void(Employee *)>) = 0;
};

#endif
