#toujours pas complet btw

CC= gcc
CFLAGS= -C99 -Wall -Werror


SRC= ./Jeu/source/fetch.c ./Jeu/source/gestion_struct.c
OBJ= $(SRC:.c=.o)

app : $(OBJ)
	CC -o $@ $^ CFLAGS

%.o : %.c
	CC CFLAGS -c -o $@ $^

clean : 
	rm -f $(OBJ)

.PHONY : clean deb

deb:
	gcc -c ./Jeu/source/fetch.c -o ./Jeu/source/fetch.o
	gcc -c ./Jeu/source/gestion_struct.c -o ./Jeu/source/gestion_struct.o
	gcc -o test ./Jeu/source/*.o
	./test 