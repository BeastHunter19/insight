#include <iostream>
#include <random>
using namespace std;

int main()
{
    float N, M;
    cout << "Inserisci N ed M maggiori di 1: " <<endl;
    if (!(cin >> N >> M)) {
        cerr << "Inserisci due numeri!" <<endl;
        return -1;
    }
    if (N<=1 || M<=1) {
        cerr << "I numeri devono essere maggiori di 1!" <<endl;
        return -1;
    }

    int n=N+0.5, m=M+0.5;
    float A[n][m];
    float l;
    random_device seed;
    uniform_real_distribution <float> num (1, 10);
    //inizializza
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            A[i][j]=num(seed);
        }
    }
    //stampa
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << A[i][j] << " ";
        }
        cout <<endl;
    }
    cout <<endl;

    //moltiplica e stampa
    l=num(seed);
    cout << l <<endl <<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << A[i][j]*l << " ";
        }
        cout <<endl;
    }
    cout <<endl <<endl;

    //matrice NxN
    int s = min(n, m);
    float B[s][s];
    for (int i=0; i<s; i++) {
        for (int j=0; j<s; j++) {
            B[i][j]=A[i][j];
        }
    }

    //stampa
    for (int i=0; i<s; i++) {
        for (int j=0; j<s; j++) {
            cout << B[i][j] << " ";
        }
        cout <<endl;
    }
    cout <<endl;
}
