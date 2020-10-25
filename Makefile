all: ut_main.cpp
	g++ ut_main.cpp -Igtest/include  -lgtest -lpthread
