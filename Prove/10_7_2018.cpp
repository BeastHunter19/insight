#include <iostream>
#include <string>
using namespace std;

bool f1(char ***A, int n)
{
    bool x=true;
    for (int j=0; j<n; j++){
        for (int i=0; i<n; i++)
            if (*A[i][j]!=*A[i][i])
                x=false;
        if (x==true)
            return true;
        else
            x=true;
    }
    return false;
}

string **f2(string **A, int n, int m, int k)
{
    string **C = new string *[n];
    for (int i=0; i<n; i++)
        C[i] = new string [m];
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            C[i][j] = A[i][j];
    for (int i=0; i<n; i++)
        for (int l=0; l<C[i][k].length(); l++)
            switch(C[i][k][l]){
                case 'j':
                case 'k':
                case 'w':
                case 'x':
                case 'y':
                    C[i][k].erase(l,1);
                    l--;
                default:
                    break;
            }
    return C;
}

int main()
{
    char c1='a', c2='a', c3='c';
    char c4='d', c5='e', c6='f';
    char c7='g', c8='i', c9='i';
    char ***v1 = new char** [3];
    v1[0] = new char * [3] {&c1,&c2,&c3};
    v1[1] = new char * [3] {&c4,&c5,&c6};
    v1[2] = new char * [3] {&c7,&c8,&c9};
    cout << f1(v1,3) <<endl;

    string **v2 = new string *[3];
    v2[0] = new string [2] {"abcdhjklm","afgvwx"};
    v2[1] = new string [2] {"aaaaaaaakkk","poooowwww"};
    v2[2] = new string [2] {"xxxzzyyylkjhg","aaaaaaaa"};
    string **v3 = f2(v2,3,2,1);
    for (int i=0; i<3; i++){
        for (int j=0; j<2; j++){
            cout << v3[i][j] << "  ";
        }
        cout <<endl;
    }

}
