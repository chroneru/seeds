#ifndef _SEEDS_PARAM_H_
#define _SEEDS_PARAM_H_

/* seeds_check */
extern int seeds_check(SEXP);

/* get_df */
extern SEXP get_df_class();
extern SEXP get_df_rownames(int);
extern SEXP get_df_colnames(int);

#include <Rinternals.h>

/*  r = a * sin(nsin / k * \theta) * b * cos(ncos / k * \theta)
    x = r * cos(\theta)
    y = r * sin(\theta)

    if(b = 1 && ncos = 0) { r = a * sin(nsin / k * \theta) }

    arguments:
    a
    b
    nsin
    ncos
    k
*/
SEXP seeds_param_init(SEXP, SEXP, SEXP, SEXP, SEXP);
SEXP seeds_param(SEXP, SEXP, SEXP, SEXP, SEXP);

#endif
