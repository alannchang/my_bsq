#include "../include/helpers.h"

/* Allowed functions: 
    malloc(3)
    free(3)
    open(2)
    read(2)
    close(2)
    printf(3)
    write(2)
*/

/* 
GAME PLAN:
-read map file, line by line
-


*/

int main(int ac, char** av){

    if(check_arg_ct(ac) != 0) return -1;

    char *str = NULL;
    int fd = open(av[1], O_RDONLY);
    while ((str = my_readline(fd)) != NULL)
    {
        printf("%s\n", str);
        free(str);
    }

    close(fd);

    return 0;
}