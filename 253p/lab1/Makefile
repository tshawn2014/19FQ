XXFLAGS=-ggdb -std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
main: average.cpp
	g++ average.cpp -o average
	valgrind average nums.dat
	valgrind average letter1.dat
	valgrind average letter2.dat
	valgrind average empty.dat 
