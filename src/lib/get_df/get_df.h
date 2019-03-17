#ifndef _GET_DF_H_
#define _GET_DF_H_

#define MAX_SIZE 256

#include <Rinternals.h>

SEXP get_df_class();
SEXP get_df_rownames(int);
SEXP get_df_colnames(int);

#endif
