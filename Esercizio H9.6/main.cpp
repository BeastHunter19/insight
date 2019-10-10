#include <iostream>

using namespace std;

int main()
{
    int N, M;                                                                                   //creazione matrice e array
    cout << "Inserisci il numero di righe della matrice: "; cin >> N;
    cout << "Inserisci il numero di colonne della matrice: "; cin >> M; cout <<endl;
    int V[N][M];
    int W[M];
    cout << "Inserisci gli elementi della matrice:" <<endl;
    int j=0, i=0;
    while (j<N) {
        while (i<M) {
            cin >> V[j][i];
            i++;
        }
        j++;
        i=0;
    }
    int s, z;                                                                                   //input ulteriori parametri
    cout << "Inserisci la lunghezza massima della sequenza di numeri adiacenti: "; cin >> z;
    if (z>N) {
        z=N;
    }
    cout << "Inserisci la somma minima dei numeri delle sequenze: "; cin >> s;
    j=0; i=0;                                                                                   //azzeramento variabili e variabili aggiuntive
    int n=0, m=0, t=0;

    while (i<M) {                                                                               //lettura matrice e creazione array
        while (j<N) {
            while (n<z) {
                if ((j+n)<N) {
                    m=m+V[j+n][i];
                }
                n++;
            }
            if (m>=s) {
                t++;
            }
            j++;
            n=0;
            m=0;
        }
        if (t>0) {
            W[i]=1;
        }
        else {
            W[i]=0;
        }
        i++;
        j=0; t=0;
    }

    i=0; j=0;                                                                                   //stampa matrice
    cout << "Matrice: " <<endl;
    while (j<N) {
        while (i<M) {
            cout << V[j][i] << " ";
            i++;
        }
        cout <<endl;
        j++;
        i=0;
    }

    cout << "Array: " <<endl;                                                                   //stampa array di output per verifica
    while (i<M) {
        cout << W[i] << " ";
        i++;
    }
}
