#' for plot rose curve, generate data.frame of tibble
#'
#' @param a coefficient of sin
#' @param nsin coefficient of sin's radian
#' @param k constant number
#'
#' @export
#'
#' @examples
#' # return data.frame(row number is 1000)
#' seeds_rose_df(1, 2, 1)
#'
#' # return tibble(row number is 1000)
#' seeds_rose_tibble(1, 2, 1)
seeds_rose_df <- function(a = 1, nsin = 1, k = 1) {
    .Call(seeds_rose, a, nsin, k)
}
#' @rdname seeds_rose_df
#' @export
seeds_rose_tibble <- function(a = 1, nsin = 1, k = 1) {
    as.tibble(seeds_rose_df(a, nsin, k))
}

#' plot rose curve
#'
#' @param a coefficient of sin
#' @param nsin coefficient of sin's radian
#' @param k constant number
#' @param ... ggplot's option
#'
#' @export
#'
#' @examples
#' # ggplot hypocycloid
#' plot_rose(1, 2, 1)
plot_rose <- function(a = 1, nsin = 1, k = 1, ...) {
    ggplot(seeds_rose_tibble(a, nsin, k), aes(x, y)) +
        geom_path(...)
}
