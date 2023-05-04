
#include <tidyCpp>
#include <crc32c/crc32c.h>

// The following three interfaces are exported. We use the third one here.
//
// Extends "crc" with the CRC32C of "count" bytes in the buffer pointed by "data".
uint32_t crc32c::Extend(uint32_t crc, const uint8_t* data, size_t count);
// Computes the CRC32C of "count" bytes in the buffer pointed by "data".
uint32_t Crc32c(const uint8_t* data, size_t count);
// Computes the CRC32C of "count" bytes in the buffer pointed by "data".
uint32_t Crc32c(const char* data, size_t count);
// Computes the CRC32C of the string's content.
uint32_t Crc32c(const std::string& string);

extern "C" SEXP c_crc32c(SEXP sx) {
    std::string s(R::asCharacter(sx));
    uint32_t val = crc32c::Crc32c(s);
    char buf[9];
    snprintf(buf, 9, "%08x", val);
    R::Protect res(R::allocVectorCharacter(1));
    R::setStringElement(res, 0, R::mkChar(buf));
    return res;
}
