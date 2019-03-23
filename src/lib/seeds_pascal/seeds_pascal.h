#ifndef _SEEDS_PASCAL_H_
#define _SEEDS_PASCAL_H_

/* seeds_check */
extern int seeds_check(SEXP);

/* get_df */
extern SEXP get_df_class();
extern SEXP get_df_rownames(int);
extern SEXP get_df_colnames(int);

#include <Rinternals.h>

SEXP seeds_pascal_init(SEXP, SEXP);
double seeds_pascal_calc(double, double, double);
SEXP seeds_pascal(SEXP, SEXP);

#endif
