% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{UniformCrossOver}
\alias{UniformCrossOver}
\title{Uniform Crossover operation on the two vectors of bytes}
\usage{
UniformCrossOver(bytes1, bytes2)
}
\arguments{
\item{bytes1}{A vector of bytes of the first parent}

\item{bytes2}{A vector of bytes of the second parent}
}
\value{
List of two byte vectors of offspring
}
\description{
This function is a C++ wrapper for crossing-over of two byte vectors of candidate solutions
}
\examples{
b1 <- DoubleVectorToBytes(c(56.54, 89.7666, 98.565))
b2 <- DoubleVectorToBytes(c(79.76, 56.4443, 34.22121))
result <- UniformCrossOver(b1,b2)
print(ByteVectorToDoubles(result[[1]]))
print(ByteVectorToDoubles(result[[2]]))
}
\author{
Mehmet Hakan Satman - mhsatman@istanbul.edu.tr
}
\seealso{
OnePointCrossOver

UniformCrossOverOnDoublesUsingBytes
}

