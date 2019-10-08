#include <iostream>

using namespace std;

int main()
{
    int num=0;
    cout << "Inserisci un numero: "; cin>>noskipws>>num;
    if (!(cin >> num)) {
        cout << "ok";
    }
    else {
        cout << num;
    }

}
