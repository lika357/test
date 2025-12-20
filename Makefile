
CC = gcc
CFLAGS = -Wall -Wextra -fprofile-arcs -ftest-coverage
LDFLAGS = -lgcov -coverage
AR = ar
ARFLAGS = rcs

all: test.exe run

sort.o: sort.c sort.h
	$(CC) -c sort.c -o sort.o $(CFLAGS)

libgeneration.a: sort.o
	$(AR) $(ARFLAGS) libgeneration.a sort.o

assert.o: assert.c assert.h
	$(CC) -c assert.c -o assert.o

sort_tests.o: sort_tests.c sort.h assert.h
	$(CC) -c sort_tests.c -o sort_tests.o $(CFLAGS)

test.exe:sort_tests.o assert.o libgeneration.a
	$(CC) sort_tests.o assert.o -L. -lgeneration $(LDFLAGS) -o test.exe

run: test.exe
	./test.exe
	gcov sort.c
	lcov -c -d . -o cov.info
	genhtml cov.info -o report

clean:
	rm -f *.o *.exe *.a *.gcov *.gcda *.gcno
	rm -rf report
	rm -f cov.info

.PHONY: all clean run