
#include <tidyCpp>
#include <crc32c/crc32c.h>

// The following three interfaces are exported. We use the third one here.
//
// Extends "crc" with the CRC32C of "count" bytes in the buffer pointed by "data".
uint32_t crc32c::Extend(uint32_t crc, const uint8_t* data, size_t count);
// Computes the CRC32C of "count" bytes in the buffer pointed by "data".
uint32_t crc32c::Crc32c(const uint8_t* data, size_t count);
// Computes the CRC32C of "count" bytes in the buffer pointed by "data".
uint32_t crc32c::Crc32c(const char* data, size_t count);
// Computes the CRC32C of the string's content.
uint32_t crc32c::Crc32c(const std::string& string);

extern "C" SEXP c_crc32c(SEXP sx) {
    R_xlen_t n = R::length(sx);
    R::Protect res(R::allocVectorCharacter(n));
    for (auto i = 0; i < n; i++) {
        std::string s(R::asCharacter(R::stringElement(sx, i)));
        uint32_t val = crc32c::Crc32c(s);
        char buf[9];
        snprintf(buf, 9, "%08x", val);
        R::setStringElement(res, i, R::mkChar(buf));
    }
    return res;
}

extern "C" uint32_t c_crc32c_uint8(const uint8_t* data, size_t count) {
    return crc32c::Crc32c(data, count);
}

extern "C" uint32_t c_crc32c_extend(uint32_t crc, const uint8_t* data, size_t count) {
    return crc32c::Extend(crc, data, count);
}
