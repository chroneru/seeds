#' for plot descartes curve, generate data.frame of tibble
#'
#' @param a coefficient of sin
#'
#' @export
#'
#' @examples
#' # return data.frame(row number is 1000)
#' seeds_descartes_df(1)
#'
#' # return tibble(row number is 1000)
#' seeds_descartes_tibble(1)
seeds_descartes_df <- function(a = 1) {
    .Call(seeds_descartes, a)
}
#' @rdname seeds_descartes_df
#' @export
seeds_descartes_tibble <- function(a = 1) {
    as.tibble(seeds_descartes_df(a))
}

#' plot descartes curve
#'
#' @param a coefficient
#' @param ... ggplot's option
#'
#' @export
#'
#' @examples
#' # ggplot hypocycloid
#' plot_descartes(1)
plot_descartes <- function(a = 1, ...) {
    ggplot(seeds_descartes_tibble(a), aes(x, y)) +
        geom_path(...)
}
