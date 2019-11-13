#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
using namespace std;
int sum(double a, double b);
float rapp(unsigned a, unsigned b);
int sum_array(double v[], int n);
float average(unsigned v[], int n);
int vowels(char v[], int n);
int last_consonant(char v[], int n);
char * pointer(char v[], int n);
void exchange(unsigned v[], int n);
void invert(unsigned v[], int n);
short * max_array(short v1[], short v2[], int n);
char * vowels_array(char v[], int n, short * p);
unsigned chars_in_strings(string s[], int n, char c[], int m, short w);
#endif
