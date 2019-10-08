#include <iostream>

using namespace std;

int main()
{
    int V[3][3]={2,5,6,10,23,34,21,10,8};
    int i=0;
    int j=2;
    int n1=V[0][0];
    int n2=V[0][2];
    int diff=0;
    int S=0;

    while (i<3) {
        diff=n1-n2;
        i++;
        j--;
        n1=V[i][i];
        n2=V[i][j];
        S=S+diff;
    }

    cout << "La media è: " << (S/3);
}
