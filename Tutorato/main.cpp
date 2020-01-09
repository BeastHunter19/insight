#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

bool *f1(char **C, int n)
{
    bool *arr = new bool [n];
    bool pal = true;
    for (int i=0; i<n; i++){
        for (int k=0; k<strlen(C[i])/2; k++)
            if (tolower(C[i][k])!=tolower(C[i][strlen(C[i])-k-1]))
                pal = false;
        arr[i] = pal;
        pal = true;
    }
    return arr;
}

bool f2(short **A, int n)
{
    for (int i=0; i<n; i++)
        if (A[i][i]!=A[i][n-1-i])
            return false;
    return true;
}

int f3(long *S, int n)
{
    int max=0, counter=1, index=0, new_index=0;
    for (int i=0; i<n-1; i++){
        if (S[i]>=S[i+1]){
            counter++;
            if (counter>=max){
                max = counter;
                index = new_index;
            }
        }
        else{
            new_index=i+1;
            counter=1;
        }
    }
    return index;
}

int main()
{
    char c1[] = "anna";
    char c2[] = "Anna";
    char c3[] = "jojo";
    char **v1 = new char *[3] {c1,c2,c3};
    bool *b1 = f1(v1,3);
    for (int i=0; i<3; i++)
        cout << b1[i] <<endl;

    short **v2 = new short * [3];
    v2[0] = new short [3] {2,3,2};
    v2[1] = new short [3] {1,3,5};
    v2[2] = new short [3] {4,8,3};
    cout << f2(v2,3) <<endl;

    long * v3 = new long [10] {5,5,5,5,5,5,5,5,5,5};
    cout << f3(v3,10)<<endl;
}
