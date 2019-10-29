#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float p;
    cout << "Inserisci un qualunque numero p maggiore o uguale a 1:  ";
    cin >> p;
    if (cin.fail()) {
        cerr << "Espressione non valida!" <<endl;
        cin.clear();
    }
    if (p<1.0) {
        cerr << "p deve essere maggiore o uguale a 1!" <<endl;
        cin.clear();
    }
    else {
        int n = p + 0.5;
        cout << n <<endl;
        int A[n];  //for
        int B[n];  //while
        int C[n];  //do-while

        //ciclo FOR
        for (int i=0; i<n; i++) {
            A[i]=pow(2, i);
        }
        //ciclo WHILE
        int j=0;
        srand(time(NULL));
        while (j<n) {
            B[j]=rand()%10;
            j++;
        }
        //ciclo DO-WHILE
        int k=0;
        do {
            C[k]=5*k;
            k++;
        } while (k<n);

        //stampa
        cout << "A:   ";
        for (int i=0; i<n; i++) {
            cout << A[i] << " ";
        }
        cout <<endl;

        cout << "B:   ";
        for (int i=0; i<n; i++) {
            cout << B[i] << " ";
        }
        cout <<endl;

        cout << "C:   ";
        for (int i=0; i<n; i++) {
            cout << C[i] << " ";
        }
        cout <<endl;
    }
    return 0;
}
