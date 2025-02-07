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

void remplir_deck(Deck * all_stones, Deck * deck){
    int * tab = (int *) malloc(sizeof(int) * deck -> size);
    int fini = 0;
    while(fini <deck -> size){
        fini++;
    }
}

void tour(Board * board, Deck * deck){
    int choix = 0;
    char choix_char;
    int id_stone;

    printf("Se tromper dans les inputs sont a vos risques et perils, si vous avez le malheur d'ecrire un input qui n'est pas proposé, vous perdez votre tour");
    //CHOISIR ACTION
    choisir_action:
    while(1){
        printf("Que souhaitez vous faire ?\n");
        printf("Jouer une Stone : 1 , Voir Deck : 2 , Voir plateau : 3\n");
        scanf("%d",&choix);
        if(choix == 1){
            break;
        }else if(choix == 2){
            affiche_deck(deck);
        }else if(choix == 3){
            affiche_board(board);
        }else{
            continue;
        }
    }

    //Choisir stone
    choix_stone:
    while(1){
        printf("Donne moi la position dans le deck (en partant de 0) de la Stone que tu veux jouer?\n");
        printf("Retourner en arrière : -1\n");
        scanf("%d",&choix);
        if(choix == -1){
            goto choisir_action;
        }else if(choix >= deck -> size){
            continue;
        }else{
            id_stone = choix;
            break;
        }
    }

    //Demander Position
    while(1){
        printf("Donne moi la case ou tu veux poser ta Stone\n");
        printf("Retourner en arrière : -1X\n");
        scanf("%d%c",&choix,&choix_char);
        if(choix_char == 'X' && choix == -1){
            goto choix_stone;
        }else{
            if(choix_char - 'a' >= board -> size || choix >= board -> size){
            continue;
            }
            *board -> board[choix_char-'a'][choix] = *deck -> tab_stones[id_stone];
            break;
        }

    }
    affiche_board(board);
}

