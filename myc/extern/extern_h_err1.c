#include "extern.h"
extern int i = 1;
int main(int argc, char const *argv[])
{
    /* code */
    for (i = 1; i < 20; ++i)
    {
        /* code */
        printf("%d\n", i);
    }
    return 0;
}
******************************************************
// extern.h
#include <stdio.h>
int i=0;

********************************************************
// the error indent that we redefine the value in the extern*.c.so we make the value of extern param is equal to the *.h