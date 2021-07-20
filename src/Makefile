CC=gcc
CFLAGS=-I. -g

sort_files=$(wildcard *sort.c)
binaries=$(sort_files:%.c=%.exec)

test_file=test.c
dependencies=sort.h

compile: $(binaries)

%.exec: %.c $(dependencies)
	$(CC) $(test_file) $< -o $@

clean: 
	$(RM) $(binaries)

.PHONY: clean compile