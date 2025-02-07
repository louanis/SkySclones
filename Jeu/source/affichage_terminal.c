#include "../header/all.h"

void affiche_deck(Deck * deck){
    printf("\n");
    int i;
    for(i = 0; i<deck -> size; i++){
        if(deck -> tab_stones[i]->null!= 0){
            continue;
        }
        printf("  %d  ",deck -> tab_stones[i] -> tab_pic[1]);
    }
    printf("\n");
    for(i = 0; i<deck -> size; i++){
        if(deck -> tab_stones[i]->null!= 0){
            continue;
        }
        printf(" %d %d ",deck -> tab_stones[i] -> tab_pic[0],deck -> tab_stones[i] -> tab_pic[3]);
    }
    printf("\n");
    for(i = 0; i<deck -> size; i++){
        if(deck -> tab_stones[i]->null!= 0){
            continue;
        }
        printf("  %d  ",deck -> tab_stones[i] -> tab_pic[2]);
    }
    printf("\n");

    return;
}

void affiche_board(Board * board){
    int i,j;

    printf("%d",board -> board[0][2] -> null);
    printf("\n");
    for(i = 0;i<board -> size;i++){
        for(j = 0;j<board -> size;j++){
            if(board -> board[j][i] -> null != 0){
                printf("       ");
                continue;
            }
            printf("   %d   ",board -> board[j][i]->tab_pic[1]);
        }
        printf("\n");
        for(j = 0;j<board -> size;j++){
            if(board -> board[j][i] -> null!= 0){
                printf("   x   ");
                continue;
            }
            printf(" %d %d %d ",board -> board[j][i]->tab_pic[0],board -> board[j][i] -> col,board -> board[j][i]->tab_pic[3]);
        }
        printf("\n");
        for(j = 0;j<board -> size;j++){
            if(board -> board[j][i] -> null!= 0){
                printf("       ");
                continue;
            }
            printf("   %d   ",board -> board[j][i]->tab_pic[2]);
        }
        printf("\n\n");
    }
}