#ifndef _SEEDS_CIRCLE_H_
#define _SEEDS_CIRCLE_H_

/* seeds_check */
extern int seeds_check(SEXP);

/* get_df */
extern SEXP get_df_class(void);
extern SEXP get_df_rownames(int);
extern SEXP get_df_colnames(int);

extern SEXP seeds_ellipse_init(SEXP, SEXP);

#include <Rinternals.h>

/* return vec(x, y), for plot circle */
SEXP seeds_circle(SEXP);

#endif
