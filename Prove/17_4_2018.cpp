#include <iostream>
#include <string>
using namespace std;

bool f1(bool **A, bool **B, bool **C, int n)
{
    bool x=true;
    for (int k=1; k<n; k++){
        for (int i=0; i<n-k; i++)
            if (A[i][i+k]!=B[i][i+k] || A[i][i+k]!=C[i][i+k])
                x=false;
        if (x==true)
            return true;
        x=true;
    }
    return false;
}

bool f2(string * **A, int n, int m, char c)
{
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            for (int k=0; k<A[i][j]->length(); k++)
                if ((*A[i][j])[k]==c){
                    A[i][j]->erase(k,1);
                    k--;
                }
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            for (int k=0; k<n; k++)
                for (int l=0; l<m; l++)
                    if (*A[i][j]==*A[k][l] && (i!=k || j!=l))
                        return true;
    return false;
}

int main()
{
    bool **v1 = new bool *[3];
    v1[0] = new bool [3] {1,0,1};
    v1[1] = new bool [3] {0,1,0};
    v1[2] = new bool [3] {0,1,1};

    bool **v2 = new bool *[3];
    v2[0] = new bool [3] {1,0,0};
    v2[1] = new bool [3] {0,1,0};
    v2[2] = new bool [3] {0,1,1};

    bool **v3 = new bool *[3];
    v3[0] = new bool [3] {1,0,1};
    v3[1] = new bool [3] {0,1,0};
    v3[2] = new bool [3] {0,1,1};

    cout << f1(v1,v2,v3,3) <<endl;

    string s1="cxxxxcc", s2="ccvvx", s3="cccc";
    string s4="xxcccxccxc", s5="xxxxxxxxcccccccc", s6="xx";
    string ***v4 = new string **[2];
    v4[0] = new string *[3] {&s1,&s2,&s3};
    v4[1] = new string *[3] {&s4,&s5,&s6};

    cout << f2(v4,2,3,'c') <<endl;
}
