#include <iostream>
#include <string>
#define N 3
using namespace std;

bool f1(int **A, int n, double w)
{
    int min = A[0][n-1];
    int max = A[0][n-1];
    int i = 1, j = n-2;

    while (i<n && j>=0) {
        if (A[i][j]<min)
            min = A[i][j];
        if (A[i][j]>max)
            max = A[i][j];
        i++;
        j--;
    }

    if (static_cast<double>(min)/max <= w)
        return true;
    else
        return false;
}

bool f2 (string **A, int n, int m, short s, short k)
{
    short s_counter = 0, c_counter = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<A[i][j].length(); k++)
                if (isupper((A[i][j])[k]))
                    c_counter++;
            if (c_counter<s)
                s_counter++;
            c_counter = 0;
        }
        if (s_counter>=k)
            return true;
        else
            s_counter = 0;
    }
    return false;
}

int main()
{
    //f1
    int **A1 = new int * [N];
    for (int i=0; i<N; i++)
        A1[i] = new int [N];
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            A1[i][j] = i*N + j + 1;
    cout << f1(A1, N, 0.01) << "    " << f1(A1, N, 0.5) <<endl;


    //f2
    string **A2 = new string * [3];
    A2[0] = new string [2] {"ABCdef", "abcDef"};
    A2[1] = new string [2] {"abCDef", "ABCDEF"};
    A2[2] = new string [2] {"abcdef", "ABCDef"};
    cout << f2(A2, 3, 2, 3, 2) << "    " << f2(A2, 3, 2, 2, 1) <<endl;

}
