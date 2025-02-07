#ifndef ACTION_H
#define ACTION_H

Stone pick_stone(Deck * deck, int id_stone);
void place_stone_deck(Deck * deck, Stone stone);
void tour(Board * board, Deck * deck);

#endif