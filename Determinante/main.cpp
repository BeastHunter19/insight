#include <iostream>
#include <cmath>

using namespace std;

int new_matrix(unsigned index, unsigned m1, int *C)
{
    int D[m1-1][m1-1];
    for (unsigned i = 0; i<m1; i++) {
        for (unsigned j=0; j<m1; j++) {
            unsigned j1=j;
            if (j!=index) {
                D[i][j] = *C[i+1][j1];
            }
            else {
                j1++;
            }
        }
    }
    return D;
}

int determinante(unsigned m, int *B)
{
    if (m==1) {
        return *B[0][0];
    }
    else if (m==2) {
        int det = (B[0][0]*B[1][1])-(B[1][0]*B[0][1]);
        return det;
    }
    else {
        int somma = 0;
        int det2=0;
        int matrice_ridotta[m-1][m-1];
        for (unsigned i=0; i<m; i++) {
            matrice_ridotta=new_matrix(i, m, B)
            det2
            somma+=B[0][i]*pow(-1, 2+i)*det2;
        }
    }
}

int main()
{
    unsigned n;
    int A[n][n];
    cout << "Numero righe e colonne: "; cin >> n;
    return 0;
}
