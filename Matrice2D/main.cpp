#include <iostream>
#include "Matrice2D.h"

using namespace std;

int main()
{
    Matrice2D m1(4,4);
    m1.riempiRandom(0, 10);
    m1.stampa();
    cout << m1.determinante();
    return 0;
}
