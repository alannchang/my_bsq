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

    
    int fd = open(av[1], O_RDONLY);

    // read first line, store as integer
    int line_ct = get_line_ct(fd);
    printf("The number is: %d\n", line_ct); // TEST PRINT

    // create matrix
    int matrix[line_ct][line_ct];

    // first row of the map
    char *first_row = my_readline(fd);
    for (int i = 0; i < line_ct; i++){
        if (first_row[i] == '.') matrix[0][i] = 1;
        if (first_row[i] == 'o') matrix[0][i] = 0;
    }

    // the rest of the map
    char *row = NULL;
    int row_index = 1;
    while ((row = my_readline(fd)) != NULL){
        // first character
        if (row[0] == '.') matrix[row_index][0] = 1;
        if (row[0] == 'o') matrix[row_index][0] = 0;
        // rest of the characters
        for (int i = 1; i < line_ct; i++){
            if (row[i] == 'o') matrix[row_index][i] = 0;
            else matrix[row_index][i] = my_min(matrix[row_index][i - 1], matrix[row_index - 1][i], matrix[row_index - 1][i - 1]) + 1;
        }
        row_index++;
    }

    for (int i = 0; i < line_ct; i++){
        for (int j = 0; j < line_ct; j++){
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");


    return 0;
}