#include <string>
#include "employee.h"
using namespace std;

class Developer : public Employee {
public:
  Developer(string, int, int);
  void employ(Employee *, function<void(Employee *)>);
  void dismiss(function<void(Employee *)>);
  void promote(function<void(Employee *)>);
  void ask(function<void(Employee *)>);

  
};
