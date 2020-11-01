require_relative "../organization/employee"
require_relative "../organization/developer"
require_relative "../organization/manager"

require "test/unit"

class TestOrganization < Test::Unit::TestCase
7
  def setup
    @hero = Developer.new "Hero", 55000, 3
    @shane = Developer.new "Shane", 48000, 2
    @employees = [@hero, @shane]
    @bailey = Manager.new "Bailey", 68320, 7, @employees
    @rafael = Manager.new "Rafael", 66250, 7
    @team = [@rafael, @bailey]
    @aysha = Manager.new "Aysha", 72650, 9, @team
  end
  

  def test1_developerInitialization    
    assert_equal(@hero.name, "Hero")
    assert_equal(@hero.salary, 55000)
    assert_equal(@hero.seniority, 3)    
  end

  def test2_Initialization    
    assert_equal(@bailey.name, "Bailey")
    assert_equal(@bailey.salary, 68320)
    assert_equal(@bailey.seniority, 7)    
  end



  def test3_askMemberNames
      mNames = []
      @bailey.ask  do |x|
        mNames << x.name
      end
      assert_equal(mNames[0], "Bailey")
      assert_equal(mNames[1], "Hero")
      assert_equal(mNames[2], "Shane")
  end

  def test4_askAllCost
    summary = 0
    @aysha.ask do |x|
      summary += x.salary
    end
    assert_equal(summary, 310220)
  end

  def test5_imployNewDeveloper
    @bailey.employ @rafael do |x|
      x.class.name == "Manager"
    end
    mNames = []
    @bailey.ask  do |x|
      mNames << x.name
    end
      assert_equal(mNames[0], "Bailey")
      assert_equal(mNames[1], "Hero")
      assert_equal(mNames[2], "Shane")
      assert_equal(mNames[3], "Rafael")
  end


  def test6_dismissEmployeesByName
    @bailey.dismiss do |x|
      x.name == "Hero"
    end
    mNames = []
    @bailey.ask  do |x|
      mNames << x.name
    end
    assert_equal(mNames.length, 2)
    assert_equal(mNames[0], "Bailey")
    assert_equal(mNames[1], "Shane")
  end

  def test7_dismissEmployeeWhoseSeniorityIsLessThan3
    @bailey.dismiss do |x|
      x.seniority < 3
    end
    mNames = []
    @bailey.ask  do |x|
      mNames << x.name
    end
    assert_equal(mNames.length, 2)
    assert_equal(mNames[0], "Bailey")
    assert_equal(mNames[1], "Hero")
  end
  
  def test8_promteEmployeeWhoseSeniorityIsGreaterThanByRaisingSalary5pct
    @bailey.promote do |x|
      if x.seniority >= 3
        x.salary = x.salary * 1.05
      end
    end
    mSalary = []
    @bailey.ask  do |x|
      mSalary << x.salary
    end
    assert_equal(mSalary[0], 71736)
    assert_equal(mSalary[1], 57750)
    assert_equal(mSalary[2], 48000)
  end
  
    
  def test9_promoteEmployeeHavingMoreThan2EmployeeByRaisingSalary2pct

    @aysha.promote do |x|
      count  = 0
      x.ask {count += 1}
      if count > 2
        x.salary = (x.salary * 1.02).round
      end
    end
    
    mSalary = []
    @aysha.ask  do |x| 
      mSalary << x.salary
    end
    assert_equal(mSalary[0], 74103)
    assert_equal(mSalary[1], 66250)
    assert_equal(mSalary[2], 69686)
    assert_equal(mSalary[3], 55000)
    assert_equal(mSalary[4], 48000)
  end
  
  def test10_dismissManagerAndTransferEmployees
    employees = []
    @aysha.dismiss do |x|
      if x.name == "Bailey"
        employees.concat x.employees
        true
      else
        false
      end
    end
    employees.each do |x|
      @rafael.employ(x) {true} 
    end  
    mNames = []
    @aysha.ask  do |k|
      mNames << k.name
    end
    assert_equal(mNames.length, 4) 
    assert_equal(mNames[0], "Aysha")
    assert_equal(mNames[1], "Rafael")
    assert_equal(mNames[2], "Hero")
    assert_equal(mNames[3], "Shane")
  end


  
    

end
