compiler = gcc
gdb_option = -g

test: test.c my_log.o
	$(compiler) $(gdb_option) test.c my_log.o -o test

my_log.o: my_log.c
	$(compiler) $(gdb_option) -c my_log.c -o my_log.o

clean:
	rm -rf *.i *.s *.o test
