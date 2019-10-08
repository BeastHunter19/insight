#include <iostream>

using namespace std;

//Il programma stampa i primi n numeri pari e i successivi m numeri dispari

int main()
{
    int n;
    cout << "Inserisci la quantità di numeri pari da stampare: " <<endl; cin >> n;
    cout <<endl;
    int m;
    cout << "Inserisci la quantità di numeri dispari da stampare: " <<endl; cin >> m;
    cout <<endl;

    int i=0;
    int S=0;

    while (i<n+m) {
        cout << S <<endl;
        i++;
        S+=2;
        if (i==n) {
            S--;
        }
    }
}
