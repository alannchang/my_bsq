#include "../include/helpers.h"

int check_arg_ct(int ac){
    if (ac != 2){
        write(2, "ERROR",5);
        return -1;
    }
    return 0;
}

int get_line_ct(int fd){
    char* first_line = my_readline(fd);
    int num = 0;
    while (*first_line >= '0' && *first_line <= '9'){
        num = num * 10 + (*first_line - '0');
        first_line++;
    }
    return num;
}

int my_min(int a, int b, int c){
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}