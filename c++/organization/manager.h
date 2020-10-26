#include <string>
#include <vector>


#include "employee.h"

class Manager : public Employee {
private:
  vector<Employee *> employees;
public:
  Manager(string, int, int);
  Manager(string, int, int, vector<Employee *>);
  void employ(Employee *, function<bool(Employee *)>);
  void dismiss(function<bool(Employee *)>);
  void promote(function<void(Employee *)>);
  void ask(function<void(Employee *)>);
};
