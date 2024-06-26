
## crc32c: R Bindings for the CRC32C Library

[![CI](https://github.com/eddelbuettel/crc32c/workflows/ci/badge.svg)](https://github.com/eddelbuettel/crc32c/actions?query=workflow%3Aci)
[![License](https://eddelbuettel.github.io/badges/GPL2+.svg)](https://www.gnu.org/licenses/gpl-2.0.html)
[![CRAN](https://www.r-pkg.org/badges/version/crc32c)](https://cran.r-project.org/package=crc32c)
[![Dependencies](https://tinyverse.netlify.app/badge/crc32c)](https://cran.r-project.org/package=crc32c)
[![Last Commit](https://img.shields.io/github/last-commit/eddelbuettel/crc32c)](https://github.com/eddelbuettel/crc32c)

### Motivation

CRC32C is a [cyclic redundancy check](https://en.wikipedia.org/wiki/Cyclic_redundancy_check) (with
parity) implementation based on work by [Castagnoli, Brauer, and
Hermann](https://dx.doi.org/10.1109/26.231911) that is provided by Google in a
[repository](https://github.com/google/crc32c) with optional hardware-acceleration selected at
run-time. It is included (minus the parts for logging, testing and
benchmarking we would not use from R) 'as is' in the package at [src/crc32c/](src/crc32c/).

This project provides it for use by [R](https://www.r-project.org).  We also aim for this to be an
example of how a standalone `cmake` project providing a library can be offered via an R package for
use by R as well as by other R packages.

### Usage

The package provides a function direct callable from R.

The package also exports three C-level functions that can be called directly from other R packages
by means of a mechanism [described in _Writing R
Extensions_](https://rstudio.github.io/r-manuals/r-exts/System-and-foreign-language-interfaces.html#linking-to-native-routines-in-other-packages).

### Authors

For CRC32C itself see the [included AUTHORS file](src/crc32c/AUTHORS) file.

For the R package integration and maintenance, Dirk Eddelbuettel

### License

For CRCR32C itself see the [included LICENSE file](src/crc32c/LICENSE) file.

The R package integrations is licensed under GPL (>= 2) just like R itself.
