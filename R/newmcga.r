# R File
# This is a wrapper file for the C library
mcga <-function (popsize, chsize, crossprob = 1.0, mutateprob =
		  0.01, elitism = 1, minval, maxval, maxiter = 10, evalFunc)
{

  par <-rep (0, chsize);
  best <-rep (0, chsize);
  population <-rep (0, chsize * popsize);
  costs <-rep (0, popsize);
  envv <-.GlobalEnv;
  result <-.Call ("mcga", popsize, chsize, crossprob, mutateprob, elitism,
		   minval, maxval, maxiter, par, best, evalFunc, population,
		   costs, envv, PACKAGE = "mcga");
  resmat <-matrix (population, ncol = chsize, nrow = popsize);
  return (list
	  (population =
	   matrix (population, popsize, chsize, byrow = TRUE), costs =
	   costs, popsize = popsize, chsize = chsize, crossprob =
	   crossprob, mutateprob = mutateprob, elitism = elitism, minval =
	   minval, maxval = maxval, maxiter = maxiter));
}



