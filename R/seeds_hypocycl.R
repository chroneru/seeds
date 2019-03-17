#' for plot hypocycloid, generate data.frame of tibble
#'
#' @param radius_c constant circle (Large circle)'s radius
#' @param radius_m movable circle (Small circle)'s radius
#'
#' @export
#'
#' @examples
#' # return data.frame(row number is 1000)
#' seeds_hypocycl_df(1, 2)
#'
#' # return tibble(row number is 1000)
#' seeds_hypocycl_tibble(1, 2)
seeds_hypocycl_df <- function(radius_c = 1, radius_m = 1) {
    .Call(seeds_hypocycl, radius_c, radius_m)
}
#' @rdname seeds_hypocycl_df
#' @export
seeds_hypocycl_tibble <- function(radius_c = 1, radius_m = 1) {
    as.tibble(seeds_hypocycl_df(radius_c, radius_m))
}

#' plot hypocycloid
#'
#' @param radius_c constant circle (Large circle)'s radius
#' @param radius_m movable circle (Small circle)'s radius
#' @param ... ggplot's option
#'
#' @export
#'
#' @examples
#' # ggplot hypocycloid
#' plot_hypocycl(1, 3)
plot_hypocycl <- function(radius_c = 1, radius_m = 1, ...) {
    ggplot(seeds_hypocycl_tibble(radius_m), aes(x, y)) +
        geom_path(...)
}
