#include "developer.h"

Developer::Developer(string name, int salary, int seniority) : Employee(name, salary, seniority) {}

void Developer::employ(Employee *candiate, function<bool(Employee *)> rule){
  rule(this);
} 

void Developer::dismiss(function<bool(Employee *)> rule){
  rule(this);
}

void Developer::promote(function<void(Employee *)> rule){
    rule(this);
}

void Developer::ask(function<void(Employee *)> todo){
    todo(this);
}
