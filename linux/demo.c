#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

/*#define offsetof(type, member) (size_t)&(((type*)0)->member)
#define container_of(ptr, type, member) ({ \
         const typeof( ((type *)0)->member ) *__mptr = (ptr); \
                        (type *)((char *)__mptr - offsetof(type,member) );})
*/

#define offsetof(type, member) (size_t)&(((type*)0)->member)                       
                                                                                   
#define container_of(ptr, type, member) ({ \
        const typeof(((type *)0)->member) *__mptr = (ptr); \
        (type *)((char *)__mptr - offsetof(type,member));})     

struct pnode{ 
    char a; 
    int b; 
    int * ptr; 

}; 


struct pnode foo ={
    .a = 'h',
    .b = 2,
    .ptr = NULL,
}; 

 

// 那这个函数是否可行： 
/*struct pnode * to_pnode(struct pnode *fo){ 


}*/

int main(int argc, char const *argv[])
{
    int a[20];
    for (int i = 0; i < 20; ++i) {
        scanf("%d",&a[i]); /* code */
        printf("hh：%d\n",a[i]);
    }



    struct pnode * p = NULL;
    // p = to_pnode(&foo);
    printf("foo.a:%c foo.b:%d\n", foo.a,foo.b);
    if (!foo.ptr)
        printf("the ptr is null\n");
  
    printf("%p\n", &foo);
    
    p = container_of(&(foo.b),struct pnode,b); 

    printf("%p\n", (void *)p);

    return 0;
}