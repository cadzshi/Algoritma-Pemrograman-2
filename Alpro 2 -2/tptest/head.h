#include <stdio.h>
#include <string.h>

int n;  // ukuran array

void insertion_sort(char[]);
void selection_sort(char[]);
void bubble_sort(char[]);
void quick_sort(char[], int , int);
int partition(char[], int, int);
void swap(char*, char*);