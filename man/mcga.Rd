\name{mcga}
\alias{mcga}
\title{
mcga
}
\description{
mcga package uses machine coded chromosomes for the real value optimization problems. Chromosomes are not encoded/decoded, the byte representation of the double values are used for crossing-over and mutation operations. This makes mcga extremely fast even the number of parameters is high. Values of the parameters are bounded with the machine double type.

mcga function is a wrapper for the C++ library. 
}
\usage{
mcga(popsize, chsize, elitism = 1, minval, maxval, maxiter = 10, evalFunc)
}
\arguments{
  \item{popsize}{
Length of the population (The number of chromosomes in the population).
}
  \item{chsize}{
Length of the chromosomes (How many variables does a chromosome holds).
}
  \item{elitism}{
Best 'elitism' chromosomes will be copeid into next population.
}
  \item{minval}{
Lower bound for the variables. This bound is only used when the chromosomes are randomized at the beginning of the algorithm.
}
  \item{maxval}{
Lower bound for the variables. This bound is only used when the chromosomes are randomized at the beginning of the algorithm.
}
  \item{maxiter}{
Number of generations.
}
  \item{evalFunc}{
User defined R function subject to minimize. In the case of maximization type optimizations, this function may return -1 * cost.
}
}

\value{
Returnes the sorted population of the last iteration and the best solution vector.

\item{population}{
Resulted population matrix
}

\item{best}{
Best vector of solutions.
}

}
\author{
Mehmet Hakan Satman <mhsatman@istanbul.edu.tr>
}



\examples{
#Examples

#Evolution of PI
f<-function(x){
        return(abs(x-pi));
}

m<-mcga(500,1,1,-1000000,1000000,100,evalFunc=f);

print(m$best);



#Calculation LMS (Least median of squares) estimates
f<-function(candidates){
        res<-y-candidates[1]-candidates[2]*x
        return(median(res^2));
}

n<-100;
x<-rnorm(n);
e<-rnorm(n);
y<-5+5*x+e;

m<-mcga(popsize=500, chsize=2, minval=-9999999, maxval=9999999, evalFunc=f, maxiter=50)

print("Best solution for LMS:")
print(m$best)
print("Cost is:")
print(f(m$best))




}
