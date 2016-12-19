// extern.c
#include <stdio.h>
extern int i;
int main(int argc, char const *argv[])
{
    /* code */
    for (i = 0; i < 20; ++i)
    {
        /* code */
        printf("%d\n", i);
    }
    return 0;
}
int i = 0;
// the first exp  is correct,the extern 的作用是扩大变量的作用域，如果不加，int i只在末尾有作用。
// 

extern_no.c
#include <stdio.h>
// extern int i;
int main(int argc, char const *argv[])
{
    /* code */
    for (i = 0; i < 20; ++i)
    {
        /* code */
        printf("%d\n", i);
    }
    return 0;
}
int i = 0;
// the second is err ,the err is unidefine int i.