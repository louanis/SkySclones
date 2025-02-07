#toujours pas complet btw

CC= gcc
CFLAGS= -C99 -Wall -Werror
EXEC= test


SRC= ./Jeu/source/fetch.c ./Jeu/source/gestion_struct.c ./Jeu/source/actions.c ./Jeu/source/affichage_terminal.c ./Jeu/source/main_terminal.c
OBJ= $(SRC:.c=.o)

app : $(OBJ)
	CC -o $@ $^ CFLAGS

%.o : %.c
	CC CFLAGS -c -o $@ $^

clean : 
	rm -f $(OBJ)
	rm -f $(EXEC)

.PHONY : clean deb

deb:
	gcc -c ./Jeu/source/fetch.c -o ./Jeu/source/fetch.o
	gcc -c ./Jeu/source/gestion_struct.c -o ./Jeu/source/gestion_struct.o
	gcc -c ./Jeu/source/actions.c -o ./Jeu/source/actions.o
	gcc -c ./Jeu/source/affichage_terminal.c -o ./Jeu/source/affichage_terminal.o
	gcc -c ./Jeu/source/main_terminal.c -o ./Jeu/source/main_terminal.o
	gcc -o $(EXEC) ./Jeu/source/*.o
	./$(EXEC)
	