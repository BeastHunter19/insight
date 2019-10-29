#include <iostream>

using namespace std;

bool check(double w1, int A1[k1][n1][n1])
{
    int max, min;
    double average;
    for (int i=0; i<k1; i++) {
        min = A1[i][0][0];
        max = A1[i][0][0];
        for (int j=1; j<n1; j++) {
            if (A1[i][j][j]<min) {
                min = A1[i][j][j];
            }
            if (A1[i][j][j]>max) {
                max = A1[i][j][j];
            }
        }
        average = (max+min)/2;
        if (average<=w1) {
            return true;
        }
    }
    return false;
}

int main()
{
    int k, n;
    double w;
    cout << "Inizializzazione array A di dimensione k x n x n:\n";
    cout << "Inserisci k: "; cin >> k;
    cout << "Inserisci n: "; cin >> n;
    int A[k][n][n];
    cout << "Inserisci il valore massimo di w: "; cin >> w;

    srand(time(NULL));
    for (int i=0; i<k; i++) {
        for (int j=0; j<n; j++) {
            for (int t=0; t<n; t++) {
                A[i][j][t] = rand()%10;
            }
        }
    }

    for (int i=0; i<k; i++) {
        for (int j=0; j<n; j++) {
            for (int t=0; t<n; t++) {
                cout << A[i][j][t] << " ";
            }
            cout <<endl;
        }
        cout <<endl <<endl;
    }

    if (check(w, A)) {
        cout << "True";
    }
    else {
        cout << "False";
    }
    return 0;
}
