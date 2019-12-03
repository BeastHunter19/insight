#include <iostream>
#include <string>
using namespace std;

bool f1(int **A, int n, int m, double w, double v)
{
    double avg;
    for (int j=0; j<m; j++) {
        avg = 0.0;
        for (int i=0; i<n; i++)
            avg += A[i][j];
        avg = avg/n;
        if (avg>=w && avg<=v)
            return true;
    }
    return false;
}

int f2(string * **M, int n, int m, unsigned short k, unsigned short s)
{
    int c_counter=0;
    int s_counter=0;
    int v_counter=0;
    for (int j=0; j<m; j++) {
        for (int i=0; i<n; i++) {
            for (int k=0; k<M[i][j]->length(); k++) {
                switch ((*M[i][j])[k]) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                        v_counter++;
                    default:
                        break;
                }
            }
            if (v_counter<s)
                s_counter++;
            v_counter=0;
        }
        if (s_counter>=k)
            c_counter++;
        s_counter=0;
    }
    return c_counter;
}

int main()
{
    int **A1 = new int * [3];
    A1[0] = new int [3] {1,2,3};
    A1[1] = new int [3] {4,5,6};
    A1[2] = new int [3] {7,8,9};
    cout << f1(A1, 3, 3, 2.2, 3.5) << "     " << f1(A1, 3, 3, 5.5, 6.0) <<endl;
    for (int i=0; i<3; i++)
        if (A1[i]) {
            delete [] A1[i];
            A1[i] = nullptr;
        }
    if (A1) {
        delete [] A1;
        A1 = nullptr;
    }

    string s1="aeiou", s2="aeiob";
    string s3="aeibc", s4="aebcd";
    string s5="abcdf", s6="bcdfg";
    string * **A2 = new string ** [3];
    A2[0] = new string * [2] {&s1, &s2};
    A2[1] = new string * [2] {&s3, &s4};
    A2[2] = new string * [2] {&s5, &s6};
    cout << f2(A2, 3, 2, 2, 1) << "     " << f2(A2, 3, 2, 2, 3) <<endl;
    for (int i=0; i<3; i++)
        if (A2[i]) {
            delete [] A2[i];
            A2[i] = nullptr;
        }
    if (A2) {
        delete [] A2;
        A2 = nullptr;
    }
}
