all: utest/ut_main.cpp employee.o developer.o manager.o
	g++ -o ut_main utest/ut_main.cpp employee.o developer.o manager.o -Igtest/include  -lgtest -lpthread 


employee.o: organization/employee.h organization/employee.cpp
	g++ -c organization/employee.cpp


developer.o: organization/developer.h organization/developer.cpp
	g++ -c organization/developer.cpp


manager.o: organization/manager.h organization/manager.cpp
	g++ -c organization/manager.cpp


clean:
	rm -rf utest/a.out
