\name{NEWS}
\title{News for Package \pkg{crc32c}}
\newcommand{\ghpr}{\href{https://github.com/eddelbuettel/crc32c/pull/#1}{##1}}
\newcommand{\ghit}{\href{https://github.com/eddelbuettel/crc32c/issues/#1}{##1}}

\section{Changes in version 0.0.3 (unreleased)}{
  \itemize{
    \item Support cross-compilation by setting CC and CXX in Makevars.in
    (Jeroen Ooms in \ghpr{1})
  }
}

\section{Changes in version 0.0.2 (2023-05-11)}{
  \itemize{
    \item Explicitly set \pkg{cmake} property for position-independent code
    \item Help macOS find its \pkg{cmake} binary as detailed also in WRE
    \item Help Windows with a non-conditional Makevars.win pointing at cmake
    \item Add more badges to README.md 
  }
}

\section{Changes in version 0.0.1 (2023-05-07)}{
  \itemize{
    \item Initial release version and CRAN upload
  }
}


