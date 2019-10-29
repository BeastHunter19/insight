#include <iostream>

using namespace std;

int main()
{
    //11.4
    int somma=0;
    for (int i=1; i<100; i+=2) {
        if (i%3!=0) {
            somma+=i;
        }
    }
    cout << somma <<endl;

    //11.5
    int somma2=0;
    for (int i=1000; i>=0&&somma2<=100000; i-=2) {
        somma2+=i;
        cout << i << " ";
    }
    return 0;
}
