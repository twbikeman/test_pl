#include <vector>
#include <algorithm>
#include <functional>
#include "../organization/employee.h"
#include "../organization/developer.h"
#include "../organization/manager.h"


class OrganizationTest : public ::testing::Test {
protected:
  void SetUp() override {
    this->hero = new Developer("Hero", 55000, 3);
    this->shane = new Developer("Shane", 48000, 2);
    vector<Employee *> employees = {this->hero, this->shane};
    this->bailey = new Manager("Bailey", 68320, 7, employees);
    this->rafael = new Manager("Rafael", 66250, 7);

    vector<Employee *> team = {this->rafael, this->bailey};
    
    
    this->aysha = new Manager("Aysha", 72650, 9, team);
    
  }
  void TearDown() override {
    delete this->hero;
    delete this->shane;
    delete this->bailey;
    delete this->rafael;
    delete this->aysha;
  }
  
  Developer *hero;
  Developer *shane;
  Manager *bailey;
  Manager *rafael;
  Manager *aysha;
};

TEST_F(OrganizationTest, test1_developerInitialize) {
  ASSERT_EQ(this->hero->getName(), "Hero");
  ASSERT_EQ(this->hero->getSalary(), 55000);
  ASSERT_EQ(this->hero->getSeniority(), 3); 
}


TEST_F(OrganizationTest, test2_managerInitializationWithEmployees) {
  ASSERT_EQ(this->bailey->getName(), "Bailey");
  ASSERT_EQ(this->bailey->getSalary(), 68320);
  ASSERT_EQ(this->bailey->getSeniority(), 7); 
}


TEST_F(OrganizationTest, test3_askMemberNames) {
  vector<string> mNames;
  function<void(Employee *)> memberNames = [&mNames](Employee *e){
					     mNames.push_back(e->getName());				     
					   };
  this->bailey->ask(memberNames);  
  ASSERT_EQ(mNames[0], "Bailey");
  ASSERT_EQ(mNames[1], "Hero");
  ASSERT_EQ(mNames[2], "Shane");
}


TEST_F(OrganizationTest, test4_askAllCost) {
  int summary = 0;
  function<void(Employee *)> allCost = [&summary](Employee *e){
    summary += e->getSalary();
  };
  this->aysha->ask(allCost);
  ASSERT_EQ(summary,310220);
}

TEST_F(OrganizationTest, test5_employNewDeveloper) {

  function<bool (Employee *)> employRafaelWithBailey = [](Employee *e)->bool {
    return dynamic_cast<Manager *>(e) != nullptr;
  };  
  this->bailey->employ(this->rafael, employRafaelWithBailey);
  vector<string> mNames;
  function<void(Employee *)> memberNames = [&mNames](Employee *e) {
    mNames.push_back(e->getName());
  };
  this->bailey->ask(memberNames);
  ASSERT_EQ(mNames[0], "Bailey");
  ASSERT_EQ(mNames[1], "Hero");
  ASSERT_EQ(mNames[2], "Shane");
  ASSERT_EQ(mNames[3], "Rafael");
}

TEST_F(OrganizationTest, test6_dismissEmployeeByName) {
  function<bool (Employee *)> employeeWhoseNameIsHero = [](Employee *e) {
    return e->getName() == "Hero";
  };
  this->bailey->dismiss(employeeWhoseNameIsHero);
  vector<string> mNames;
  function<void (Employee *)> memberNames = [&mNames](Employee *e) {
    mNames.push_back(e->getName());
  };
   this->bailey->ask(memberNames); 
   ASSERT_EQ(mNames.size(), 2); 
   ASSERT_EQ(mNames[0], "Bailey");
   ASSERT_EQ(mNames[1], "Shane");
}

TEST_F(OrganizationTest, test7_dismissEmployeeWhoseSeniorityisLessThan3) {
  
  function<bool (Employee *)> dismissEmployeeWhoseSeniorityisLessThan3 = [](Employee *e) {
    return e->getSeniority() < 3;
  };
  this->bailey->dismiss(dismissEmployeeWhoseSeniorityisLessThan3);
  vector<string> mNames;
  function<void (Employee *)> memberNames = [&mNames](Employee *e) {
    mNames.push_back(e->getName());
  };
   this->bailey->ask(memberNames); 
   ASSERT_EQ(mNames.size(), 2); 
   ASSERT_EQ(mNames[0], "Bailey");
   ASSERT_EQ(mNames[1], "Hero");
}

TEST_F(OrganizationTest, test8_promoteEmployeeWhoseSeniorityIsGreaterThan3ByRaisingSalary5pct) {
  function<void (Employee *)> employeeWhoseSeniorityIsGreaterThan3ByRaisingSalary5pct = [](Employee *e) {
    if (e->getSeniority() >= 3) e->setSalary(e->getSalary() * 1.05);
  };
  this->bailey->promote(employeeWhoseSeniorityIsGreaterThan3ByRaisingSalary5pct);
  vector<int> mSalary;
  function<void (Employee *)> salary = [&mSalary](Employee *e) {
    mSalary.push_back(e->getSalary());
  };
   this->bailey->ask(salary); 
   ASSERT_EQ(mSalary[0], 71736);
   ASSERT_EQ(mSalary[1], 57750);
   ASSERT_EQ(mSalary[2], 48000); 
}

TEST_F(OrganizationTest, test9_promoteEmployeeHavingMoreThan2EmployeesByRaisingSalary2pct)
{
  int count = 0;
  function<void (Employee *)> IfItHasMoreThan2EmployeesByRaisingSalary2pct = [&count](Employee *e){
									       if (count > 2) e->setSalary(e->getSalary() * 1.02);
									       count += 1;
  };

  this->aysha->promote(IfItHasMoreThan2EmployeesByRaisingSalary2pct);
  vector<int> mSalay;
  function<void(Employee *)> salay = [&mSalay](Employee *e) {mSalay.push_back(e->getSalary());
  };
  this->aysha->ask(salay);
  ASSERT_EQ(mSalay[0], 74103);
  ASSERT_EQ(mSalay[1], 66250);
  ASSERT_EQ(mSalay[2], 69686);
  ASSERT_EQ(mSalay[3], 55000);
  ASSERT_EQ(mSalay[4], 48000);
}

TEST_F(OrganizationTest, test10_dismissMangerAndTransferEmployees)
{
  vector<Employee *> employees;
  function<bool(Employee *)> Bailey = [](Employee *e) {
					if (dynamic_cast<Manager *>(e) != nullptr && e->getName() == "Bailey") {
					  return true;
					}
					else
					  return false;
				      };
  function<bool(Employee *)> transfer = [&employees](Employee *e) {
					   employees.push_back(e);
					   return true;
					};

  this->aysha->dismiss(Bailey);
  this->bailey->dismiss(transfer);
  for (auto e : employees)
    {
      this->rafael->employ(e, [](Employee *){return true;});
    }
  vector<string> mNames;
  function<void(Employee *)> memberNames = [&mNames](Employee *e) {
    mNames.push_back(e->getName());
  };
  this->aysha->ask(memberNames);
  ASSERT_EQ(mNames.size(), 4);
  ASSERT_EQ(mNames[0], "Aysha");
  ASSERT_EQ(mNames[1], "Rafael");
  ASSERT_EQ(mNames[2], "Hero");
  ASSERT_EQ(mNames[3], "Shane");
}

