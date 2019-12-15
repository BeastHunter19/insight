#include <iostream>
#include <string>
using namespace std;

int f2(string **A, int n, int m)
{
    string longest=A[0][0];
    int counter=0;
    bool x=true;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (A[i][j].length()>longest.length())
                longest=A[i][j];
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (A[i][j].length()==longest.length()){
                for (int k=0; k<A[i][j].length(); k++)
                    if (A[i][j][k]!=longest[k] && A[i][j][k]!='?' && longest[k]!='?')
                        x=false;
                if (x==true)
                    counter++;
                else
                    x=true;
            }
    return counter;
}

int main()
{
    string **v = new string *[2];
    v[0] = new string [2] {"abc?e","sd"};
    v[1] = new string [2] {"a??d","?"};
    cout << f2(v,2,2)<<endl;
}
