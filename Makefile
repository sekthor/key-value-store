CC=gcc

all: db

db.o: db.c
	$(CC) -c $^

db: db.o
	$(CC) -o $@ $^

install: db
	install -D ./db /usr/bin/db
	mkdir -p /var/lib/db
	chown ${USER} /var/lib/db