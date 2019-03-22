
#include <R.h>
#include "seeds_ellipse.h"

SEXP seeds_ellipse_init(
    SEXP a,
    SEXP b) {

    int nprot = 0;

    double *ellipse_a, *ellipse_b;
    ellipse_a = REAL(a);
    ellipse_b = REAL(b);

    int ellipse_row = 100;
    int ellipse_col = 2;

    double start = -M_PI;
    //double fin = M_PI;
    double plus = 2 * M_PI / 99;


    SEXP ellipse_x, ellipse_y;
    SEXP ellipse;
    ellipse_x = PROTECT( allocVector(REALSXP, ellipse_row) ); nprot++;
    ellipse_y = PROTECT( allocVector(REALSXP, ellipse_row) ); nprot++;
    ellipse = PROTECT( allocVector(VECSXP, ellipse_col) ); nprot++;

    for(int i = 0; i < ellipse_row; i++) {

        REAL(ellipse_x)[i] = sin(start) * *ellipse_a;
        REAL(ellipse_y)[i] = cos(start) * *ellipse_b;

        start = start + plus;
    }

    SET_VECTOR_ELT(ellipse, 0, ellipse_x);
    SET_VECTOR_ELT(ellipse, 1, ellipse_y);

    return ellipse;
}

SEXP seeds_ellipse(
    SEXP a,
    SEXP b) {

    SEXP ellipse;

    PROTECT(ellipse = seeds_ellipse_init(a, b));

    setAttrib(ellipse, R_NamesSymbol, get_df_colnames(2));
    setAttrib(ellipse, R_RowNamesSymbol, get_df_rownames(100));
    setAttrib(ellipse, R_ClassSymbol, get_df_class());

    UNPROTECT(1);
    return ellipse;
}
