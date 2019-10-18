#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

string username;
ifstream record_i ("record.txt");
int record;

string opponent_move()             //genera casualmente la mossa del PC
{
    int opp_move;
    srand (time(NULL));
    opp_move = rand() % 3;
    switch (opp_move) {
        case 0: return "Sasso";
        case 1: return "Carta";
        default: return "Forbici";
    }
}

string player_move()               //chiede al giocatore di fare una mossa
{
    int move_choice;
    cout << "Inserisci il numero corrispondente alla tua scelta: \n1) Sasso\n2) Carta\n3) Forbici" <<endl;
    do {
        cin >> move_choice;
        switch (move_choice) {
            case 1: return "Sasso";
            case 2: return "Carta";
            case 3: return "Forbici";
            default: cout << "Scegli un numero da 1 a 3!" <<endl;
        }
    } while (true);

}

string ask_username()              //chiede al giocatore il suo nome
{
    string name;
    cout << "Inserisci il tuo nome:   "; cin >> name;
    cout <<endl <<"Benvenuto " << name << "!" <<endl;
    return name;
}

string check(string move1, string move2)       //stabilisce se il giocatore 1 ha vinto, pareggiato o perso
{
    if (move1 == "Sasso") {
        if (move2 == "Forbici") {
            return "Vittoria";
        }
        else if (move2 == "Sasso") {
            return "Pareggio";
        }
        else {
            return "Sconfitta";
        }
    }
    else if (move1 == "Carta") {
        if (move2 == "Sasso") {
            return "Vittoria";
        }
        else if (move2 == "Carta") {
            return "Pareggio";
        }
        else {
            return "Sconfitta";
        }
    }
    else {
        if (move2 == "Carta") {
            return "Vittoria";
        }
        else if (move2 == "Forbici") {
            return "Pareggio";
        }
        else {
            return "Sconfitta";
        }
    }
}

void start_game()                //fa iniziare una partita
{
    int lives=3, score=0;
    string result;
    string opp_move, pl_move;
    cout << "Hai a disposizione 3 vite.\nSe le finisci la partita terminerà." <<endl <<endl;
    while (lives > 0) {
        pl_move = player_move();             //esegue mosse
        opp_move = opponent_move();
        cout <<endl << username << ": " << pl_move << " ---------- " << "PC: " << opp_move <<endl;
        result = check(pl_move, opp_move);      //verifica il risultato
        if (result == "Vittoria") {
            score++;
            cout << "Hai vinto!       Punteggio: " << score << "    Vite: " << lives <<endl <<endl;
        }
        else if (result == "Pareggio") {
            cout << "Pareggio.        Punteggio: " << score << "    Vite: " << lives <<endl <<endl;
        }
        else {
            lives--;
            cout << "Hai perso...     Punteggio: " << score << "    Vite: " << lives <<endl <<endl;
        }
    }
    cout << "GAME OVER" <<endl << "Hai totalizzato " << score << " punti!" <<endl;          //punteggio,   aggiungere sistema di record personale
    ofstream record_o ("record.txt");
    record_o << score;
    record_i >> record;
    cout << "Adesso tornerai al menu iniziale." <<endl <<endl;
}

int main()
{
    if (!record_i) {
        ofstream record_o ("record.txt");
        record_o << 0;
    }
    int menu_choice;
    username = ask_username();
    do {
        record_i >> record;
        cout <<endl << "Scegli cosa fare:\n1) Inizia partita (Record: " << record << ")\n2) Cambia utente\n3) Esci dal gioco" <<endl;
        cin >> menu_choice;       //scelta dell'utente
        switch (menu_choice) {
            case 1:
                start_game();                                    //fa iniziare una nuova partita
                break;
            case 2:
                cout << "Arrivederci " << username << "!" <<endl;      //cambia utente
                username = ask_username();
                break;
            case 3:
                cout << "Alla prossima, " << username << "!";              //esci dal gioco
                return 0;
            default: cout << "Scelta non valida!" <<endl;               //errore
        }
    } while (true);
}
