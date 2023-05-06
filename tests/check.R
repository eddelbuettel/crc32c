
library(crc32c)

## Known test vectors
crc32cInput <- c("123456789", "The quick brown fox jumps over the lazy dog")
crc32cOutput <- c("e3069283", "22620404")

stopifnot( all.equal( crc32c(crc32cInput), crc32cOutput ) )
