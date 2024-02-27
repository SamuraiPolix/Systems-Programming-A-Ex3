CC = gcc

DEPS = StrList.h
TARGET_OBJECTS = Main.o StrList.o

# FLAGS
CFLAGS = -Wall -g

all: StrList

.PHONY: clean

StrList: $(TARGET_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

*.o: *.c $(DEPS)
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o StrList *.gch *.h.gch