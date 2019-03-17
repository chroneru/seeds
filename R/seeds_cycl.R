#' for plot cycloid, generate data.frame of tibble
#'
#' @param radius_m movable circle (Small circle)'s radius
#'
#' @export
#'
#' @examples
#' # return data.frame(row number is 1000)
#' seeds_cycl_df(2)
#'
#' # return tibble(row number is 1000)
#' seeds_cycl_tibble(2)
seeds_cycl_df <- function(radius_m = 1) {
    .Call(seeds_cycl, radius_m)
}
#' @rdname seeds_cycl_df
#' @export
seeds_cycl_tibble <- function(radius_m = 1) {
    as.tibble(seeds_cycl_df(radius_m))
}

#' plot cycloid
#'
#' @param radius_m movable circle (Small circle)'s radius
#' @param ... ggplot's option
#'
#' @export
#'
#' @examples
#' # ggplot cycloid
#' plot_cycl(3)
plot_cycl <- function(radius_m = 1, ...) {
    ggplot(seeds_cycl_tibble(radius_m), aes(x, y)) +
        geom_path(...)
}
