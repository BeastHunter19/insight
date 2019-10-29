#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    //1.
    string name, surname;
    cout << "Inserisci il tuo nome: "; cin >> name;
    cout << "Inserisci il tuo cognome: "; cin >> surname;
    cout << "Il primo carattere del nome è: " << name[0] << ", l'ultimo: " << name[name.length()-1] <<endl;
    cout << "Il secondo carattere del cognome è: " << surname[1] << ", il terzo: " << surname[2] <<endl;

    //2.
    string both="", aux="";
    for (int i=0; i<name.length(); i++) {
        for (int j=0; j<surname.length(); j++) {
            if (name[i]==surname[j]&&(any_of(both[0], both[both.length()-1], name[i]))) {
                both+=name[i];
            }
        }
    }
    cout << "I caratteri in comune sono: " << both <<endl;

    //3.
    int counter_n=0, counter_s=0;
    if (name[0]==surname[surname.length()-1]) {
        cout << "La prima lettera del nome è uguale all'ultima del cognome!" <<endl;
    }
    if (name.length()==surname.length()) {
        cout << "Il nome e il cognome hanno la stessa lunghezza" <<endl;
    }

    for (int i=0; i<name.length(); i++) {
        switch (name[i])
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                break;
            default:
                counter_n++;
        }
    }
    for (int i=0; i<surname.length(); i++) {
        switch (surname[i])
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                break;
            default:
                counter_s++;
        }
    }
    cout << "Il numero di consonanti nel nome è: " << counter_n <<", nel cognome: " << counter_s <<endl;
    return 0;
}
