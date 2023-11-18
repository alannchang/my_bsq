#ifndef MY_BSQ_MY_BSQ_H
#define MY_BSQ_MY_BSQ_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "helpers.h"

#define EMPTY '.'
#define OBSTACLE 'o'
#define SQUARE 'x'

typedef struct{
    int row;
    int col;
    int val;
} max_pt;

int check_arg_ct(int ac);

int get_line_ct(int fd);

int my_min(int a, int b, int c);

void cmp_val(int current, max_pt *max_pt, int current_row, int current_col);

max_pt create_matrix(int fd, int line_ct);

int print_solution(char *map_file, max_pt max_pt, int line_ct);

#endif