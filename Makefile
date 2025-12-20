
CC = gcc
CFLAGS = -Wall -Wextra -fprofile-arcs -ftest-coverage
LDFLAGS = -lgcov -coverage
AR = ar
ARFLAGS = rcs

all: test.exe run

generation.o: generation.c generation.h
	$(CC) -c generation.c -o generation.o $(CFLAGS)

libgeneration.a: generation.o
	$(AR) $(ARFLAGS) libgeneration.a generation.o

assert.o: assert.c assert.h
	$(CC) -c assert.c -o assert.o

generation_tests.o: generation_tests.c generation.h assert.h
	$(CC) -c generation_tests.c -o generation_tests.o $(CFLAGS)

test.exe: generation_tests.o assert.o libgeneration.a
	$(CC) generation_tests.o assert.o -L. -lgeneration $(LDFLAGS) -o test.exe

run: test.exe
	./test.exe
	gcov generation.c
	lcov -c -d . -o cov.info
	genhtml cov.info -o report

clean:
	rm -f *.o *.exe *.a *.gcov *.gcda *.gcno
	rm -rf report
	rm -f cov.info

.PHONY: all clean run