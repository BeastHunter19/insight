#define N 3
#include <string>
#include <iostream>
using namespace std;

bool func1(int v[][N], double w)
{
    int diagonal = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            if (i+j+1==N)
                diagonal += v[i][j];

    int column = 0;
    for (int j=0; j<N; j++) {
        for (int i=0; i<N; i++)
            column += v[i][j];
        if (static_cast<double>(column/diagonal)>w)
            return true;
        else
            column = 0;
    }
    return false;
}

bool func2(string * P[][2], int n, int m, short a, short b, string s)
{
    short counter = 0;
    for (int j=0; j<m; j++) {
        for (int i=0; i<n; i++)
            if ((*P)[i][j].find(s)!=string::npos)
                counter++;
        if (counter>=a && counter<=b)
            return true;
        else
            counter = 0;
    }
    return false;
}

int main()
{
    int arr1 [N][N] = {2, 3, 5, 4, 6, 7, 1, 3, 9};
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
            cout << arr1[i][j] << " ";
        cout << endl;
    }
    bool bool1 = func1(arr1, 0.2);
    cout <<endl << bool1;

    string s1="jonathan",s2="joseph",s3="jotaro",s4="josuke",s5="giorno",s6="jolyne";
    string * arr2[3][2] = {&s1, &s2, &s3, &s4, &s5, &s6};
    bool bool2 = func2(arr2, 3, 2, 1, 2, "jo");
    cout <<endl << bool2;

}
