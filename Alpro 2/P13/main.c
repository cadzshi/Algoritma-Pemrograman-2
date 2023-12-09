#include <stdio.h>
#include "head.h"

int main()
{
    //NAMPILIN ISI PITA
    // char pita[50];
    // printf("masukkan kalimat pada pita\n");
    // scanf("%49[^\n]s", &pita);

    // START(pita);
    // printf("%c\n", GETCC());

    // while (EOP() == 0)
    // {
    //     INC(pita);
    //     printf("%c\n", GETCC());
    // }

    //NAMPILIN ISI PITA YANG HANYA HURUF A
    // char pita[50];
    // printf("masukkan kalimat pada pita\n");
    // scanf("%49[^\n]s", &pita);

    // START(pita);
    // while (EOP() == 0)
    // {
    //     if (GETCC() == 'a')
    //     {
    //          printf("%c - %d\n", GETCC(), GETIndeks());
    //     }
    //     INC(pita);
    // }

    //MENGHITUNG BANYAK HURUF A
    // char pita[50];
    // int n;
    // printf("masukkan kalimat pada pita\n");
    // scanf("%49[^\n]s", &pita);
    
    // START(pita);
    // while (EOP() == 0)
    // {
    //     if (GETCC() == 'a')
    //     {
    //          n++;
    //     }
    //     INC(pita);
    // }
    // printf("banyaknya a adalah %d\n", n);

    //MENGHHITUNG BANYAK HURUF
    // char pita[50];
    // int n = 0;
    // printf("masukkan kalimat pada pita\n");
    // scanf("%49[^\n]s", &pita);

    // START(pita);
    // while (EOP() == 0)
    // {
    //     n++;
    //     ADV(pita);
    // }
    // printf("banyaknya huruf adalah %d\n", n);

    //MENGHITUNG BANYAK SUKU KATA "NA"
    // char pita[50];
    // char temp;
    // int n = 0;
    // printf("masukkan kalimat pada pita\n");
    // scanf("%49[^\n]s", &pita);

    // START(pita);
    // while (EOP() == 0)
    // {
    //     temp = GETCC();
    //     INC(pita);
    //     if (EOP() == 0)
    //     {
    //         if (temp == 'n' && GETCC() == 'a')
    //         {
    //             n++;
    //         }   
    //     }
    // }
    // printf("banyaknya suku na adalah %d\n", n);

    //MENGHITUNG SUKU KATA KAK
    char pita[50];
    char temp, tempp;
    int n = 0;
    printf("masukkan kalimat pada pita\n");
    scanf("%49[^\n]s", &pita);

    START(pita);
    while (EOP() == 0)
    {
        temp = GETCC();
        INC(pita);
        if (EOP() == 0)
        {
            tempp = GETCC();
            INC(pita);
            if (EOP() == 0)
            {   
                if (temp == 'k' && tempp == 'a' && GETCC() == 'k')
                {
                    n++;
                }   
            }
            
        }
    }
    printf("banyaknya suku kak adalah %d\n", n);

    return 0;
}