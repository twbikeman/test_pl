#include "manager.h"

Manager::Manager(string name, int salary, int seniority) : Employee(name, salary, seniority) {}

Manager::Manager(string name, int salary, int seniority, vector<Employee *> employees) : Employee(name, salary, seniority) {
  this->employees = employees;
}

void Manager::employ(Employee *candiate, function<void(Employee *)> rule){
  rule(this);
} 

void Manager::dismiss(function<void(Employee *)> rule){
  rule(this);
}

void Manager::promote(function<void(Employee *)> rule){
    rule(this);
}

void Manager::ask(function<void(Employee *)> todo){
    todo(this);
}
