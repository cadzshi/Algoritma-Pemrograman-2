#include "head.h"

int main
{
    char tipe[10];
    scanf("%s", &tipe);
    
    int a, jmlmenu1, jmlgula1, jmlkarbo1, jmlprotein1;
    scanf("%d", &a);
    data menu1[a];
    scandata(menu1, a, jmlmenu1, jmlgula1, jmlkarbo1, jmlprotein1);

    int b, jmlmenu2, jmlgula2, jmlkarbo2, jmlprotein2;
    scanf("%d", &b);
    data menu2[b];
    scandata(menu2, b, jmlmenu2, jmlgula2, jmlkarbo2, jmlprotein2);

    int c, jmlmenu3, jmlgula3, jmlkarbo3, jmlprotein3;
    scanf("%d", &c);
    data menu3[c];
    scandata(menu3, c);


    return 0;
}