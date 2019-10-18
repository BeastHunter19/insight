#include <iostream>
#include "board.h"

board::board()
{
    player='X';
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board::cells[i][j]=0;
        }
    }
}

void board::makeMove() {
    
}