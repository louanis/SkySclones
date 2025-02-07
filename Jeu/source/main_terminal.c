#include "../header/all.h"

int main(){
    int size = 3;
    //initialisation des variable
    Board * board = init_board(size);
    Deck * all_stones = fetch_stones();
    Deck * red_deck = init_deck(5);
    Deck * blue_deck = init_deck(5);
    red_deck -> col = 1;



    return 0;
}