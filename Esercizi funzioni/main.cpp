#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int main()
{
    double a=1.3, b=2.4;
    cout << "sum = " << sum(a, b) <<endl;

    cout << "rapp = " << rapp(5, 2) <<endl;
    cout << "rapp2 = " << rapp(4, 0);

    double v1[3] = {1.5, 3.4, 5.6};
    cout << "sum_array = " << sum_array(v1, 3) <<endl;

    unsigned v2[3] = {2, 5, 7};
    cout << "average = " << average(v2, 3) <<endl;

    char v3[5] = {'a', 'c', 'd', 'u', 'f'};
    cout << "vowels = " << vowels(v3, 5) <<endl;

    char v4[4] = {'b', 'a', 'c', 's'};
    cout << "last_consonant = " << last_consonant(v4, 4) <<endl;

    char v5[4] = {'c', 'a', 'd', 'e'};
    char *ptr = pointer(v5, 4);
    cout << "pointer = " << ptr << "  value = " << *ptr <<endl;

    unsigned v6[5] = {0, 2, 5, 3, 4};
    exchange(v6, 5);
    for (int i=0; i<5; i++) {
        cout << v6[i] << " ";
    }
    cout <<endl;

    unsigned v7[5] = {0, 1, 2, 3, 4};
    invert(v7, 5);
    for (int i=0; i<5; i++) {
        cout << v7[i] << " ";
    }
    cout <<endl;

    short v8[4] = {1, 3, 5, 10};
    short v9[4] = {2, 1, 7, 0};
    short *v10 = max_array(v8, v9, 4);
    for (int i=0; i<4; i++) {
        cout << v10[i] << " ";
    }
    cout <<endl;

    short p=0;
    char v11[4] = {'a', 'b', 'c', 'o'};
    char *v12 = vowels_array(v11, 4, &p);
    for (int i=0; i<5; i++) {
        cout << v12[i] << " ";
    }
    cout <<endl;

    string s[3] = {"za warudo", "bites za dusto", "yare yare daze"};
    char c[5] = {'a', 'y', 'z', 'd', 'f'};
    cout << "chars_in_strings = " << chars_in_strings(s, 3, c, 5, 5) <<endl;
}
