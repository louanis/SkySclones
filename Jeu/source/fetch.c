#include <stdio.h>
#include <stdlib.h>
#include "../header/struct.h"
#include "../header/fetch.h"
#include "../header/gestion_struct.h"
#include "../header/types_val.h"


//#define DEBUG_FETCH

//List of all stones


Deck * fetch_stones(void){
    FILE * f = fopen("./Jeu/data/stones.txt","r");

    int size;

    printf("----\n");fflush(stdout);
    fscanf(f,"elem: %d\n",&size);
    printf("----\n");fflush(stdout);

    int pic;

    Deck * deck = init_deck(size);

    for(int i = 0; i<size;i++){
        deck -> tab_stones[i] = init_stone();
        deck -> tab_stones[i] -> id = i;

        for(int j = 0; j<4;j++){
            fscanf(f,"%d ",&pic);
            deck -> tab_stones[i] -> tab_pic[j] = pic;
        }
        fscanf(f,"\n");
    }

    fclose(f);
    return deck;
}


void print_stone(Stone * stone){
    printf("col %d id %d elem %d null %d : [%d %d %d %d]\n",stone->col,stone->id,stone->element,stone->null,stone->tab_pic[0],stone->tab_pic[1],stone->tab_pic[2],stone->tab_pic[3]);
    return;
}




#ifdef DEBUG_FETCH

int main(){
    Deck * deck = fetch_stones();

    
    for(int i = 0; i< deck-> size; i++){
        print_stone(deck -> tab_stones[i]);
    }

    for(int i = 0; i< deck-> size; i++){
        free_stone(deck -> tab_stones[i]);
    }

    free_deck(deck);

}

#endif