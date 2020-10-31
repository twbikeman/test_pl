require_relative "employee"

class Manager < Employee 
    attr_accessor :employees
    def initialize name, salary, seniory, employees = nil
        super name, salary, seniory
        @employees = []
        @employees += employees unless employees.nil?
    end
  

end

