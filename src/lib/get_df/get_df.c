#include <stdio.h>

#include <R.h>
#include <Rdefines.h>
#include <Rinternals.h>
#include "get_df.h"

SEXP get_df_class() {
    SEXP cls;

    PROTECT(cls = NEW_CHARACTER(1));

    SET_STRING_ELT(cls, 0, mkChar("data.frame"));

    UNPROTECT(1);
    return cls;
}

SEXP get_df_rownames(int nrow) {
    SEXP rowname;
    char c_rowname[MAX_SIZE];

    PROTECT(rowname = NEW_CHARACTER(nrow));

    for(int i = 0; i < nrow; i++) {
        snprintf(c_rowname, MAX_SIZE, "%d", i + 1);

        SET_STRING_ELT(rowname, i, mkChar(c_rowname));
    }

    UNPROTECT(1);
    return rowname;
}

SEXP get_df_colnames(int ncol) {
    SEXP colname;

    PROTECT(colname = allocVector(STRSXP, ncol));

    switch(ncol) {

        case 1:
            SET_STRING_ELT(colname, 0, mkChar("x"));
            break;

        case 2:
            SET_STRING_ELT(colname, 0, mkChar("x"));
            SET_STRING_ELT(colname, 1, mkChar("y"));
            break;

        case 3:
            SET_STRING_ELT(colname, 0, mkChar("x"));
            SET_STRING_ELT(colname, 1, mkChar("y"));
            SET_STRING_ELT(colname, 2, mkChar("z"));
            break;

        default:
            error("number of col must be either, 0, 1, 2");
    }

    UNPROTECT(1);
    return colname;
}

