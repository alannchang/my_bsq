#include "../include/my_bsq.h"

int main(int ac, char** av){

    if(check_arg_ct(ac) != 0) return -1;

    int fd;

    if ((fd = open(av[1], O_RDONLY)) == EXIT_FAILURE){
        write(2, "FILE ERROR", 10);
        return EXIT_FAILURE;
    }

    dimensions dim;
    if ((dim.rows = get_line_ct(fd)) == EXIT_FAILURE ) return EXIT_FAILURE;

    char *first_row;
    if ((first_row = my_readline(fd)) == NULL) {
        write(2, "INVALID MAP", 11);
        return EXIT_FAILURE;
    }
        
    dim.cols = my_strlen(first_row);

    max_pt max_pt = get_max_pt(fd, first_row, dim);

    if (max_pt.row == -1){ // invalid map or no bsq found or mem allocation failure
        write(2, "MAP ERROR", 9);
        return EXIT_FAILURE;
    }

    max_pt.val--; // easier value to work with
    print_solution(av[1], max_pt, dim);

    return EXIT_SUCCESS;
}