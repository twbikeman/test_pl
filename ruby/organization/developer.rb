require_relative "employee"

class Developer < Employee 

    def initialize name, salary, seniory
        super name, salary, seniory
    end

    def ask &block
      yield self
    end

    def promote &block
      yield self
      return 1
    end
    

end




