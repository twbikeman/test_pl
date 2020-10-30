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
  int i = 0;
  for (auto e: this->employees) {
    if (rule(e)) this->employees.erase(this->employees.begin() + i);
    i++;
  }


	   
}

void Manager::promote(function<void(Employee *)> rule){

  int num = this->employees.size();
  rule(this);
  for (auto e: this->employees)
    e->promote(rule);

}

void Manager::ask(function<void(Employee *)> todo){
    todo(this);
    for (auto e: this->employees)
      e->ask(todo);
}
