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

    // read first line, store as integer
    int line_ct = get_line_ct(fd);

    max_pt max_pt = create_matrix(fd, line_ct);

    // invalid map or no squares found
    if (max_pt.row == -1){
        write(2, "INVALID MAP", 11);
        return -1;
    } 
 
    close(fd);

    print_solution(av[1], max_pt, line_ct);

    close(fd);
    return 0;
}