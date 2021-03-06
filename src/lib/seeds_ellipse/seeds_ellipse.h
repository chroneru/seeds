#ifndef _SEEDS_ELLIPSE_H_
#define _SEEDS_ELLIPSE_H_

/* seeds_check */
extern int seeds_check(SEXP);

/* get_df */
extern SEXP get_df_class();
extern SEXP get_df_rownames(int);
extern SEXP get_df_colnames(int);

#include <Rinternals.h>

SEXP seeds_ellipse_init(SEXP, SEXP);
SEXP seeds_ellipse(SEXP, SEXP);

#endif
