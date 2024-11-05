CC = gcc
CFLAGS = -g -Wall -Wextra -Iinclude -std=c2x

TARGET = lib/darray.a

.PHONY: all
all: tests
	bin/tests/darray_test

.PHONY: release
release: CFLAGS += -O3
release: $(TARGET) tests

.PHONY: debug
debug: CFLAGS += -O0 -g
debug: $(TARGET) tests

.PHONY: build
build: 
	mkdir -p build
	mkdir -p bin/tests
	mkdir -p lib

.PHONY: clean
clean: 
	-rm -rf $(TARGET)
	-rm -rf lib bin build

$(TARGET): build build/darray.o
	ar rcs $(TARGET) build/darray.o

.PHONY: tests
tests: test/darray_test.c ${TARGET}
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) test/darray_test.c $(TARGET) -o bin/tests/darray_test

build/darray.o: src/darray.c include/darray.h
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -c src/darray.c -o build/darray.o
