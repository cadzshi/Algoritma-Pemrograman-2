#include "head.h"

int main()
{
    char pita[501];
    char cari;
    int flag;

    scanf("%501[^\n]s %c", &pita, &cari);

    start(pita);
    while (eop() == 0)
    {
        getcc();
        if (getcc() == cari)
        {
            inc(pita);
            getcc();
            if (getcc() == 'a' || getcc() == 'i' || getcc() == 'u' || getcc() == 'e' || getcc() == 'o')
            {
                inc(pita);
                getcc();
                if (getcc() == 'a' || getcc() == 'i' || getcc() == 'u' || getcc() == 'e' || getcc() == '0')
                {
                    inc(pita);
                    getcc();
                }
                
            }
            if (getcc() != 'a' && getcc() != 'i' && getcc() != 'u' && getcc() != 'e' && getcc() != 'o')
            {
                    inc(pita);
                    getcc();
                    flag++;
            }
        }
        adv(pita);
    }

    printf("%d", flag);
}