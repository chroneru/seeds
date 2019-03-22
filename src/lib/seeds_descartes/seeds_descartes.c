
#include <R.h>
#include "seeds_descartes.h"

SEXP seeds_descartes_init(SEXP a) {

    int nprot = 0;

    double *descartes_a;
    descartes_a = REAL(a);

    int descartes_row = 100;
    int descartes_col = 2;

    double start = -M_PI;
    //double fin = M_PI;
    double plus = 2 * M_PI / 99;


    SEXP descartes_x, descartes_y;
    SEXP descartes;
    descartes_x = PROTECT( allocVector(REALSXP, descartes_row) ); nprot++;
    descartes_y = PROTECT( allocVector(REALSXP, descartes_row) ); nprot++;
    descartes = PROTECT( allocVector(VECSXP, descartes_col) ); nprot++;

    for(int i = 0; i < descartes_row; i++) {

        REAL(descartes_x)[i] = seeds_descartes_calc(*descartes_a, start) *
                               cos(start);
        REAL(descartes_y)[i] = seeds_descartes_calc(*descartes_a, start) *
                               sin(start);

        start = start + plus;
    }

    SET_VECTOR_ELT(descartes, 0, descartes_x);
    SET_VECTOR_ELT(descartes, 1, descartes_y);

    return descartes;
}

double seeds_descartes_calc(double a, double radian) {
    double radius = 0;

    radius = 3 * a * sin(radian) * cos(radian)/
            (pow(sin(radian), 3) + pow(cos(radian), 3));

    return radius;
}


SEXP seeds_descartes(SEXP a) {
    // check integer
    if(seeds_check(a)) {
        a = coerceVector(a, REALSXP);
    }

    SEXP descartes;

    PROTECT(descartes = seeds_descartes_init(a));

    setAttrib(descartes, R_NamesSymbol, get_df_colnames(2));
    setAttrib(descartes, R_RowNamesSymbol, get_df_rownames(100));
    setAttrib(descartes, R_ClassSymbol, get_df_class());

    UNPROTECT(1);
    return descartes;
}
