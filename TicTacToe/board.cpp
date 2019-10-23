#include <iostream>
#include "board.h"
using namespace std;

board::board()
{
    symb='X';
    row=1;
    col='a';
    col_num=0;
    opp_move=' ';
    winner=' ';
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cells[i][j]=' ';
        }
    }
}

void board::playerSymb()
{
    cout << "Scegli X o O:  ";
    while (true) {
        cin >> symb;
        if (symb != 'X' && symb != 'O') {
            cout << "Scelta non valida! Scegli X o O:  ";
        }
        else {
            if (symb == 'X') {
                opp_symb = 'O';
            }
            else {
                opp_symb = 'X';
            }
            return;
        }
    }
}

void board::showBoard()
{
    cout << "  a   b   c  " <<endl;
    cout << "-------------" <<endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << "| " << cells[i][j] << " ";
        }
        cout << "|  " << i+1 <<endl << "-------------" <<endl;
    }
}

void board::clearBoard()
{
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cells[i][j]=' ';
        }
    }
}

void board::chooseCell()
{
    cout << "Scegli la casella in cui fare la tua mossa (indicando prima la colonna e poi la riga): \n";
    while (true) {
        cin >> col;
        cin >> row;
        if ((col=='a'||col=='b'||col=='c')&&(row==1||row==2||row==3)) {
            if (col=='a') {
                col_num=0;
            }
            else if (col=='b') {
                col_num=1;
            }
            else {
                col_num=2;
            }
            return;
        }
        else {
            cout << "Scegli una colonna (a,b,c) e una riga (1,2,3): \n";
        }
    }
}

bool board::checkEmpty()
{
    if (cells[row-1][col_num]==' ') {
        return true;
    }
    else {
        return false;
    }
}

void board::plMove()
{
    while (true) {
        chooseCell();
        if (checkEmpty()==true) {
            cells[row-1][col_num] = symb;
            return;
        }
        else {
            cout << "Scegli una casella vuota!\n";
        }
    }
}

int board::chooseMove()
{
    return 0, 1;
}

void board::oppMove()
{
    int choice[2] = {chooseMove()};
    row = choice[0];
    col_num = choice[1];
    cells[row][col_num] = opp_symb;
}

char board::checkTris()
{
    for (int i=0; i<3; i++) {
        if (cells[i][0]==cells[i][1]&&cells[i][0]==cells[i][2]&&cells[i][0]!=' ') {
            winner = cells[i][0];
            return winner;
        }
    }
    for (int j; j<3; j++) {
        if (cells[0][]==cells[1][0]&&cells[0][0]==cells[2][0]&&cells!=' ') {
            winner = cells[0][0];
            return winner;
        }
    }
    if ((cells[0][0]==cells[1][1]&&cells[0][0]==cells[2][2])||(cells[0][2]==cells[1][1]&&cells[0][2]==cells[2][0])) {
        winner = cells[0][0];
        return winner;
    }
    return ' ';
}

bool board::checkDraw()
{
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (cells[i][j]==' ') {
                return false;
            }
        }
    }
    return true;
}

int board::evaluate()
{
    char check = checkTris();
    if (check==symb) {
        return +10;
    }
    else if (check==opp_symb) {
        return -10;
    }
    else {
        return 0;
    }
}

int board::minimax(int depth, bool isMax)
{
    score = evaluate();
    if (score==10||score==-10) {
        return score;
    }
    if (checkDraw()) {
        return 0;
    }

    if (isMax) {
        int best = -1000;
    }
}
