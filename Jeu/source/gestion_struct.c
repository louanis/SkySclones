#include <stdio.h>
#include <stdlib.h>
#include "../header/struct.h"
#include "../header/type_val.h"



//BOARD

Board * init_board(){
    Board * main_plateau = (Board*) malloc(sizeof(Board));

    if(main_plateau == NULL){
        exit(EXIT_FAILURE);
    }

    Stones ** plateau = (Stones**) malloc(sizeof(Stones*)*BOARD_SIZE);

    if(plateau == NULL){
        exit(EXIT_FAILURE);
    }

    for(int i = 0;i<BOARD_SIZE;i++){
        plateau[i] = (Stones*) malloc(sizeof(Stones)*BOARD_SIZE);

        if(plateau[i] == NULL){
            exit(EXIT_FAILURE);
        }

    }

    main_plateau -> board = plateau;
    main_plateau -> element = 0;
    main_plateau -> color = (char*) malloc(sizeof(char)*2);
    main_plateau -> size = BOARD_SIZE

    return main_plateau;
}

void free_board(Board * main_plateau){


    for(int i = 0; i < main_plateau -> size ;i++){
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
            main_plateau -> color[(1 & (~main_plateau -> board[pos -> col - 'a'][pos -> row] -> col))] -= 1;
        }
    }
    if(pos -> row > 0){
        if(main_plateau -> board[pos -> col - 'a'][pos -> row - 1] -> tab_pic[2] < main_plateau -> board[pos -> col - 'a'][pos -> row] -> tab_pic[1]){
            //Change the stone color
            main_plateau -> board[pos -> col - 'a'][pos -> row - 1] -> col = main_plateau -> board[pos -> col - 'a'][pos -> row] -> col;

            //update the score
            main_plateau -> color[main_plateau -> board[pos -> col - 'a'][pos -> row] -> col] += 1;
            main_plateau -> color[(1 & (~main_plateau -> board[pos -> col - 'a'][pos -> row] -> col))] -= 1;
        }
    }
    if(pos -> row < main_plateau -> size - 1){
        if(main_plateau -> board[pos -> col - 'a'][pos -> row + 1] -> tab_pic[1] < main_plateau -> board[pos -> col - 'a'][pos -> row] -> tab_pic[2]){
            //Change the stone color
            main_plateau -> board[pos -> col - 'a'][pos -> row + 1] -> col = main_plateau -> board[pos -> col - 'a'][pos -> row] -> col;

            //update the score
            main_plateau -> color[main_plateau -> board[pos -> col - 'a'][pos -> row] -> col] += 1;
            main_plateau -> color[(1 & (~main_plateau -> board[pos -> col - 'a'][pos -> row] -> col))] -= 1;
        }
    }
    if(pos -> col -'a' < main_plateau -> size - 1){
        if(main_plateau -> board[pos -> col - 'a' + 1][pos -> row] -> tab_pic[0] < main_plateau -> board[pos -> col - 'a'][pos -> row] -> tab_pic[3]){
            //Change the stone color
            main_plateau -> board[pos -> col - 'a' + 1][pos -> row] -> col = main_plateau -> board[pos -> col - 'a'][pos -> row] -> col;

            //update the score
            main_plateau -> color[main_plateau -> board[pos -> col - 'a'][pos -> row] -> col] += 1;
            main_plateau -> color[(1 & (~main_plateau -> board[pos -> col - 'a'][pos -> row] -> col))] -= 1;
        }
    }
}

