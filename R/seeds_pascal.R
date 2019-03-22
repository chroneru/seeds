#' for plot limacon of pascal, generate data.frame of tibble
#'
#' @param a coefficient of sin
#' @param l constant
#'
#' @export
#'
#' @examples
#' # return data.frame(row number is 1000)
#' seeds_pascal_df(1, 2)
#'
#' # return tibble(row number is 1000)
#' seeds_pascal_tibble(1)
seeds_pascal_df <- function(a = 1, l = 1) {
    .Call(seeds_pascal, a, l)
}
#' @rdname seeds_pascal_df
#' @export
seeds_pascal_tibble <- function(a = 1, l = 1) {
    as.tibble(seeds_pascal_df(a, l))
}

#' plot pascal curve
#'
#' @param a coefficient
#' @param l constant
#' @param ... ggplot's option
#'
#' @export
#'
#' @examples
#' # ggplot hypocycloid
#' plot_pascal(1)
plot_pascal <- function(a = 1, l = 1, ...) {
    ggplot(seeds_pascal_tibble(a, l), aes(x, y)) +
        geom_path(...)
}
