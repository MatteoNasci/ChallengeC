CC=clang
CPPCHECK=D:\CppCheck\cppcheck.exe
CFLAGS=-Wall -Werror -Wno-pragma-pack -O3
BINARY=reverse_arg
BINARY_TESTS=reverse_arg_tests

ifeq ($(OS),Windows_NT)
	BINARY:=$(BINARY).exe
	BINARY_TESTS:=$(BINARY_TESTS).exe
endif

reverse: main.o utils.o
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
