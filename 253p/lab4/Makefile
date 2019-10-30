CXXFLAGS=-ggdb -std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
main: lab4.cpp
	g++ $(CXXFLAGS) lab4.cpp -o product
	valgrind product 10 3 5 6 2
