#include <R.h>
#include "seeds_param.h"

SEXP seeds_param_init(
        SEXP a,
        SEXP b,
        SEXP nsin,
        SEXP ncos,
        SEXP k) {

    int nprot = 0;

    double *param_a, *param_b, *param_nsin, *param_ncos, *param_k;
    param_a = REAL(a);
    param_b = REAL(b);
    param_nsin = REAL(nsin);
    param_ncos = REAL(ncos);
    param_k = REAL(k);

    int param_row = 1000;
    int param_col = 2;

    double start = - *param_k * M_PI;
    //double fin = *param_k * M_PI;
    double plus = 2 * *param_k * M_PI / (param_row - 1);


    SEXP param_x, param_y;
    SEXP param;
    param_x = PROTECT( allocVector(REALSXP, param_row) ); nprot++;
    param_y = PROTECT( allocVector(REALSXP, param_row) ); nprot++;
    param = PROTECT( allocVector(VECSXP, param_col) ); nprot++;

    for(int i = 0; i < param_row; i++) {

        REAL(param_x)[i] = *param_a * sin(*param_nsin / *param_k * start) *
                           *param_b * cos(*param_ncos / *param_k * start) *
                           cos(start);
        REAL(param_y)[i] = *param_a * sin(*param_nsin / *param_k * start) *
                           *param_b * cos(*param_ncos / *param_k * start) *
                           sin(start);

        start = start + plus;
    }

    SET_VECTOR_ELT(param, 0, param_x);
    SET_VECTOR_ELT(param, 1, param_y);

    UNPROTECT(nprot);
    return param;
}

SEXP seeds_param(
        SEXP a,
        SEXP b,
        SEXP nsin,
        SEXP ncos,
        SEXP k) {
    // check integer
    if(seeds_check(a)) {
        a = coerceVector(a, REALSXP);
    }
    if(seeds_check(b)) {
        b = coerceVector(b, REALSXP);
    }
    if(seeds_check(nsin)) {
        nsin = coerceVector(nsin, REALSXP);
    }
    if(seeds_check(ncos)) {
        ncos = coerceVector(ncos, REALSXP);
    }
    if(seeds_check(k)) {
        k = coerceVector(k, REALSXP);
    }

    SEXP param;

    PROTECT(param = seeds_param_init(a, b, nsin, ncos, k));

    setAttrib(param, R_NamesSymbol, get_df_colnames(2));
    setAttrib(param, R_RowNamesSymbol, get_df_rownames(1000));
    setAttrib(param, R_ClassSymbol, get_df_class());

    UNPROTECT(1);
    return param;
}
