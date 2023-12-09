#include <string.h>
#include <stdio.h>

typedef struct{
    int nim;
    char nama;
    char kelas;
} data;

void swap(data temp[], int a, int b);
void sort(int n, data arr[]);
void search(data arr[], int n, int target);
