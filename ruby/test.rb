class A 

    def self.aa
        puts "from class"
    end
    def self.bb
        puts "yhaoo"
    end
    def aa
        puts "from instance"
    end
end

A.aa
b = A.new
b.aa
b.bb