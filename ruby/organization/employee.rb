class Employee 
    attr_accessor :name, :salary, :seniority

    def initialize name, salary, seniority
        @name = name
        @salary = salary
        @seniority = seniority
    end

    def setSalary salary
        @salary = salary
    end

end
