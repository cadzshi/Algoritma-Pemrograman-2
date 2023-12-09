#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nama[100];
    int red, green, blue;
} data;

int n, m;
char dicari[10];

void scanwarna (data warna[n][m]);
void printwarna (data warna[n][m]);
void pembatas();
void pembatas2();
