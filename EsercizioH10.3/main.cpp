#include <iostream>
using namespace std;

int main()
{
    string s1, s2, s3, mys="";
    cout << "Inserisci s1:  "; cin >> s1;
    cout << "Inserisci s2:  "; cin >> s2;
    cout << "Inserisci s3:  "; cin >> s3;

    if (s1.length()>10||s2.length()>10||s3.length()>10) {
        if (s1.length()>=20||s2.length()>=20||s3.length()>=20) {
            mys += s2[0]+s2[1]+s2[2]+s3[s3.length()-1]+s3[s3.length()-2]+s3[s3.length()-3];
            cout << "If A+B: mys= " << mys <<endl;
        }
        else {
            mys = s1+s2+s3;
            cout << "If A: mys= " << mys <<endl;
        }
    }
    else {
        int somma = s1.length() + s2.length() + s3.length();
        cout << "La somma delle lunghezze è: " << somma <<endl;
    }
}
