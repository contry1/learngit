
#include "name_semp.h"

int main(int argc, char const *argv[])
{

    
    printf("please input file name:");
    if (argc != 2) {
        printf("the usage...\n");
        exit(1);
        /* code */
    }
    sem_unlink_t(argv[1]);


    
    // pause();
    return 0;
}

