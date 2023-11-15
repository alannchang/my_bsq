#ifndef MY_BSQ_MY_BSQ_H
#define MY_BSQ_MY_BSQ_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "../include/helpers.h"

typedef struct{
    int row;
    int col;
    int val;
} max_pt;

void compare_max(int **matrix, int *max);

#endif