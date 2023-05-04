
crc32c <- function(x) {
    .Call(c_crc32c, x)
}
