#include <iostream>
#include <string>
using namespace std;

short *f1 (double **K, int n, int m, int a, int b)
{
    short *A = new short[m] {0};
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if ((int)(K[j][i]+0.5)>a && (int)(K[j][i]+0.5)<b)
                A[i]++;
    return A;
}

bool f2 (string **S, int n, int m, short k, string w)
{
    int counter=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++)
            if (S[i][j].find(w)!=string::npos)
                counter++;
        if (counter<=k)
            return true;
        counter=0;
    }
    return false;
}

int main()
{
    double **v1 = new double *[3];
    v1[0] = new double [3] {1.3, 2.7, 4.9};
    v1[1] = new double [3] {0.3, 5.8, 1.45};
    v1[2] = new double [3] {2.4567, 3.567, 8.00004};
    short * V = f1(v1,3,3,1,9);
    for (int i=0; i<3; i++)
        cout << V[i] << " ";

    string **v2 = new string * [2];
    v2[0] = new string [3] {"abcdef","defghi","ghijjkl"};
    v2[1] = new string [3] {"xxxxxxa","jjjjjjjjcd","ooojjjdfdnn"};
    cout << endl << f2(v2,2,3,0,"jj");
}
