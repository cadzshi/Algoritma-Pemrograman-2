#include <stdio.h>

//contoh rekursif
void jasuke()
{
    printf("jagung\n");
    printf("susu\n");
    jasuke();
}

//rekursif dengan base case
void count(int n)
{
    printf("%d\n", n);
    if (n < 3) //base case
    {
        count(n + 1); //rekursif
    }
}

int main()
{
    jasuke();
    count(1);
    return 0;
}