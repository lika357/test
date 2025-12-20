
CC = gcc
CFLAGS = -Wall -Wextra -fprofile-arcs -ftest-coverage
LDFLAGS = -lgcov -coverage
AR = ar
ARFLAGS = rcs

all: test.exe run

comparison.o: comparison.c comparison.h
	$(CC) -c comparison.c -o comparison.o $(CFLAGS)

libgeneration.a: comparison.o
	$(AR) $(ARFLAGS) libgeneration.a comparison.o

assert.o: assert.c assert.h
	$(CC) -c assert.c -o assert.o

comparison_tests.o: comparison_tests.c comparison.h assert.h
	$(CC) -c comparison_tests.c -o comparison_tests.o $(CFLAGS)

test.exe:comparison_tests.o assert.o libgeneration.a
	$(CC) comparison_tests.o assert.o -L. -lgeneration $(LDFLAGS) -o test.exe

run: test.exe
	./test.exe
	gcov comparison.c
	lcov -c -d . -o cov.info
	genhtml cov.info -o report

clean:
	rm -f *.o *.exe *.a *.gcov *.gcda *.gcno
	rm -rf report
	rm -f cov.info

.PHONY: all clean run