main: my_ls.c
	gcc -g my_ls.c -o my_ls
	mkdir dir1
	mkdir dir1/dir2
	mkdir dir1/dir3
	touch file1
	touch file2
	touch dir1/file3
	touch dir1/file4
	touch dir1/dir2/file5
	touch dir1/dir2/file6
	touch dir1/dir3/file7
	touch dir1/dir3/file8
	valgrind my_ls
	valgrind my_ls dir1/dir2
	valgrind my_ls .
	valgrind my_ls my_ls.c my_ls Makefile 
	valgrind my_ls ..
	rm -r dir1
	rm file1 file2 my_ls
