#include <R.h>
#include <string.h>
#include "seeds_cycl.h"

SEXP seeds_cycl_init(
        SEXP radius_c,
        SEXP radius_m,
        int func_num) {

    int nprot = 0;

    double *cycl_radius_c, *cycl_radius_m;
    cycl_radius_c = REAL(radius_c);
    cycl_radius_m = REAL(radius_m);

    int cycl_row = 1000;
    int cycl_col = 2;

    double start = - 4 * M_PI;
    //double fin = 4 * M_PI;
    double plus = 8 * M_PI / (cycl_row - 1);


    SEXP cycl_x, cycl_y;
    SEXP cycl;
    cycl_x = PROTECT( allocVector(REALSXP, cycl_row) ); nprot++;
    cycl_y = PROTECT( allocVector(REALSXP, cycl_row) ); nprot++;
    cycl = PROTECT( allocVector(VECSXP, cycl_col) ); nprot++;

    for(int i = 0; i < cycl_row; i++) {

        REAL(cycl_x)[i] = cycl_x_calc(*cycl_radius_c, *cycl_radius_m, start, func_num);
        REAL(cycl_y)[i] = cycl_y_calc(*cycl_radius_c, *cycl_radius_m, start, func_num);

        start = start + plus;
    }

    SET_VECTOR_ELT(cycl, 0, cycl_x);
    SET_VECTOR_ELT(cycl, 1, cycl_y);

    UNPROTECT(nprot);
    return cycl;
}

SEXP seeds_cycl(SEXP radius_m) {
    //check integer
    if(seeds_check(radius_m)) {
        radius_m = coerceVector(radius_m, REALSXP);
    }

    SEXP cycl;

    SEXP radius_c;
    radius_c = allocVector(REALSXP, 1);
    REAL(radius_c)[0] = 1;

    PROTECT(cycl = seeds_cycl_init(radius_c, radius_m, 0));

    setAttrib(cycl, R_NamesSymbol, get_df_colnames(2));
    setAttrib(cycl, R_RowNamesSymbol, get_df_rownames(1000));
    setAttrib(cycl, R_ClassSymbol, get_df_class());

    UNPROTECT(2);
    return cycl;
}

SEXP seeds_epicycl(SEXP radius_c, SEXP radius_m) {
    // check integer
    if(seeds_check(radius_c)) {
        radius_c = coerceVector(radius_c, REALSXP);
    }
    if(seeds_check(radius_m)) {
        radius_m = coerceVector(radius_m, REALSXP);
    }

    SEXP cycl;

    PROTECT(cycl = seeds_cycl_init(radius_c, radius_m, 1));

    setAttrib(cycl, R_NamesSymbol, get_df_colnames(2));
    setAttrib(cycl, R_RowNamesSymbol, get_df_rownames(1000));
    setAttrib(cycl, R_ClassSymbol, get_df_class());

    UNPROTECT(1);
    return cycl;
}

SEXP seeds_hypocycl(SEXP radius_c, SEXP radius_m) {
    // check integer
    if(seeds_check(radius_c)) {
        radius_c = coerceVector(radius_c, REALSXP);
    }
    if(seeds_check(radius_m)) {
        radius_m = coerceVector(radius_m, REALSXP);
    }

    SEXP cycl;

    PROTECT(cycl = seeds_cycl_init(radius_c, radius_m, 2));

    setAttrib(cycl, R_NamesSymbol, get_df_colnames(2));
    setAttrib(cycl, R_RowNamesSymbol, get_df_rownames(1000));
    setAttrib(cycl, R_ClassSymbol, get_df_class());

    UNPROTECT(1);
    return cycl;
}
