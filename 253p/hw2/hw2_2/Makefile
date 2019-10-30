CXXFLAGS=-ggdb -std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
main: parseC.cpp
	g++ $(CXXFLAGS) parseC.cpp -o parse
	valgrind parse < MusicLibrary.cpp > tokens
