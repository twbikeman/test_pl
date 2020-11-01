require_relative "employee"

class Manager < Employee 
    attr_accessor :employees
    def initialize name, salary, seniory, employees = nil
        super name, salary, seniory
        @employees = []
        @employees += employees unless employees.nil?
    end

    def ask rule
      rule.call self
      if !@employees.empty?
      @employees.each do |x|
        x.ask rule
      end
      end
    end


    def employ employee, rule

      if rule.call self
        @employees << employee
      end
      
    end
  

end

