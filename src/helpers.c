#include "../include/helpers.h"
#include "../include/my_bsq.h"

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
    int i = 0;
    while (first_line[i] >= '0' && first_line[i] <= '9'){
        num = num * 10 + (first_line[i] - '0');
        i++;
    }
    free(first_line);
    return num;
}

int my_min(int a, int b, int c){
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

void cmp_val(int current, max_pt *max_pt, int current_row, int current_col){
    if (current > max_pt->val){
        max_pt->val = current;
        max_pt->row = current_row;
        max_pt->col = current_col;
    }
}