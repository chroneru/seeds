
#include <R.h>
#include "seeds_pascal.h"

SEXP seeds_pascal_init(SEXP a, SEXP l) {

    int nprot = 0;

    double *pascal_a, *pascal_l;
    pascal_a = REAL(a);
    pascal_l = REAL(l);

    int pascal_row = 100;
    int pascal_col = 2;

    double start = -M_PI;
    //double fin = M_PI;
    double plus = 2 * M_PI / 99;


    SEXP pascal_x, pascal_y;
    SEXP pascal;
    pascal_x = PROTECT( allocVector(REALSXP, pascal_row) ); nprot++;
    pascal_y = PROTECT( allocVector(REALSXP, pascal_row) ); nprot++;
    pascal = PROTECT( allocVector(VECSXP, pascal_col) ); nprot++;

    for(int i = 0; i < pascal_row; i++) {

        REAL(pascal_x)[i] = seeds_pascal_calc(*pascal_a, *pascal_l, start) *
                               cos(start);
        REAL(pascal_y)[i] = seeds_pascal_calc(*pascal_a, *pascal_l, start) *
                               sin(start);

        start = start + plus;
    }

    SET_VECTOR_ELT(pascal, 0, pascal_x);
    SET_VECTOR_ELT(pascal, 1, pascal_y);

    return pascal;
}

double seeds_pascal_calc(double a, double l, double radian) {
    double radius = 0;

    radius = a * cos(radian) + l;

    return radius;
}


SEXP seeds_pascal(SEXP a, SEXP l) {
    // check integer
    if(seeds_check(a)) {
        a = coerceVector(a, REALSXP);
    }
    if(seeds_check(l)) {
        l = coerceVector(l, REALSXP);
    }

    SEXP pascal;

    PROTECT(pascal = seeds_pascal_init(a, l));

    setAttrib(pascal, R_NamesSymbol, get_df_colnames(2));
    setAttrib(pascal, R_RowNamesSymbol, get_df_rownames(100));
    setAttrib(pascal, R_ClassSymbol, get_df_class());

    UNPROTECT(1);
    return pascal;
}
