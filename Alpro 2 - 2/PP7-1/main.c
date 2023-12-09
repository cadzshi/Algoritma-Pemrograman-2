#include "head.h"

int main()
{   
    int n, target;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    scanf("%d", &target);

    search(n, num, target);
    
    
    return 0;
}