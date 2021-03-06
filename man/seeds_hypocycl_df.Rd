% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/seeds_hypocycl.R
\name{seeds_hypocycl_df}
\alias{seeds_hypocycl_df}
\alias{seeds_hypocycl_tibble}
\title{for plot hypocycloid, generate data.frame of tibble}
\usage{
seeds_hypocycl_df(radius_c = 1, radius_m = 1)

seeds_hypocycl_tibble(radius_c = 1, radius_m = 1)
}
\arguments{
\item{radius_c}{constant circle (Large circle)'s radius}

\item{radius_m}{movable circle (Small circle)'s radius}
}
\description{
for plot hypocycloid, generate data.frame of tibble
}
\examples{
# return data.frame(row number is 1000)
seeds_hypocycl_df(1, 2)

# return tibble(row number is 1000)
seeds_hypocycl_tibble(1, 2)
}
