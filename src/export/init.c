
#include <Rinternals.h>
#include <R_ext/Rdynload.h>
//#include <rlang.h>

extern SEXP seeds_param(SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP seeds_rose(SEXP, SEXP, SEXP);
extern SEXP seeds_ellipse(SEXP, SEXP);
extern SEXP seeds_circle(SEXP);

extern SEXP seeds_cycl(SEXP);
extern SEXP seeds_epicycl(SEXP, SEXP);
extern SEXP seeds_hypocycl(SEXP, SEXP);
/* seeds_pascal */
extern SEXP seeds_pascal(SEXP, SEXP);

extern SEXP seeds_descartes(SEXP);

static const R_CallMethodDef r_callables[] = {
    {"seeds_param", (DL_FUNC) &seeds_param, 5},
    {"seeds_rose", (DL_FUNC) &seeds_rose, 3},

    {"seeds_ellipse", (DL_FUNC) &seeds_ellipse, 2},
    {"seeds_circle", (DL_FUNC) &seeds_circle, 1},

    {"seeds_cycl", (DL_FUNC) &seeds_cycl, 1},
    {"seeds_epicycl", (DL_FUNC) &seeds_epicycl, 2},
    {"seeds_hypocycl", (DL_FUNC) &seeds_hypocycl, 2},
    {"seeds_pascal", (DL_FUNC) &seeds_pascal, 2},

    {"seeds_descartes", (DL_FUNC) &seeds_descartes, 1},
    {NULL, NULL, 0}
};

/*
void R_init_seeds(r_dll_info* dll) {
    r_register_c_callable("seeds", "C_seeds_circle", (r_fn_ptr) &C_seeds_circle);
}
*/

void R_init_seeds(DllInfo *info) {
    /*
    R_RegisterCCallable("seeds", "seeds_param", (DL_FUNC) &seeds_param);
    R_RegisterCCallable("seeds", "seeds_rose", (DL_FUNC) &seeds_rose);
    R_RegisterCCallable("seeds", "seeds_ellipse", (DL_FUNC) &seeds_ellipse);
    R_RegisterCCallable("seeds", "seeds_circle", (DL_FUNC) &seeds_circle);

    R_RegisterCCallable("seeds", "seeds_cycl", (DL_FUNC) &seeds_cycl);
    R_RegisterCCallable("seeds", "seeds_epicycl", (DL_FUNC) &seeds_epicycl);
    R_RegisterCCallable("seeds", "seeds_hypocycl", (DL_FUNC) &seeds_hypocycl);
    */
    R_registerRoutines(info, NULL, r_callables, NULL, NULL);
    R_useDynamicSymbols(info, FALSE);

}
