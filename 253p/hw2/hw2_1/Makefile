CXXFLAGS=-ggdb -std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
main: cstring_op.cpp
	g++ $(CXXFLAGS) cstring_op.cpp -o cstring_op
	valgrind cstring_op
