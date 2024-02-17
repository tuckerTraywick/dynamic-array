CC := gcc
CFLAGS := -O1 -g3 -std=c99 -Wall -Wextra -Wpedantic
INCLUDE := -I./

.PHONY: test
test: build/test.o build/list.o
	@$(CC) $(CFLAGS) $^ -o $@

build/%.o: %.c
	@mkdir -p build
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

test.c: list.h

list.c: list.h

list.h:

.PHONY: clean
	@rm -rf build
