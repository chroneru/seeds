#' for plot ellipse, generate data.frame or tibble
#'
#' @param a sin's coefficient
#' @param b cos's coefficient
#'
#' @export
#'
#' @examples
#' # return data.frame(row number is 100)
#' seeds_ellipse_df(2, 3)
#'
#' # return tibble(row number is 100)
#' seeds_ellipse_tibble(2, 3)
seeds_ellipse_df <- function(a = 1, b = 1) {
    .Call(seeds_ellipse, a, b)
}
#' @rdname seeds_ellipse_df
#' @export
seeds_ellipse_tibble <- function(a = 1, b = 1) {
    as.tibble(seeds_ellipse_df(a, b))
}

#' plot ellipse
#'
#' @param a sin's coefficient
#' @param b cos's coefficient
#' @param ... ggplot's option
#'
#' @export
#'
#' @examples
#' # ggplot ellipse
#' plot_ellipse(2, 3)
plot_ellipse <- function(a = 1, b = 1, ...) {
    ggplot(seeds_ellipse_tibble(a, b), aes(x, y)) +
        geom_path(...)
}
