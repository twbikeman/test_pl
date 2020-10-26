#include "employee.h"

Employee::Employee(string name, int salary, int seniority) {
  this->name = name;
  this->salary = salary;
  this->seniority = seniority;
}

string Employee::getName() {
  return this->name;
}

int Employee::getSalary() {
  return this->salary;
}

int Employee::getSeniority() {
  return this->seniority;
}

void Employee::setSalary(int salary) {
  this->salary = salary;
}

void Employee::setSeniority(int seniority) {
  this->seniority = seniority;
}
