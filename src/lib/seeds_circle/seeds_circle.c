
#include <R.h>
#include <Rdefines.h>
#include <Rinternals.h>
#include <Rmath.h>
#include "seeds_circle.h"

SEXP seeds_circle(SEXP radius) {
    /* // check integer
    if(TYPEOF(radius) == INTSXP) {
        warning("this argument is integer, coerce numeric!");

        radius = AS_NUMERIC(radius);
    }
    */

    // check numeric
    if(TYPEOF(radius) != REALSXP) {
        error("argument is not numeric.");
    }

    // check one-size
    if(length(radius) != 1) {
        warning("this argument is not an element!");
    }

    SEXP circ;

    PROTECT(circ = seeds_ellipse_init(radius, radius));

    setAttrib(circ, R_NamesSymbol, get_df_colnames(2));
    setAttrib(circ, R_RowNamesSymbol, get_df_rownames(100));
    setAttrib(circ, R_ClassSymbol, get_df_class());



    UNPROTECT(1);
    return circ;
}
