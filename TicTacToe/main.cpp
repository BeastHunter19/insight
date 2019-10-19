#include <iostream>
#include "board.h"
using namespace std;

int main()
{
    board spboard;
    spboard.playerSymb();
    spboard.showBoard();
    spboard.plMove();
    spboard.showBoard();
    spboard.oppMove();
    spboard.showBoard();
}
