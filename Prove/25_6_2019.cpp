#include <iostream>
#include <string>

using namespace std;

bool f1(int **M, int n, int m, short k, double x)
{
    short counter=0;
    for (int j=0; j<m; j++){
        for (int i=0; i<n-1; i++)
            if (M[i+1][j]!=0 && (double) M[i][j]/M[i+1][j] < x)
                counter++;
        if (counter==k)
            return true;
        counter=0;
    }
    return false;
}

bool f2 (string * **Q, int n, short m, short k)
{
    short v_counter=0, s_counter=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<Q[i][n-1-i]->length(); j++)
            switch ((*Q[i][n-1-i])[j]){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    v_counter++;
                default:
                    break;
            }
        if (v_counter<=k)
            s_counter++;
        v_counter=0;
    }
    if (s_counter>=m)
        return true;
    else
        return false;
}

int main()
{
    int **v1 = new int * [3];
    v1[0] = new int [2] {0,1};
    v1[1] = new int [2] {2,3};
    v1[2] = new int [2] {4,5};
    cout << f1(v1, 3, 2, 1, 0.7) << endl;

    string s1="aebcd", s2="eouiacd";
    string s3="eocdbf", s4="aaaaa";
    string * **v2 = new string **[2];
    v2[0] = new string *[2] {&s1, &s2};
    v2[1] = new string *[2] {&s3, &s4};
    cout << f2(v2, 2, 2, 3) <<endl;
}
