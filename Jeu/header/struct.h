#include "types_val.h"
#ifndef STRUCT_H
#define STRUCT_H

typedef struct Stone_{
    char col; //Blue = 0, Red = 1
    pic * tab_pic; //Contient la quantité de pic pour chaque face, l'ordre de lecture n'est pas determiné et dependra du layout de Board
    short id;
    char element;
    char null;
}Stone;

typedef struct Board_{
    Stone *** board;
    char element;
    char red;
    char blue;
}Board;

typedef struct Deck_{
    Stone ** tab_stones;
    char col; //Blue = 0, Red = 1
}Deck;


#endif