require_relative "employee"

class Manager < Employee 
    attr_accessor :employees
    def initialize name, salary, seniory, employees = nil
        super name, salary, seniory
        @employees = []
        @employees += employees unless employees.nil?
    end

    def ask &block
      yield self
      if !@employees.empty?
        @employees.each do |x|
          x.ask &block
        end
      end                       
    end


    def employ employee, &block
      if yield self
        @employees << employee
      end
    end

    def dismiss &block
      if !@employees.empty?
        @employees.each do |x|
          if yield x
            @employees.delete(x)
          end
        end                       
      end
    end


    def promote &block
      if !@employees.empty?
        @employees.each do |x|
          x.promote &block
        end
      end
      yield self
    end
      
    
end

