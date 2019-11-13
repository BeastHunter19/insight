#include <iostream>
#include <string>
#include <limits>
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
    int max_ships;  //numero massimo di navi da disporre

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

    cout << "Inserisci il numero di navi per ogni giocatore: "; cin >> max_ships;
    if (cin.fail()) {
        cerr << "Inserisci un numero intero!";
        return -1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
    int ships = 0;      //contatore per il numero di navi
    int ship_counter = 0;
    char ship_char = 'A';
    random_device seed;
    uniform_int_distribution<int> length(min, max);
    uniform_int_distribution<int> row(0, n);
    uniform_int_distribution<int> col(0, m);
    uniform_int_distribution<int> dir(0, 1);

    //piazza le navi sul campo dell'avversario
    while (ships<max_ships) {
        ship_length = length(seed);
        while (dir_loop) {
            ship_row = row(seed);
            ship_col = col(seed);
            ship_dir = dir(seed);    //0=orizzontale   1=verticale
            if (ship_dir==0) {
                if ((opp_board[ship_row][ship_col-1]==' '||ship_col==0) && (opp_board[ship_row][ship_col+ship_length]==' '||ship_col+ship_length==m)) {
                    for (int i=0; i<ship_length; i++) {
                        if (!(i!=ship_length-1 && ship_col+i==m-1)) {
                            if (opp_board[ship_row][ship_col+i]==' ' && opp_board[ship_row+1][ship_col+i]==' ' && opp_board[ship_row-1][ship_col+i]==' ') {
                                ship_counter++;
                            }
                            else if (ship_row==0 && opp_board[ship_row+1][ship_col+i]==' ') {
                                ship_counter++;
                            }
                            else if (ship_row==(m-1) && opp_board[ship_row-1][ship_col+i]==' ') {
                                ship_counter++;
                            }
                        }
                    }
                }
                if (ship_counter==ship_length) {
                    dir_loop = false;
                    for (int i=0; i<ship_length; i++) {
                        opp_board[ship_row][ship_col+i]=ship_char;
                    }
                    ship_char++;
                }
            }
            else {
                if ((opp_board[ship_row-1][ship_col]==' '||ship_row==0) && (opp_board[ship_row+ship_length][ship_col]==' '||ship_row+ship_length==n)) {
                    for (int i=0; i<ship_length; i++) {
                        if (opp_board[ship_row+i][ship_col]==' ' && opp_board[ship_row+i][ship_col+1]==' ' && opp_board[ship_row+i][ship_col-1]==' ') {
                            ship_counter++;
                        }
                        else if (ship_col==0 && opp_board[ship_row+i][ship_col+1]==' ') {
                            ship_counter++;
                        }
                        else if (ship_col==(m-1) && opp_board[ship_row+i][ship_col-1]==' ') {
                            ship_counter++;
                        }
                    }
                }
                if (ship_counter==ship_length) {
                    dir_loop = false;
                    for (int i=0; i<ship_length; i++) {
                        opp_board[ship_row+i][ship_col]=ship_char;
                    }
                    ship_char++;
                }
            }
            ship_counter = 0;
        }
        dir_loop = true;
        ships++;
    }

    ships = 0;
    ship_counter = 0;
    ship_char = 'A';

    //piazza le navi sul campo del giocatore
    while (ships<max_ships) {
        ship_length = length(seed);
        while (dir_loop) {
            ship_row = row(seed);
            ship_col = col(seed);
            ship_dir = dir(seed);    //0=orizzontale   1=verticale
            if (ship_dir==0) {
                if ((pl_board[ship_row][ship_col-1]==' '||ship_col==0) && (pl_board[ship_row][ship_col+ship_length]==' '||ship_col+ship_length==m)) {
                    for (int i=0; i<ship_length; i++) {
                        if (!(i!=ship_length-1 && ship_col+i==m-1)) {
                            if (pl_board[ship_row][ship_col+i]==' ' && pl_board[ship_row+1][ship_col+i]==' ' && pl_board[ship_row-1][ship_col+i]==' ') {
                                ship_counter++;
                            }
                            else if (ship_row==0 && pl_board[ship_row+1][ship_col+i]==' ') {
                                ship_counter++;
                            }
                            else if (ship_row==(m-1) && pl_board[ship_row-1][ship_col+i]==' ') {
                                ship_counter++;
                            }
                        }
                    }
                }
                if (ship_counter==ship_length) {
                    dir_loop = false;
                    for (int i=0; i<ship_length; i++) {
                        pl_board[ship_row][ship_col+i]=ship_char;
                    }
                    ship_char++;
                }
            }
            else {
                if ((pl_board[ship_row-1][ship_col]==' '||ship_row==0) && (pl_board[ship_row+ship_length][ship_col]==' '||ship_row+ship_length==n)) {
                    for (int i=0; i<ship_length; i++) {
                        if (pl_board[ship_row+i][ship_col]==' ' && pl_board[ship_row+i][ship_col+1]==' ' && pl_board[ship_row+i][ship_col-1]==' ') {
                            ship_counter++;
                        }
                        else if (ship_col==0 && pl_board[ship_row+i][ship_col+1]==' ') {
                            ship_counter++;
                        }
                        else if (ship_col==(m-1) && pl_board[ship_row+i][ship_col-1]==' ') {
                            ship_counter++;
                        }
                    }
                }
                if (ship_counter==ship_length) {
                    dir_loop = false;
                    for (int i=0; i<ship_length; i++) {
                        pl_board[ship_row+i][ship_col]=ship_char;
                    }
                    ship_char++;
                }
            }
            ship_counter = 0;
        }
        dir_loop = true;
        ships++;
    }

    //stampa il campo dell'avversario a schermo
    cout << " ";
    for (int i=0; i<(4*m-1); i++) {
        cout << "-";
    }
    cout <<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << "| " << opp_board[i][j] << " ";
        }
        cout << "|" <<endl;
        cout << " ";
        for (int i=0; i<(4*m-1); i++) {
            cout << "-";
        }
        cout <<endl;
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

    //inizia partita
    int opp_ships=max_ships, pl_ships=max_ships;
    int turn=dir(seed);      //0 = turno del giocatore     1 = turno dell'avversario

    do {
        if (turn==0) {       //mossa del giocatore
            do {
                cout << "Scegli dove colpire (riga colonna): "; cin >> ship_row >> ship_col;
                if (cin.fail()) {
                    cerr << "Inserisci coordinate valide!" <<endl;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (cin.fail());
            cin.clear();
            
        }
        else {               //mossa dell'avversario

        }
    } (pl_ships>0 && opp_ships>0);
}
