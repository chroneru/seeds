#' for plot parameter representation, generate data.frame of tibble
#'
#' @param a coefficient of sin
#' @param b coefficient of cos
#' @param nsin coefficient of sin's radian
#' @param ncos coefficient of cos's radian
#' @param k constant number
#'
#' @export
#'
#' @examples
#' # return data.frame(row number is 1000)
#' seeds_param_df(2, 3, 4, 5, 2)
#'
#' # return tibble(row number is 1000)
#' seeds_param_tibble(2, 3, 4, 5, 2)
seeds_param_df <- function(a = 1, b = 1, nsin = 1, ncos = 0, k = 1) {
    .Call(seeds_param, a, b, nsin, ncos, k)
}
#' @rdname seeds_param_df
#' @export
seeds_param_tibble <- function(a = 1, b = 1, nsin = 1, ncos = 0, k = 1) {
    as.tibble(seeds_param_df(a, b, nsin, ncos, k))
}

#' plot parameter representation
#'
#' @param a coefficient of sin
#' @param b coefficient of cos
#' @param nsin coefficient of sin's radian
#' @param ncos coefficient of cos's radian
#' @param k constant number
#' @param ... ggplot's option
#'
#' @export
#'
#' @examples
#' # ggplot parameter representation
#' plot_param(2, 3, 4, 5, 2)
plot_param <- function(a = 1, b = 1, nsin = 1, ncos = 0, k = 1, ...) {
    ggplot(seeds_param_tibble(a, b, nsin, ncos, k), aes(x, y)) +
        geom_path(...)
}
