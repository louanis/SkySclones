#include "../header/all.h"



Stone pick_stone(Deck * deck, int id_stone){
    Stone * ret = get_stone(deck, id_stone);
    return *ret;
}

void place_stone_deck(Deck * deck, Stone stone){
    for(int i = 0; i<deck->size; i++){
        if(deck->tab_stones[i]->null = 1){
            *deck->tab_stones[i] = stone;
            return;
        }
    }
    return;
}

void place_stone_board(Stone * stone, Board * board, Position pos){

    ajouter_stone_board(stone,board,pos);
    update_board(board,pos);

    return;
}


void tour(Board * board, Deck * deck){
    //Afficher deck actuel
    //Choisir pierre
    //Choisir position sur le plateau
}

