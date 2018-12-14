CC=clang
CPPCHECK=D:\CppCheck\cppcheck.exe
CFLAGS=-Wall -Werror -Wno-pragma-pack -O3
BINARY=float_rw
BINARY_TESTS=float_rw_tests

ifeq ($(OS),Windows_NT)
	BINARY:=$(BINARY).exe
	BINARY_TESTS:=$(BINARY_TESTS).exe
endif

float_rw: main.o utils.o
	$(CC) -o $(BINARY) $^

main.o: main.c
	$(CC) -c -o $@ $(CFLAGS) $^
	$(CPPCHECK) $^

utils.o: utils.c utils.h
	$(CC) -c -o $@ $(CFLAGS) $<
	$(CPPCHECK) $^

tests.o: tests.c
	$(CC) -c -o $@ $(CFLAGS) $^
	$(CPPCHECK) $^

test: tests.o utils.o
	$(CC) -o $(BINARY_TESTS) $^
	./$(BINARY_TESTS)
