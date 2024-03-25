CC = gcc

DEPS = StrList.h
TARGET_OBJECTS = Main.o StrList.o

# FLAGS
CFLAGS = -Wall -g 			# add -ggdb3 if we are checking memory leaks

all: StrList

.PHONY: clean

test: test.o StrList.o
	$(CC) $(CFLAGS) -o $@ $^ 

StrList: $(TARGET_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

*.o: *.c $(DEPS)
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o StrList test *.gch