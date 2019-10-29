#include <iostream>
#include "board.h"
using namespace std;

board::board()
{
    symb='X';
    row=-1;
    col='a';
    col_num=-1;
    opp_move=' ';
    winner=' ';
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cells[i][j]=' ';
        }
    }
    cells[0][2]='X';
    cells[1][2]='X';
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
    int score = evaluate();
    if (score==10||score==-10) {
        return score;
    }
    if (checkDraw()) {
        return 0;
    }

    if (isMax) {
        int best = -1000;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (cells[i][j]==' ') {
                    cells[i][j] = symb;
                    best = max(best, minimax(depth+1, !isMax))-depth;
                    cells[i][j] = ' ';
                }
            }
        }
        return best;
    }
    else {
        int best = 1000;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (cells[i][j]==' ') {
                    cells[i][j] = opp_symb;
                    best = min(best, minimax(depth+1, !isMax))+depth;
                    cells[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

int board::chooseMove()
{
    int best_val = 1000;
    int best_move[2] = {-1, -1};
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (cells[i][j]==' ') {
                cells[i][j] = opp_symb;
                int move_val = minimax(0, false);
                cells[i][j] = ' ';
                if (move_val<best_val) {
                    best_move[0] = i;
                    best_move[1] = j;
                    best_val = move_val;
                }
            }
        }
    }
    return best_move[0], best_move[1];
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
            return cells[i][0];
        }
    }
    for (int j; j<3; j++) {
        if (cells[0][j]==cells[1][j]&&cells[0][j]==cells[2][j]&&cells[0][j]!=' ') {
            return cells[0][j];
        }
    }
    if (((cells[0][0]==cells[1][1]&&cells[0][0]==cells[2][2])||(cells[0][2]==cells[1][1]&&cells[0][2]==cells[2][0]))&&cells[1][1]!=' ') {
        return cells[1][1];
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

void board::game()
{
    char turn = 'X';
    playerSymb();
    showBoard();
    cout << "Inizia il giocatore X. \n";
    while (true) {
        if (turn==symb) {
            cout << "Tocca a te: \n";
            plMove();
            showBoard();
            winner = checkTris();
            if (winner==symb) {
                cout << "Hai vinto!\n";
                return;
            }
            else {
                if (checkDraw()) {
                    cout << "Pareggio.\n";
                    return;
                }
            }
            turn = opp_symb;
        }
        else {
            oppMove();
            showBoard();
            winner = checkTris();
            if (winner==opp_symb) {
                cout << "Hai perso...\n";
                return;
            }
            else {
                if (checkDraw()) {
                    cout << "Pareggio.\n";
                    return;
                }
            }
            turn = symb;
        }
    }
    clearBoard();
    showBoard();
}
