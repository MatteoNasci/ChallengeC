CC=clang
CFLAGS=-Wall -Werror -Wno-pragma-pack -O3 -ID:\source\repos\C\SDL2-devel-2.0.9-VC\SDL2-2.0.9\include
LDFLAGS=-lSDL2 -L.
BINARY=timed_image
BINARY_TESTS=timed_image_tests

ifeq ($(OS),Windows_NT)
	BINARY:=$(BINARY).exe
	BINARY_TESTS:=$(BINARY_TESTS).exe
endif

image: main.o gfx.o timer.o
	$(CC) -o $(BINARY) $(LDFLAGS) $^

main.o: main.c
	$(CC) -c -o $@ $(CFLAGS) $^

gfx.o: gfx.c gfx.h
	$(CC) -c -o $@ $(CFLAGS) $<

timer.o: timer.c timer.h
	$(CC) -c -o $@ $(CFLAGS) $<

tests.o: tests.c
	$(CC) -c -o $@ $(CFLAGS) $^

test: tests.o gfx.o timer.o
	$(CC) -o $(BINARY_TESTS) $(LDFLAGS) $^
	./$(BINARY_TESTS)
