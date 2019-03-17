#' for plot circle, generate data.frame or tibble
#'
#' @param r circle's radius you want to plot
#'
#' @useDynLib seeds, .registration = TRUE
#' @import ggplot2
#' @importFrom tibble as.tibble
#'
#' @export
#'
#' @examples
#' # return data.frame(row number is 100)
#' seeds_circle_df()
#'
#' # return tibble(row number is 100)
#' seeds_circle_tibble()
seeds_circle_df <- function(r = 1) {
    .Call(seeds_circle, r)
}
#' @rdname seeds_circle_df
#' @export
seeds_circle_tibble <- function(r = 1) {
    as.tibble(seeds_circle_df(r))
}

#' plot circle
#'
#' @param r circle's radius you want to plot
#' @param ... ggplot's option
#'
#' @export
#'
#' @examples
#' # ggplot circle
#' plot_circle()
plot_circle <- function(r = 1, ...) {
    ggplot(seeds_circle_tibble(r), aes(x, y)) +
        geom_path(...)
}
