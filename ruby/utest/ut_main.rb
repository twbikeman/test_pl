require_relative "../organization/employee"
require_relative "../organization/developer"
require_relative "../organization/manager"

require "test/unit"

class TestOrganization < Test::Unit::TestCase

  def setup
    @hero = Developer.new "Hero", 55000, 3
    @shane = Developer.new "Shane", 48000, 2
    @employees = [@hero, @shane]
    @bailey = Manager.new "Bailey", 68320, 7, @employees
    @rafael = Manager.new "Rafael", 66250, 7
    @team = [@bailey, @rafael]
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
    memberNames = lambda do |x|
      mNames << x.name
    end
      @bailey.ask memberNames
      assert_equal(mNames[0], "Bailey")
      assert_equal(mNames[1], "Hero")
      assert_equal(mNames[2], "Shane")
      
  end

  def test4_askAllCost
    summary = 0
    allCost = lambda do |x|
      summary += x.salary
    end   
    @aysha.ask allCost 
    assert_equal(summary, 310220)
  end

  def test5_imployNewDeveloper

    employRafaelWithBailey = lambda do |x|
      x.class.name == "Manager"
    end   
    

    @bailey.employ @rafael, employRafaelWithBailey

    mNames = []
    memberNames = lambda do |x|
      mNames << x.name
    end
      @bailey.ask memberNames
      assert_equal(mNames[0], "Bailey")
      assert_equal(mNames[1], "Hero")
      assert_equal(mNames[2], "Shane")
      assert_equal(mNames[3], "Rafael")
    
    
  end
  
    
  
  
  
end
