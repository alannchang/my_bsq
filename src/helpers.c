#include "../include/helpers.h"

int check_arg_ct(int ac){
    if (ac != 2){
        write(2, "ERROR",5);
        return -1;
    }
    return 0;
}