#include <iostream>

using namespace std;

int main()
{
    int x;
    cout << "Inserisci x: "; cin >> x;
    int y;
    cout << "Inserisci y: "; cin >> y;
    int z;
    cout << "Inserisci z: "; cin >> z;
    cout <<endl
    int n;

    if (x<y) {
        n=x;
    }
    else {
        n=y;
    }

    if (n<z) {
        cout << "Il minore è: " << n;
    }
    else {
        cout << "Il minore è: " << z;
    }
}
