#include "../include/helpers.h"
#include "../include/my_bsq.h"

/* Allowed functions: 
    malloc(3)
    free(3)
    open(2)
    read(2)
    close(2)
    printf(3)
    write(2)
*/

int main(int ac, char** av){

    if(check_arg_ct(ac) != 0) return -1;

    int fd = open(av[1], O_RDONLY);

    // read first line, store as integer
    int line_ct = get_line_ct(fd);
    printf("Row count: %d\n", line_ct); // TEST PRINT

    // create matrix
    int matrix[line_ct][line_ct];
    max_pt max_pt;
    max_pt.row = -1;
    max_pt.val = 0;

    // first row of the map
    char *first_row = my_readline(fd);
    for (int i = 0; i < line_ct; i++){
        if (first_row[i] == '.') matrix[0][i] = 1;
        else if (first_row[i] == 'o') matrix[0][i] = 0;
        cmp_val(matrix[0][i], &max_pt, 0, i);
    }

    // the rest of the map
    char *row = NULL;
    int row_index = 1;

    while ((row = my_readline(fd)) != NULL){

        // first character
        if (row[0] == '.') matrix[row_index][0] = 1;
        else if (row[0] == 'o') matrix[row_index][0] = 0;
        cmp_val(matrix[row_index][0], &max_pt, row_index, 0);

        // rest of the characters
        for (int i = 1; i < line_ct; i++){
            if (row[i] == 'o') matrix[row_index][i] = 0;
            else matrix[row_index][i] = my_min(matrix[row_index][i - 1], matrix[row_index - 1][i], matrix[row_index - 1][i - 1]) + 1;
            cmp_val(matrix[row_index][i], &max_pt, row_index, i);
        }
        row_index++;
        free(row);
    }

    // TEST PRINT MATRIX
    for (int i = 0; i < line_ct; i++){
        for (int j = 0; j < line_ct; j++){
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    // invalid map or no squares found
    if (max_pt.row == -1){
        write(2, "INVALID MAP", 11);
        return -1;
    } 

    printf("Value:%d Row:%d Col:%d\n", max_pt.val, max_pt.row, max_pt.col); // TEST PRINT

    free(first_row);
    close(fd);


    return 0;
}