#include "head.h"

int main()
{
    int n, target;
    scanf("%d", &n);
    data arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].nim);
        scanf("%s", &arr[i].nama);
        scanf("%s", &arr[i].kelas);
    }
    scanf("%d", &target);

    
    sort(n, arr);
    search(arr, n, target);

    return 0;
}