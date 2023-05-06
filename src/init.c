
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

#include <Rconfig.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>
#include <stdint.h>             /* for uint8_t and uint32_t */

/*  function declarations -- could be in external header file if used  */
/*  by functions in anotherfile in this package                        */
SEXP c_crc32c(SEXP sx);
uint32_t c_crc32c_uint8(const uint8_t* data, size_t count);
uint32_t c_crc32c_extend(uint32_t crc, const uint8_t* data, size_t count);

/* definition of functions provided for .Call() 			*/
static const R_CallMethodDef callMethods[] = {
    { "c_crc32c",	(DL_FUNC) &c_crc32c,		1 },
    { NULL,            	NULL,                     	0 }
};


/* functions being called when package is loaded -- used to register 	*/
/* the functions we are exporting here					*/
void R_init_crc32c(DllInfo *info) {

    /* used by external packages linking to crc32c function from C */
    R_RegisterCCallable("crc32c", "c_crc32c",        (DL_FUNC) &c_crc32c);
    R_RegisterCCallable("crc32c", "c_crc32c_uint8",  (DL_FUNC) &c_crc32c_uint8);
    R_RegisterCCallable("crc32c", "c_crc32c_extend", (DL_FUNC) &c_crc32c_extend);

    R_registerRoutines(info,
                       NULL,		/* slot for .C */
                       callMethods, 	/* slot for .Call */
                       NULL,            /* slot for .Fortran */
                       NULL);   	/* slot for .External */

    R_useDynamicSymbols(info, TRUE);    /* controls visibility */

}
