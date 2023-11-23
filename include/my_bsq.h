#ifndef MY_BSQ_MY_BSQ_H
#define MY_BSQ_MY_BSQ_H
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "my_readline.h"
#define EMPTY '.'
#define OBSTACLE 'o'
#define SQUARE 'x'
typedef struct{
    int row;
    int col;
    int val;
} max_pt;

typedef struct{
    int index;
    char *str;
} row;

typedef struct{
    int rows;
    int cols;
} dimensions;

int my_strlen(char *str);

int check_arg_ct(int ac);

int get_line_ct(int fd);

int my_min(int a, int b, int c);

void cmp_val(int current, max_pt *max_pt, int current_row, int current_col);

max_pt get_max_pt(int fd, char *first_row, dimensions dim);

int print_solution(char *map_file, max_pt max_pt, dimensions dim);

#endif