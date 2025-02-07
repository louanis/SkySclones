#ifndef GESTION_STRUCT_H
#define GESTION_STRUCT_H

Board * init_board(char SIZE);
void free_board(Board * main_plateau);
void ajouter_stone_board(Deck * deck, int id_stone, Board * main_plateau, Position pos);
void update_board(Board * main_plateau, Position pos);
int in(int a, int* b, int size);


Deck * init_deck(int size);
void free_deck(Deck * deck);
Stone * get_stone(Deck * deck, int id_stone);


Stone * init_stone();
void copy_stone(Stone * nullStone, Stone * cpStone);
void nullify_stone(Stone * stone);
void free_stone(Stone * stone);


#endif