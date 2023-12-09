#include "head.h"

int main()
{
    printf("Ukuran Array   : ");
    scanf("%i", &n);

    char input[n];

    printf("Masukkan Array : ");
    for (int i = 0; i < n; i++) scanf(" %c", &input[i]);

    char metode[10];

    printf("Metode Sorting : ");
    scanf("%s", metode);

    if (strcmp(metode, "insertion") == 0) insertion_sort(input);
    else if (strcmp(metode, "selection") == 0) selection_sort(input);
    else if (strcmp(metode, "bubble") == 0) bubble_sort(input);
    else if (strcmp(metode, "quick") == 0) quick_sort(input, 0, n - 1);

    printf("Hasil Sorting  : ");
    for (int i = 0; i < n; i++) printf("%c%c", input[i], i == n - 1 ? '\n' : ' ');

    return 0;
}