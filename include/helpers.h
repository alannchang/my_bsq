#ifndef MY_BSQ_HELPERS_H
#define MY_BSQ_HELPERS_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/* 
    Allowed: 
    malloc(3)
    free(3)
    open(2)
    read(2)
    close(2)
    printf(3)
    write(2)
*/

char* my_readline(int fd);

int check_arg_ct(int ac);

int get_line_ct(int fd);

int my_min(int a, int b, int c);

#endif