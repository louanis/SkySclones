#include <stdio.h>
#include <stdlib.h>
#include "../header/struct.h"
#include "../header/types_val.h"



//BOARD

Board * init_board(){
    Board * main_plateau = (Board*) malloc(sizeof(Board));

    if(main_plateau == NULL){
        exit(EXIT_FAILURE);
    }

    Stone *** plateau = (Stone***) malloc(sizeof(Stone**)*BOARD_SIZE);

    if(plateau == NULL){
        exit(EXIT_FAILURE);
    }

    for(int i = 0;i<BOARD_SIZE;i++){
        plateau[i] = (Stone**) malloc(sizeof(Stone*)*BOARD_SIZE);

        if(plateau[i] == NULL){
            exit(EXIT_FAILURE);
        }

    }

    main_plateau -> board = plateau;
    main_plateau -> element = 0;
    main_plateau -> color = (char*) malloc(sizeof(char)*2);
    main_plateau -> size = BOARD_SIZE;

    return main_plateau;
}

void free_board(Board * main_plateau){


    for(int i = 0; i < main_plateau -> size ;i++){
        for(int j = 0; j < main_plateau -> size; j++){
            free(main_plateau -> board[i][j]);
        }
        free(main_plateau -> board[i]);
    }

    free(main_plateau -> board);
    free(main_plateau -> color);
    free(main_plateau);

    return;
}

void ajouter_stone_board(Stone * pierre, Board * main_plateau, Position * pos){
    if(pos -> col - 'a' >= main_plateau -> size || pos -> row >= main_plateau -> size){
        exit(EXIT_FAILURE);
    }

    main_plateau -> board[pos -> col - 'a'][pos -> row] = pierre;

    return;
}

void update_board(Board * main_plateau, Position * pos){


    if(pos -> col - 'a' >= main_plateau -> size || pos -> row >= main_plateau -> size){
        exit(EXIT_FAILURE);
    }

    if(pos -> col -'a' > 0){
        if(main_plateau -> board[pos -> col - 'a' - 1][pos -> row] -> tab_pic[3] < main_plateau -> board[pos -> col - 'a'][pos -> row] -> tab_pic[0]){
            //Change the stone color
            main_plateau -> board[pos -> col - 'a' - 1][pos -> row] -> col = main_plateau -> board[pos -> col - 'a'][pos -> row] -> col;

            //update the score
            main_plateau -> color[main_plateau -> board[pos -> col - 'a'][pos -> row] -> col] += 1;
            main_plateau -> color[(1 & (~(main_plateau -> board[pos -> col - 'a'][pos -> row] -> col)))] -= 1;
        }
    }
    if(pos -> row > 0){
        if(main_plateau -> board[pos -> col - 'a'][pos -> row - 1] -> tab_pic[2] < main_plateau -> board[pos -> col - 'a'][pos -> row] -> tab_pic[1]){
            //Change the stone color
            main_plateau -> board[pos -> col - 'a'][pos -> row - 1] -> col = main_plateau -> board[pos -> col - 'a'][pos -> row] -> col;

            //update the score
            main_plateau -> color[main_plateau -> board[pos -> col - 'a'][pos -> row] -> col] += 1;
            main_plateau -> color[(1 & (~(main_plateau -> board[pos -> col - 'a'][pos -> row] -> col)))] -= 1;
        }
    }
    if(pos -> row < main_plateau -> size - 1){
        if(main_plateau -> board[pos -> col - 'a'][pos -> row + 1] -> tab_pic[1] < main_plateau -> board[pos -> col - 'a'][pos -> row] -> tab_pic[2]){
            //Change the stone color
            main_plateau -> board[pos -> col - 'a'][pos -> row + 1] -> col = main_plateau -> board[pos -> col - 'a'][pos -> row] -> col;

            //update the score
            main_plateau -> color[main_plateau -> board[pos -> col - 'a'][pos -> row] -> col] += 1;
            main_plateau -> color[(1 & (~(main_plateau -> board[pos -> col - 'a'][pos -> row] -> col)))] -= 1;
        }
    }
    if(pos -> col -'a' < main_plateau -> size - 1){
        if(main_plateau -> board[pos -> col - 'a' + 1][pos -> row] -> tab_pic[0] < main_plateau -> board[pos -> col - 'a'][pos -> row] -> tab_pic[3]){
            //Change the stone color
            main_plateau -> board[pos -> col - 'a' + 1][pos -> row] -> col = main_plateau -> board[pos -> col - 'a'][pos -> row] -> col;

            //update the score
            main_plateau -> color[main_plateau -> board[pos -> col - 'a'][pos -> row] -> col] += 1;
            main_plateau -> color[(1 & (~(main_plateau -> board[pos -> col - 'a'][pos -> row] -> col)))] -= 1;
        }
    }


    return;
}


//Deck

Deck * init_deck(int size){
    Deck * deck = (Deck*) malloc(sizeof(Deck));

    if(deck == NULL){
        exit(EXIT_FAILURE);
    }
    
    Stone ** tab_stones = (Stone**) malloc(sizeof(Stone*)*size);

    deck -> tab_stones = tab_stones;
    deck -> col = 0;
    deck -> size = size;

    return deck;
}

void free_deck(Deck * deck){

    free(deck->tab_stones);
    free(deck);

    return;
}

//Stone

Stone * init_stone(){
    Stone * stone = (Stone*) malloc(sizeof(Stone));

    if(stone == NULL){
        exit(EXIT_FAILURE);
    }

    pic * tab_pic = (pic*) malloc(4*sizeof(pic));

    stone -> col = 0;
    stone -> tab_pic = tab_pic;
    stone -> id = 0;
    stone -> null = 0;

    return stone;

}


void free_stone(Stone * stone){

    free(stone -> tab_pic);
    free(stone);

    return;
}