#' for plot logarithmic spiral, generate data.frame or tibble
#'
#' @param a coefficient
#' @param b coefficient
#'
#' @export
#'
#' @examples
#' # return data.frame(row number is 1000)
#' seeds_log_spiral_df(2, 3)
#'
#' # return tibble(row number is 1000)
#' seeds_log_spiral_tibble(2, 3)
seeds_log_spiral_df <- function(a = 1, b = 1) {
    .Call(seeds_log_spiral, a, b)
}
#' @rdname seeds_log_spiral_df
#' @export
seeds_log_spiral_tibble <- function(a = 1, b = 1) {
    as.tibble(seeds_log_spiral_df(a, b))
}

#' plot log_spiral
#'
#' @param a coefficient
#' @param b coefficient
#' @param ... ggplot's option
#'
#' @export
#'
#' @examples
#' # ggplot log_spiral
#' plot_log_spiral(1, 0.2)
plot_log_spiral <- function(a = 1, b = 1, ...) {
    ggplot(seeds_log_spiral_tibble(a, b), aes(x, y)) +
        geom_path(...)
}
