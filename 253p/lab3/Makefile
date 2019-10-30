main: main.o my_ls.o
	gcc -o main main.o my_ls.o
	valgrind main .
	valgrind main ..
	valgrind main my_ls.cpp main.cpp
main.o: main.cpp my_ls.h
	gcc -c main.cpp
my_ls.o: my_ls.cpp my_ls.h
	gcc -c my_ls.cpp
clean:
	rm main main.o my_ls.o
