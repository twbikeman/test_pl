require_relative "employee"

class Developer < Employee 

    def initialize name, salary, seniory
        super name, salary, seniory
    end

    def ask rule
      rule.call self
    end

end

