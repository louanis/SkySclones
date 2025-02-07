#include "../header/all.h"


#define DEBUG_FETCH

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
        deck -> tab_stones[i] -> null = 0;

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
    srand(time(NULL)+rand());
    char SIZE = 3;
    int i,j;

    Deck * deck = fetch_stones();
    Board * board = init_board(SIZE);

    
    for(i = 0; i< deck-> size; i++){
        print_stone(deck -> tab_stones[i]);
    }

    for(i = 0; i<SIZE;i++){
        
        for(j = 0; j<SIZE;j++){
            
        }
    }


    *board -> board[2][0] = *deck -> tab_stones[rand()%3];

    affiche_board(board);

    Deck * deck2 = init_deck(5);

    copy_stone(deck2 -> tab_stones[1],deck -> tab_stones[deck->size - 1]);

    printf("--------\n");

    print_stone(deck2 -> tab_stones[1]);

    for(i = 0; i< deck-> size; i++){
        free_stone(deck -> tab_stones[i]);
    }

    printf("--------\n");

    print_stone(deck2 -> tab_stones[1]);

    for(i = 0; i< deck2-> size; i++){
        free_stone(deck2 -> tab_stones[i]);
    }
    
    free_board(board);
    free_deck(deck2);
    free_deck(deck);

}

#endif