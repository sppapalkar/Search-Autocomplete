CC = gcc

SRCS = $(wildcard src/*.c) \
       $(wildcard src/heap/*.c) \
       $(wildcard src/map/*.c) \
       $(wildcard src/search/*.c) \
       $(wildcard src/trie/*.c)

HEADERS = $(wildcard src/*.h) \
          $(wildcard src/heap/*.h) \
          $(wildcard src/map/*.h) \
          $(wildcard src/search/*.h) \
          $(wildcard src/trie/*.h)

OBJECTS = $(SRCS:.c=.o)

./main: $(OBJECTS)
	$(CC) $^ -o $@

./%.o: src/%.c $(HEADERS)
	$(CC) $< -c -o $@

.PHONY: clean
clean:
	rm -f $(obj) main