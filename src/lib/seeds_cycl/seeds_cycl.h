#ifndef _SEEDS_CYCL_H_
#define _SEEDS_CYCL_H_

/* seeds_check */
extern int seeds_check(SEXP);

/* get_df */
extern SEXP get_df_class();
extern SEXP get_df_rownames(int);
extern SEXP get_df_colnames(int);

#include <Rinternals.h>

double cycl_x_calc(double, double, double, int);
double cycl_y_calc(double, double, double, int);

SEXP seeds_cycl_init(SEXP, SEXP, int);
SEXP seeds_cycl(SEXP);
SEXP seeds_epicycl(SEXP, SEXP);
SEXP seeds_hypocycl(SEXP, SEXP);

#endif
