#include "types_val.h"
#ifndef STRUCT_H
#define STRUCT_H

typedef struct Stone_{
    char col; //Blue = 0, Red = 1
    pic * tab_pic; // contains the number of spike in the order : left ; up ; down ; right
    short id;
    char element;
    char null; //0 pour une pierre non vide, 1 pour une pierre vide
}Stone;

typedef struct Board_{
    Stone *** board;
    char element;
    char * color; // color[0] = points for Blue, color[1] = points for Red
    char size;
}Board;

typedef struct Deck_{
    Stone ** tab_stones;
    char col; //Blue = 0, Red = 1
    char size;
}Deck;

typedef struct Position_{
    char col;
    char row;
}Position;


#endif