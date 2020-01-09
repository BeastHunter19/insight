#include <iostream>
#include <string>
using namespace std;

bool f1(double **D, int n, int m, int a)
{
    for (int j=0; j<m; j++)
        for (int i=0; i<n-1; i++)
            if ((int)(D[i][j]+D[i+1][j]+0.5)==a)
                return true;
    return false;
}

bool f2(string **Q, int n)
{
    int l=0, s=0;
    for (int i=1; i<n; i++){
        if (Q[i][i].length()>Q[l][l].length())
            l=i;
        if (Q[i][i].length()<Q[s][s].length())
            s=i;
    }
    int l_vowels=0, s_vowels=0;
    for (int k=0; k<Q[l][l].length(); k++)
        switch (Q[l][l][k]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                l_vowels++;
            default:
                break;
        }
    for (int k=0; k<Q[s][s].length(); k++)
        switch (Q[s][s][k]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                s_vowels++;
            default:
                break;
        }
    if (l_vowels<s_vowels)
        return true;
    else
        return false;
}

int main()
{
    double ** v1 = new double *[3];
    v1[0] = new double [2] {2.45,3.4};
    v1[1] = new double [2] {0.666667,2.44445};
    v1[2] = new double [2] {1.1111,2.3456};
    cout << f1(v1,3,2,10) <<endl;

    string **v2 = new string * [3];
    v2[0] = new string [3] {"aaeddf","aaaffffvvv","erty"};
    v2[1] = new string [3] {"qwqqww","cvbhhheee","aeiouaeiouaeiou"};
    v2[2] = new string [3] {"pppdppddffffeee","aeae","xxxxxxxxxxxxxxxddd"};
    cout << f2(v2,3) <<endl;
}
