#include "head.h"

int main()
{
    int nG;
    scanf("%d", &nG);
    data G[nG];
    scandata(G, nG);

    int nH;
    scanf("%d", &nH);
    data H[nH];
    scandata(H, nH);

    int nR;
    scanf("%d", &nR);
    data R[nR];
    scandata(R, nR);

    int nS;
    scanf("%d", &nS);
    data S[nS];
    scandata(S, nS);

    int m;
    scanf("%d", &m);

    char tipe[10];
    scanf("%s", &tipe);

    sorting(G, nG, tipe);
    sorting(H, nH, tipe);
    sorting(R, nR, tipe);
    sorting(S, nS, tipe);

    data GH[nG + nH];
    merge(G, nG, H, nH, GH, tipe);

    data GHR[nG + nH + nR];
    merge(GH, nG + nH, GHR, nG + nH + nR, GHRS, tipe);

    data GHRS[nG + nH + nR + nS];
    merge(GH, nG + nH, GHR, nG + nH + nR, GHRS, tipe);
    return 0;
}