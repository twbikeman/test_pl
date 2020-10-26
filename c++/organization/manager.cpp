#include "manager.h"

Manager::Manager(string name, int salary, int seniority) : Employee(name, salary, seniority) {}

Manager::Manager(string name, int salary, int seniority, vector<Employee *> employees) : Employee(name, salary, seniority) {
  this->employees = employees;
}

void Manager::employ(Employee *candidate, function<bool(Employee *)> rule){
  if (rule(this))
  this->employees.push_back(candidate);
} 

void Manager::dismiss(function<bool(Employee *)> rule){
  rule(this);
}

void Manager::promote(function<void(Employee *)> rule){
    rule(this);
}

void Manager::ask(function<void(Employee *)> todo){
    todo(this);
    for (auto e: this->employees)
      e->ask(todo);
}
