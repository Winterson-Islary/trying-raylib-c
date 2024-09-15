CC = gcc
INCDIRS = -I.
OPT = -O0
LIBS = -lraylib -lgdi32 -lwinmm
CFLAGS = -Wall -Wextra -g $(INCDIRS) $(OPT)

CFILES = main.c
OBJECTS = main.o

BINARY = bin

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BINARY) $(OBJECTS)