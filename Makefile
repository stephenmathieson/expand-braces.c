
CFLAGS = -std=c99 -Wall -Wextra

test: expand-braces.o test.o
	$(CC) $^ -o $@ $(CFLAGS)
	./test

example: expand-braces.o example.o
	$(CC) $^ -o $@ $(CFLAGS)

%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS)

clean:
	rm -f *.o test example

.PHONY: test clean
