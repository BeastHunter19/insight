#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>
#include <cmath>
#include <random>
using namespace std;

/*Il programma permette di partecipare
ad una partita di battaglia navale contro
il computer, eventualmente caricando una
sessione precedente da file*/

int main()
{
    string name;        //nome giocatore
    int n, m;           //dimensioni campo di gara
    int min, max;       //dimensioni navi

    cout << "Inserisci il tuo nome: "; cin >> name;
    if (cin.fail()) {
        cerr << "Inserisci un nome!";
        return -1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << name <<endl;

    cout << "Inserisci le dimensioni del campo di gara (righe colonne): "; cin >> n >> m;
    if (cin.fail()) {
        cerr << "Inserisci numeri interi!";
        return -1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << n << " "  << m <<endl;

    cout << "Inserisci le dimensioni delle navi (minime massime): "; cin >> min >> max;
    if (cin.fail()) {
        cerr << "Inserisci numeri interi!";
        return -1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (min>=max) {
        cerr << "La dimensione massima dovrebbe essere maggiore della minima!";
        return -1;
    }
    cout << min << " " << max <<endl;

    //inizializza gli array necessari allo svolgimento del gioco
    char pl_board[n][m];
    char opp_board[n][m];
    char pl_moves[n][m];
    char opp_moves[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            pl_board[i][j]=' ';
            opp_board[i][j]=' ';
            pl_moves[i][j]=' ';
            opp_moves[i][j]=' ';
        }
    }
    //inizializza variabili relative alle navi
    int ship_length;
    int ship_row;
    int ship_col;
    int ship_dir;
    bool dir_loop = true;
    int max_ships = 5;   //numero massimo di navi da disporre
    int ships = 0;      //contatore per il numero di navi
    int ship_counter = 0;
    random_device seed;
    uniform_int_distribution<int> length(min, max);
    uniform_int_distribution<int> row(0, n);
    uniform_int_distribution<int> col(0, m);
    uniform_int_distribution<int> dir(0, 1);

    //piazza le navi sul campo del giocatore
    while (ships<max_ships) {
        ship_length = length(seed);
        while (dir_loop) {
            ship_row = row(seed);
            ship_col = col(seed);
            ship_dir = dir(seed);    //0=orizzontale   1=verticale
            if (ship_dir==0) {
                if (pl_board[ship_row][ship_col-1]!='A' && pl_board[ship_row][ship_col+ship_length+1]!='A') {
                    for (int i=0; i<ship_length; i++) {
                        if (pl_board[ship_row][ship_col+i]!='A' && pl_board[ship_row+1][ship_col+i]!='A' && pl_board[ship_row-1][ship_col+i]!='A') {
                            ship_counter++;
                        }
                    }
                }
                if (ship_counter==ship_length) {
                    dir_loop = false;
                    for (int i=0; i<ship_length; i++) {
                        pl_board[ship_row][ship_col+i]='A';
                    }
                }
            }
            else {
                if (pl_board[ship_row-1][ship_col]!='A' && pl_board[ship_row+ship_length+1][ship_col]!='A') {
                    for (int i=0; i<ship_length; i++) {
                        if (pl_board[ship_row+i][ship_col]!='A' && pl_board[ship_row+i][ship_col+1]!='A' && pl_board[ship_row+i][ship_col-1]!='A') {
                            ship_counter++;
                        }
                    }
                }
                if (ship_counter==ship_length) {
                    dir_loop = false;
                    for (int i=0; i<ship_length; i++) {
                        pl_board[ship_row+i][ship_col]='A';
                    }
                }
            }
            ship_counter = 0;
        }
        dir_loop = true;
        ships++;
    }


    //stampa il campo del giocatore a schermo
    cout << " ";
    for (int i=0; i<(4*m-1); i++) {
        cout << "-";
    }
    cout <<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << "| " << pl_board[i][j] << " ";
        }
        cout << "|" <<endl;
        cout << " ";
        for (int i=0; i<(4*m-1); i++) {
            cout << "-";
        }
        cout <<endl;
    }
}
