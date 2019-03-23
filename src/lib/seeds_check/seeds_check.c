
#include <R.h>
#include "seeds_check.h"

int seeds_check(SEXP checked) {
    int status = 0;

    /* size check */
    if(length(checked) != 1) {
        warning("this argument is not an element!");
    }

    /* type check */
    switch(TYPEOF(checked)) {
        case REALSXP:
            return status;
            break;

        case INTSXP:
            warning("this argument is integer, coerce numeric!");
            status = 1;
            break;

        default:
            error("this argument is not numeric.");
            return status;
    }
}
