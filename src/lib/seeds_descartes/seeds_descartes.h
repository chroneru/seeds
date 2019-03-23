#ifndef _SEEDS_DESCARTES_H_
#define _SEEDS_DESCARTES_H_

/* seeds_check */
extern int seeds_check(SEXP);

/* get_df */
extern SEXP get_df_class();
extern SEXP get_df_rownames(int);
extern SEXP get_df_colnames(int);

#include <Rinternals.h>

SEXP seeds_descartes_init(SEXP);
double seeds_descartes_calc(double, double);
SEXP seeds_descartes(SEXP);

#endif
