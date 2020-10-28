require_relative "employee"

class Developer < Employee 
    attr_accessor :employees
    def initialize name, salary, seniory,employees
        super name, salary, seniory
        @employees = []
        @employees += employees
    end

end

a = Developer.new 'yes',10, 10, [1,2,3]
p a.employees
