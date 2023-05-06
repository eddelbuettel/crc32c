#' Cyclic Redundancy Check with Hardware Support
#'
#' The \code{crc32c} implementation with hardware support via SSE2 instructions
#' on \sQuote{x86_64} platforms as well as on \sQuote{arm64} is provided by using
#' the code from the repository at \url{https://github.com/google/crc32c}.
#'
#' @param x A character vector
#' @return A character vector of the same length as the incoming vector, with a
#' \code{crc43c} checksum in hexadecimal as a character value of length eight in each
#' element.
#'
#' @seealso https://github.com/google/crc32c
#' @references https://datatracker.ietf.org/doc/html/rfc3720, doi:10.1109/26.231911
#' @examples
#' crc32c("abc")
crc32c <- function(x) {
    stopifnot("Argument 'x' for 'crc32c()' must be of type 'character'" = is.character(x))
    .Call(c_crc32c, x)
}
