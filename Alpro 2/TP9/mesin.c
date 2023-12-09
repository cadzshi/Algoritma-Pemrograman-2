#include "head.h"


int idx;
int wlen;
char cw[50];



void start(char str[])
{
    
    idx = 0;
    wlen = 0;

    while (str[idx] == ' ')
    {
        idx++;
    }


    while ((str[idx] != ' ') && (eop(str) == 0))
    {
        cw[wlen] = str[idx];
        wlen++;
        idx++;
    }

    cw[wlen] = '\0';
}



void reset()
{

    wlen = 0;
    cw[wlen] = '\0';
}



int eop(char str[])
{
    
    if (str[idx] == ';')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



void inc(char str[])
{
    
    wlen = 0;


    
    while (str[idx] == ' ')
    {
        idx++;
    }


    
    while ((str[idx] != ' ') && (eop(str) == 0))
    {
        cw[wlen] = str[idx];
        wlen++;
        idx++;
    }


    
    cw[wlen] = '\0';
}



int getlen()
{
    return wlen;
}



char *getcw()
{
    return cw;
}

void check(char str[], char kode, int flag)
{
    while ((str[idx] != ' ') && (eop(str) == 0))
    {
        cw[wlen] = str[idx];
        if (cw[wlen - 1] == kode)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
        
        
    }
    
}