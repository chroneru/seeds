#ifndef _SEEDS_ROSE_H_
#define _SEEDS_ROSE_H_

/* seeds_param.h */
extern SEXP seeds_param_init(SEXP, SEXP, SEXP, SEXP, SEXP);

/* get_df.h */
extern SEXP get_df_class();
extern SEXP get_df_rownames(int);
extern SEXP get_df_colnames(int);

#include <Rinternals.h>
SEXP seeds_rose(SEXP, SEXP, SEXP);

#endif
