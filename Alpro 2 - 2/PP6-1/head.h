#include <stdio.h>
#include <string.h>

typedef struct{
    char nama[50];
    int nim;
} data;

void swapint(int *a, int *b);
void swapstr(char a[], char b[]);
void sorting(data arr[], int n);
void merge(data arr1[], int n1, data arr2[], int n2, data arr3[]);
void scandata(data arr[], int n);
void printdata(data arr[], int n);