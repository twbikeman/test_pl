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

TEST_F(OrganizationTest, developerInitialize) {
  ASSERT_EQ("Shane", this->shane->getName());
  ASSERT_EQ(48000, this->shane->getSalary());
  ASSERT_EQ(2, this->shane->getSeniority()); 
}

TEST_F(OrganizationTest, askMemberNames) {

  vector<string> mNames;
  function<void(Employee *)> memberNames = [&mNames](Employee *e){
					     mNames.push_back(e->getName());

				    };
  this->bailey->ask(memberNames);
  
  ASSERT_EQ("Bailey",mNames[0]);
  ASSERT_EQ("Hero",mNames[1]);
  ASSERT_EQ("Shane",mNames[2]);
}


TEST_F(OrganizationTest, askAllCost) {
  int summary = 0;
  function<void(Employee *)> allCost = [&summary](Employee *e){
    summary += e->getSalary();
  };
  this->aysha->ask(allCost);
  ASSERT_EQ(310220, summary);

}


TEST_F(OrganizationTest, employNewDeveloper) {

  function<bool (Employee *)> employRafaelWithBailey = [](Employee *e)->bool {
    return dynamic_cast<const Manager*>(e) != nullptr;
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
