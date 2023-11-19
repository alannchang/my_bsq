#include "../include/my_bsq.h"

int check_arg_ct(int ac){
    if (ac != 2){
        write(2, "INVALID NUMBER OF ARGUMENTS", 27);
        return -1;
    }
    return 0;
}

int get_line_ct(int fd){
    char* first_line = NULL;
    if ((first_line = my_readline(fd)) == NULL){
        write(2, "INVALID MAP", 11);
        return -1;
    }
    
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

max_pt init_max_pt(){
    max_pt max_pt;
    max_pt.row = -1;
    max_pt.val = 0;
    return max_pt;
}

row init_row(int index){
    row row;
    row.str = NULL;
    row.index = index;
    return row;
}

max_pt get_max_pt(int fd, int line_ct){
    int matrix[line_ct][line_ct];
    max_pt max_pt = init_max_pt();

    // first row of the map
    char *first_row = my_readline(fd);
    for (int i = 0; i < line_ct; i++){
        if (first_row[i] == EMPTY) matrix[0][i] = 1;
        else if (first_row[i] == OBSTACLE) matrix[0][i] = 0;
        cmp_val(matrix[0][i], &max_pt, 0, i);
    }
    free(first_row);

    // the rest of the map
    row row = init_row(1);

    while ((row.str = my_readline(fd)) != NULL){

        // first character
        if (row.str[0] == EMPTY) matrix[row.index][0] = 1;
        else if (row.str[0] == OBSTACLE) matrix[row.index][0] = 0;
        cmp_val(matrix[row.index][0], &max_pt, row.index, 0);

        // rest of the characters
        for (int i = 1; i < line_ct; i++){
            if (row.str[i] == OBSTACLE) matrix[row.index][i] = 0;
            else matrix[row.index][i] = my_min(matrix[row.index][i - 1], matrix[row.index - 1][i], matrix[row.index - 1][i - 1]) + 1;
            cmp_val(matrix[row.index][i], &max_pt, row.index, i);
        }
        row.index++;
        free(row.str);
    }
    close(fd);
    return max_pt;
}


int print_solution(char *map_file, max_pt max_pt, int line_ct){
    int fd = open(map_file, O_RDONLY);
    
    char *pass_line_ct = my_readline(fd); // skip first line (line count)
    free(pass_line_ct);

    row row = init_row(0);
    max_pt.val--;
    while ((row.str = my_readline(fd)) != NULL){
        if (row.index >= max_pt.row - max_pt.val && row.index <= max_pt.row){
            for (int i = 0; i < line_ct; i++){
                if (i >= max_pt.col - max_pt.val && i <= max_pt.col) printf("%c", SQUARE);
                else (printf("%c", row.str[i]));
            }
            printf("\n");
        
        } else {
            printf("%s", row.str);
            printf("\n");
        }

        row.index++;
        free(row.str);
    }
    close(fd);
    return 0;
}
