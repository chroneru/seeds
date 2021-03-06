% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/seeds_cycl.R
\name{seeds_cycl_df}
\alias{seeds_cycl_df}
\alias{seeds_cycl_tibble}
\title{for plot cycloid, generate data.frame of tibble}
\usage{
seeds_cycl_df(radius_m = 1)

seeds_cycl_tibble(radius_m = 1)
}
\arguments{
\item{radius_m}{movable circle (Small circle)'s radius}
}
\description{
for plot cycloid, generate data.frame of tibble
}
\examples{
# return data.frame(row number is 1000)
seeds_cycl_df(2)

# return tibble(row number is 1000)
seeds_cycl_tibble(2)
}
