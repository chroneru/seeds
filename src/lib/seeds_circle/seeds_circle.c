
#include <R.h>
#include <Rmath.h>
#include "seeds_circle.h"

SEXP seeds_circle(SEXP radius) {
    // check integer
    if(seeds_check(radius)) {
        radius = coerceVector(radius, REALSXP);
    }

    SEXP circ;

    PROTECT(circ = seeds_ellipse_init(radius, radius));

    setAttrib(circ, R_NamesSymbol, get_df_colnames(2));
    setAttrib(circ, R_RowNamesSymbol, get_df_rownames(100));
    setAttrib(circ, R_ClassSymbol, get_df_class());



    UNPROTECT(1);
    return circ;
}
