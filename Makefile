
CC = gcc
CFLAGS = -Wall -Wextra -fprofile-arcs -ftest-coverage
LDFLAGS = -lgcov -coverage
AR = ar
ARFLAGS = rcs

all: run

generation.o: generation.c generation.h
	$(CC) -c generation.c -o generation.o $(CFLAGS)

libgeneration.a: generation.o
	$(AR) $(ARFLAGS) libgeneration.a generation.o

assert.o: assert.c assert.h
	$(CC) -c assert.c -o assert.o

comparison.o: comparison.c comparison.h 
	$(CC) -c comparison.c -o comparison.o  $(CFLAGS)

sort.o: sort.c sort.h 
	$(CC) -c sort.c -o sort.o  $(CFLAGS)

vector.o: vector.c vector.h 
	$(CC) -c vector.c -o vector.o  $(CFLAGS)

# comparation
libcomparison.a: comparison.o
	$(AR) $(ARFLAGS) libcomparison.a comparison.o

libsort.a: sort.o
	$(AR) $(ARFLAGS) libsort.a sort.o

libvector.a: vector.o
	$(AR) $(ARFLAGS) libvector.a vector.o

comparison_tests.o: comparison_tests.c comparison.h assert.h
	$(CC) -c comparison_tests.c -o comparison_tests.o $(CFLAGS)

vector_tests.o: vector_tests.c vector.h assert.h
	$(CC) -c vector_tests.c -o vector_tests.o $(CFLAGS)

sort_tests.o: sort_tests.c vector.h assert.h comparison.h
	$(CC) -c sort_tests.c -o sort_tests.o $(CFLAGS)

testc.exe:comparison_tests.o assert.o libcomparison.a
	$(CC) comparison_tests.o assert.o -L. -lcomparison $(LDFLAGS) -o testc.exe

tests.exe:sort_tests.o assert.o vector.o comparison.o libsort.a
	$(CC) sort_tests.o assert.o vector.o comparison.o -L. -lsort $(LDFLAGS) -o tests.exe

testv.exe:vector_tests.o assert.o generation.o libvector.a
	$(CC) vector_tests.o assert.o generation.o -L. -lvector $(LDFLAGS) -o testv.exe

generation_tests.o: generation_tests.c sort.h assert.h
	$(CC) -c generation_tests.c -o generation_tests.o $(CFLAGS)

test.exe:generation_tests.o assert.o libgeneration.a
	$(CC) generation_tests.o assert.o -L. -lgeneration $(LDFLAGS) -o test.exe

run: test.exe testc.exe tests.exe testv.exe
	./test.exe
	./testc.exe
	./tests.exe
	./testv.exe

	gcov comparison.c vector.c sort.c generation.c 

clean:
	rm -f *.o *.exe *.a *.gcov *.gcda *.gcno
	rm -rf report
	rm -f cov.info

.PHONY: all clean run