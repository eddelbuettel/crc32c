
/*
 *  crc32c -- Packge to provide crc32c as a C-callable function
 *
 *  Copyright (C) 2023  Dirk Eddelbuettel
 *
 *  This file is part of crc32c.
 *
 *  crc32c is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  crc32c is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with RApiSerialize.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


/* This header file provides the interface used by other packages, */
/* and should be included once per package.                        */

#ifndef _R_crc32cAPI_h_
#define _R_crc32cAPI_h_

/* number of R header files (possibly listing too many) */
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include <Rconfig.h>
#include <R_ext/Rdynload.h>

#ifdef HAVE_VISIBILITY_ATTRIBUTE
    # define attribute_hidden __attribute__ ((visibility ("hidden")))
#else
    # define attribute_hidden
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* provided the interface for the function exported 	*/
/* in ../src/init.c via R_RegisterCCallable()		*/

SEXP attribute_hidden c_crc32c(SEXP x) {
    static SEXP(*fun)(SEXP) = NULL;
    if (fun == NULL) fun = (SEXP(*)(SEXP)) R_GetCCallable("crc32c", "c_crc32c");
    return fun(x);
}

uint32_t attribute_hidden c_crc32c_uint8(const uint8_t* data, size_t count) {
    static uint32_t(*fun)(const uint8_t*, size_t) = NULL;
    if (fun == NULL)
        fun = (uint32_t(*)(const uint8_t*, size_t)) R_GetCCallable("crc32c", "c_crc32c_uint8");
    return fun(data, count);
}

uint32_t attribute_hidden c_crc32c_extend(uint32_t crc, const uint8_t* data, size_t count) {
    static uint32_t(*fun)(uint32_t, const uint8_t*, size_t) = NULL;
    if (fun == NULL)
        fun = (uint32_t(*)(uint32_t, const uint8_t*, size_t)) R_GetCCallable("crc32c", "c_crc32c_extend");
    return fun(crc, data, count);
}



#ifdef __cplusplus
}
#endif

#endif /* _R_crc32cAPI_h */
