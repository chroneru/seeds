#ifndef _SEEDS_LOG_SPIRAL_H_
#define _SEEDS_LOG_SPIRAL_H_

/* seeds_check */
extern int seeds_check(SEXP);

/* get_df */
extern SEXP get_df_class();
extern SEXP get_df_rownames(int);
extern SEXP get_df_colnames(int);

#include <Rinternals.h>

SEXP seeds_log_spiral_init(SEXP, SEXP);
double seeds_log_spiral_calc(double, double, double);
SEXP seeds_log_spiral(SEXP, SEXP);

#endif
