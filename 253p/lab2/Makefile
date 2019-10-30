CXXFLAGS=-ggdb -std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
main: urlparse.cpp
	g++ $(CXXFLAGS) urlparse.cpp -o parse
	parse < urls.txt
