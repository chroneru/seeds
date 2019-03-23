
#include <R.h>
#include "seeds_log_spiral.h"

SEXP seeds_log_spiral_init(SEXP a, SEXP b) {

    int nprot = 0;

    double *log_spiral_a, *log_spiral_b;
    log_spiral_a = REAL(a);
    log_spiral_b = REAL(b);

    int log_spiral_row = 1000;
    int log_spiral_col = 2;

    double start = -M_PI;
    //double fin = 5 * M_PI;
    double plus = 6 * M_PI / 999;


    SEXP log_spiral_x, log_spiral_y;
    SEXP log_spiral;
    log_spiral_x = PROTECT( allocVector(REALSXP, log_spiral_row) ); nprot++;
    log_spiral_y = PROTECT( allocVector(REALSXP, log_spiral_row) ); nprot++;
    log_spiral = PROTECT( allocVector(VECSXP, log_spiral_col) ); nprot++;

    for(int i = 0; i < log_spiral_row; i++) {

        REAL(log_spiral_x)[i] = seeds_log_spiral_calc(
                                *log_spiral_a, *log_spiral_b, start
                                ) * cos(start);
        REAL(log_spiral_y)[i] = seeds_log_spiral_calc(
                                *log_spiral_a, *log_spiral_b, start
                                ) * sin(start);

        start = start + plus;
    }

    SET_VECTOR_ELT(log_spiral, 0, log_spiral_x);
    SET_VECTOR_ELT(log_spiral, 1, log_spiral_y);

    return log_spiral;
}

double seeds_log_spiral_calc(double a, double b, double radian) {
    double radius = 0;

    radius = a * exp(b * radian);

    return radius;
}


SEXP seeds_log_spiral(SEXP a, SEXP b) {
    // check integer
    if(seeds_check(a)) {
        a = coerceVector(a, REALSXP);
    }
    if(seeds_check(b)) {
        b = coerceVector(b, REALSXP);
    }

    SEXP log_spiral;

    PROTECT(log_spiral = seeds_log_spiral_init(a, b));

    setAttrib(log_spiral, R_NamesSymbol, get_df_colnames(2));
    setAttrib(log_spiral, R_RowNamesSymbol, get_df_rownames(1000));
    setAttrib(log_spiral, R_ClassSymbol, get_df_class());

    UNPROTECT(1);
    return log_spiral;
}
