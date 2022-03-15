CC=gcc

all: db

db.o: db.c
	$(CC) -c $^

db: db.o
	$(CC) -o $@ $^