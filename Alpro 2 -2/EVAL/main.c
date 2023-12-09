#include "head.h"

int main()
{
    banyakdata = 0;
    int i = 0, x;
    char pita[100][55];
    scanf(" %101[^\n]s", &pita[i]);

    start(pita[i]);
    while ((strcmp(getcw(), "STOP") != 0) && (pita[i][strlen(pita[i])] != '!'))
    {
        prosedur(i, pita[i]);
        i++;
        scanf(" %100[^\n]s", &pita[i]);
        start(pita[i]);
    }
    output(i);

    return 0;
}