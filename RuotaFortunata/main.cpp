#include <iostream>
#include <limits>

#include "ruota.h"

using namespace std;

int main()
{
    //elementi delle tre ruote (1-5 standard; 7,8,9 jolly)
    int elementi1[7] = {1,2,3,4,5, 7,8};
    int elementi2[6] = {1,2,3,4,5, 7};
    int elementi3[8] = {1,2,3,4,5, 7,8,9};

    //oggetti ruota
    RuotaFortunata ruota1 = RuotaFortunata(7, elementi1);
    RuotaFortunata ruota2 = RuotaFortunata(6, elementi2);
    RuotaFortunata ruota3 = RuotaFortunata(8, elementi3);

    //input numero di lanci
    int lanci;
    cout << "Inserisci il numero di lanci che vuoi effettuare: "; cin >> lanci;
    if (cin.fail()) {
        cerr << "Inserisci un numero intero positivo!";
        return -1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //iterazione per effettuare i lanci
    unsigned punteggio = 0;
    int valore1, valore2, valore3;

    for(int i=0; i<lanci; i++) {
        //gira le tre ruote
        ruota1.gira();
        ruota2.gira();
        ruota3.gira();

        valore1 = ruota1.getValoreCorrente();
        valore2 = ruota2.getValoreCorrente();
        valore3 = ruota3.getValoreCorrente();

        //stampa i risultati dei lanci
        cout << endl << "Lancio " << i+1 << ":  " << valore1 << "     " << valore2 << "     " << valore3 << endl;

        //verifica eventuale vittoria
        if (valore2==valore1+1 && valore3==valore2+1)
            punteggio += 10;
        else if (valore1==7 && valore2==7 && valore3==7)
            punteggio += 500;
        else if ((valore1==7||valore1==8)&&(valore2==7)&&(valore3==7||valore3==8||valore3==9))
            punteggio += 100;

        //stampa risultato
        if (i == lanci-1)
            cout << "Risultato finale:   " << punteggio << endl << endl;
        else
            cout << "Risultato parziale:   " << punteggio << endl;
    }
}
