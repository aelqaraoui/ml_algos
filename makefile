CC = gcc
CFLAGS  = -g -Wall 
LIBS = -lm

MYDIR = ./src
list: $(MYDIR)/*
		$(CC) $(CFLAGS) $^ -o build/main $(LIBS)

exec:
		./build/main