#require_relative "../organization/developer.rb"
#require_relative "../organization/employee.rb"
#require_relative "../organization/manager.rb"
require "test/unit"

class TestSimpleNumber < Test::Unit::TestCase

  def test_simple
    assert_equal(4, 4)
  end
 
end
