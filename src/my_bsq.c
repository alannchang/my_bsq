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

    int fd;

    if ((fd = open(av[1], O_RDONLY)) == -1){
        write(2, "FILE ERROR", 10);
        return -1;
    }

    dimensions dim;
    if ((dim.rows = get_line_ct(fd)) == -1 ) return -1;

    max_pt max_pt = get_max_pt(fd, dim.rows);

    if (max_pt.row == -1){ // invalid map or no squares found
        write(2, "INVALID MAP", 11);
        return -1;
    }

    max_pt.val--; // easier value to work with
    print_solution(av[1], max_pt, dim.rows);

    return 0;
}