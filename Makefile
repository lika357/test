
CC = gcc
CFLAGS = -Wall -Wextra -fprofile-arcs -ftest-coverage
LDFLAGS = -lgcov -coverage
AR = ar
ARFLAGS = rcs

all: test.exe run

vector.o: vector.c vector.h
	$(CC) -c vector.c -o vector.o $(CFLAGS)

libgeneration.a: vector.o
	$(AR) $(ARFLAGS) libgeneration.a vector.o

assert.o: assert.c assert.h
	$(CC) -c assert.c -o assert.o

vector_tests.o: vector_tests.c vector.h assert.h
	$(CC) -c vector_tests.c -o vector_tests.o $(CFLAGS)

test.exe: vector_tests.o assert.o libgeneration.a
	$(CC) vector_tests.o assert.o -L. -lgeneration $(LDFLAGS) -o test.exe

run: test.exe
	./test.exe
	gcov vector.c
	lcov -c -d . -o cov.info
	genhtml cov.info -o report

clean:
	rm -f *.o *.exe *.a *.gcov *.gcda *.gcno
	rm -rf report
	rm -f cov.info

.PHONY: all clean run