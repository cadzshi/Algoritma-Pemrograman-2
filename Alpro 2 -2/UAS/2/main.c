#include "head.h"

int main()
{
    char pita[501];
    char a, b;
    int jmla, jmlb, jmlkata = 0;


    scanf("%501[^\n]s", &pita);
    scanf("\n%c %d\n%c %d", &a, &jmla, &b, &jmlb);


    start(pita);
    // while (eop(pita) == 0)
    // {
    //     getcw();

    // }

    printf("%d\n", jmlkata);
    
    return 0;
}

