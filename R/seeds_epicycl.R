#' for plot epicycloid, generate data.frame of tibble
#'
#' @param radius_c constant circle (Large circle)'s radius
#' @param radius_m movable circle (Small circle)'s radius
#'
#' @export
#'
#' @examples
#' # return data.frame(row number is 1000)
#' seeds_epicycl_df(1, 2)
#'
#' # return tibble(row number is 1000)
#' seeds_epicycl_tibble(1, 2)
seeds_epicycl_df <- function(radius_c = 1, radius_m = 1) {
    .Call(seeds_epicycl, radius_c, radius_m)
}
#' @rdname seeds_epicycl_df
#' @export
seeds_epicycl_tibble <- function(radius_c = 1, radius_m = 1) {
    as.tibble(seeds_epicycl_df(radius_c, radius_m))
}

#' plot epicycloid
#'
#' @param radius_c constant circle (Large circle)'s radius
#' @param radius_m movable circle (Small circle)'s radius
#' @param ... ggplot's option
#'
#' @export
#'
#' @examples
#' # ggplot hypocycloid
#' plot_epicycl(1, 3)
plot_epicycl <- function(radius_c = 1, radius_m = 1, ...) {
    ggplot(seeds_epicycl_tibble(radius_c, radius_m), aes(x, y)) +
        geom_path(...)
}
