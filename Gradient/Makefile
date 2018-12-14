CC=clang
CPPCHECK=D:\CppCheck\cppcheck.exe
CFLAGS=-Wall -Werror -Wno-pragma-pack -O3 -ID:\source\repos\C\SDL2-devel-2.0.9-VC\SDL2-2.0.9\include
LDFLAGS=-lSDL2 -L.
BINARY=gradient
BINARY_TESTS=gradient_tests

ifeq ($(OS),Windows_NT)
	BINARY:=$(BINARY).exe
	BINARY_TESTS:=$(BINARY_TESTS).exe
endif

image: main.o gfx.o
	$(CC) -o $(BINARY) $(LDFLAGS) $^

main.o: main.c
	$(CC) -c -o $@ $(CFLAGS) $^
	$(CPPCHECK) $^

gfx.o: gfx.c gfx.h
	$(CC) -c -o $@ $(CFLAGS) $<
	$(CPPCHECK) $^

tests.o: tests.c
	$(CC) -c -o $@ $(CFLAGS) $^
	$(CPPCHECK) $^

test: tests.o gfx.o
	$(CC) -o $(BINARY_TESTS) $(LDFLAGS) $^
	./$(BINARY_TESTS)
