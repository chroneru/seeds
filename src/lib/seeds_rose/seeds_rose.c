#include <R.h>
#include "seeds_rose.h"

SEXP seeds_rose(
        SEXP a,
        SEXP nsin,
        SEXP k) {

    int nprot = 0;

    SEXP rose;
    SEXP b, ncos;
    PROTECT(b = allocVector(REALSXP, 1)); nprot++;
    PROTECT(ncos = allocVector(REALSXP, 1)); nprot++;

    REAL(b)[0] = 1;
    REAL(ncos)[0] = 0;

    rose = PROTECT(seeds_param_init(a, b, nsin, ncos, k)); nprot++;

    setAttrib(rose, R_NamesSymbol, get_df_colnames(2));
    setAttrib(rose, R_RowNamesSymbol, get_df_rownames(1000));
    setAttrib(rose, R_ClassSymbol, get_df_class());

    UNPROTECT(nprot);
    return rose;
}
