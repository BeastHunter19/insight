#include <cstdlib>
#include <iostream>
#include <string>
#define N 3

using namespace std;

unsigned santone(bool v[N][N])
{
    srand(time(NULL));
    int x = N/2, y = N/2;
    unsigned counter = 0;
    unsigned dir;
    while (x<N && y<N && x>=0 && y>=0) {
        if (v[x][y]==true){
            counter++;
            v[x][y] = false;
        }
        dir = rand()%4;
        switch (dir) {
            case 0:
                y--;
                break;
            case 1:
                x++;
                break;
            case 2:
                y++;
                break;
            case 3:
                x--;
                break;
        }
    }
    return counter;
}

bool sorelle(string * A[][N], int n, int m)
{
    int counters[m] = {0};
    for (int j=0; j<m; j++) {
        for (int i=0; i<n; i++) {
            if (A[i][j]==nullptr)
                counters[j] = -1;
            else {
                for (int k=0; k<(*A)[i][j].length(); k++) {
                    switch (((*A)[i][j])[k]) {
                        case 'a':
                        case 'e':
                        case 'i':
                        case 'o':
                        case 'u':
                            counters[j]++;
                        default:
                            break;
                    }
                }
            }
        }
        for (int i=0; i<m; i++)
            for (int j=1; j<m; j++)
                if (counters[i]==counters[j] && counters[i]!=-1 && i!=j)
                    return true;
    }
    return false;
}

int main()
{
    srand(time(NULL));
    bool v1[N][N];
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            v1[i][j] = rand()%2;
            cout << v1[i][j] << " ";
        }
        cout <<endl;
    }
    cout << endl << santone(v1);

    string s1 = "";
    string s2 = "abbcd";
    string s3 = "ciao";
    string s4 = "aeiou";
    string s5 = "aebbcdg";
    string s6 = "aeionm";

    string* v2[2][N] = {nullptr, &s2, &s3, &s4, &s5, &s6};
    cout << endl << sorelle(v2, 2, N);
    return 0;
}
