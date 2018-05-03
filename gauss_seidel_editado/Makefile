CC= gcc
SRCS=main.c gauss.c
LIBS= -lm
FLAGS= -Wall -g
.PHONY: compile


all: compile
	$(CC) $(SRCS:.c=.o) -o principal $(FLAGS)

compile:
	$(CC) -c $(SRCS) $(FLAGS)

run:
	./principal

clean:
	rm $(SRCS:.c=.o) principal

debug:
	valgrind ./principal
