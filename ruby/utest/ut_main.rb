require_relative "../organization/employee.rb"
require_relative "../organization/developer.rb"
require_relative "../organization/manager.rb"

require "test/unit"

class OrganizationTest < Test::Unit::TestCase
  def setup
    @hero = Developer.new "Hero", 55000, 3
    @shane = Developer.new "Shane", 48000, 2
    employees = [@hero, @shane]
    bailey = Manager.new "Bailey", 68320, 7 , employees
    rafael = Manager.new  "Rafael", 66250, 7
    team = [@bailey, @rafael]
    @aysha = Manager.new "Aysha", 72650, 9, team
  end
  
  def developerInitialization
    assert_equal(@hero.name, "Hero")
    assert_equal(@hero.salary, 55000)
    assert_equal(@hero.seniority, 3)   
  end
end
