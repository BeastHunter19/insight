#include <iostream>

#include "Matrice3D.h"

using namespace std;

int main()
{
    Matrice3D m1(3,3,2,2);
    m1 = m1.prodottoScalare(3);
    m1.stampa();
    return 0;
}
