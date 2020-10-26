#include <string>
#include "employee.h"
using namespace std;

class Developer : public Employee {
public:
  Developer(string, int, int);
  void employ(Employee *, function<bool(Employee *)>);
  void dismiss(function<bool(Employee *)>);
  void promote(function<void(Employee *)>);
  void ask(function<void(Employee *)>);

  
};
