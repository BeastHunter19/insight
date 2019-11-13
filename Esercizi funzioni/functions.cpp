#include <string>

using namespace std;

int sum(double a, double b)
{
    int sum = a+b+0.5;
    return sum;
}

float rapp(unsigned a, unsigned b)
{
    if (b==0) {
        return -1;
    }
    else {
        float rapp = (float)a/b;
        return rapp;
    }
}

int sum_array(double v[], int n)
{
    double sum = 0;
    for (int i=0; i<n; i++) {
        sum += v[i];
    }
    return sum+0.5;
}

float average(unsigned v[], int n)
{
    unsigned sum = 0;
    for (int i=0; i<n; i++) {
        sum += v[i];
    }
    return (float)sum/n;
}

int vowels(char v[], int n)
{
    unsigned counter = 0;
    for (int i=0; i<n; i++) {
        switch (v[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                counter++;
            default:
                break;
        }
    }
    return counter;
}

int last_consonant(char v[], int n)
{
    int index;
    for (int i=0; i<n; i++) {
        switch (v[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                break;
            default:
                index = i;
                break;
        }
    }
    return index;
}

char * pointer(char v[], int n)
{
    for (int i=0; i<n; i++) {
        switch (v[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return &v[i];
            default:
                break;
        }
    }
    return nullptr;
}

void exchange(unsigned v[], int n)
{
    unsigned * max = &v[0];
    unsigned * min = &v[0];
    for (int i=1; i<n; i++) {
        if (v[i]>*max) {
            max = &v[i];
        }
        if (v[i]<*min) {
            min = &v[i];
        }
    }
    unsigned p = *max;
    *max = *min;
    *min = p;
}

void invert(unsigned v[], int n)
{
    unsigned m = n-1;
    unsigned p;
    for (int i=0; i<n/2; i++) {
        p = v[i];
        v[i] = v[m-i];
        v[m-i] = p;
    }
}

short * max_array(short v1[], short v2[], int n)
{
    short *arr = new short[n];
    for (int i=0; i<n; i++) {
        if (v1[i]>v2[i]) {
            arr[i] = v1[i];
        }
        else {
            arr[i] = v2[i];
        }
    }
    return arr;
}

char * vowels_array(char v[], int n, short * p)
{
    *p = vowels(v, n);
    if (*p==0) {
        return nullptr;
    }
    char *arr = new char[*p];
    for (int i=0, j=0; i<n; i++) {
        switch (v[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                arr[j] = v[i];
                j++;
            default:
                break;
        }
    }
    return arr;
}

unsigned chars_in_strings(string s[], int n, char c[], int m, short w)
{
    unsigned s_counter = 0;
    unsigned c_counter = 0;
    for (int i=0; i<n; i++) {
        for(int j=0; j<s[i].length(); j++) {
            for (int k=0; k<m; k++) {
                if ((s[i])[j]==c[k]) {
                    c_counter++;
                }
            }
        }
        if (c_counter>=w) {
            s_counter++;
        }
        c_counter = 0;
    }
    return s_counter;
}
