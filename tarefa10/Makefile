CFLAGS = -std=c99 -Wall -Werror -Werror=vla -g
LDFLAGS = -lm

.PHONY: all clean

all: corretor

corretor: corretor_main.c
	gcc $(CFLAGS) -c corretor_funcoes.c $(LDFLAGS)
	gcc $(CFLAGS) -c corretor_main.c $(LDFLAGS)
	gcc $(CFLAGS) -o corretor corretor_main.o corretor_funcoes.o $(LDFLAGS)

clean:
	rm -f corretor
	rm -f *.o
