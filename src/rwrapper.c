#include "mcga.h"
#include <R.h>
#include <Rdefines.h>
#include <stdio.h>


SEXP
mcga (SEXP popsize, SEXP chsize, SEXP crossp, SEXP mutatep, SEXP elitism,
      SEXP min, SEXP max, SEXP maxiter, SEXP par, SEXP best, SEXP evalFunc,
      SEXP population, SEXP costs, SEXP env)
{
  int popsize1 = NUMERIC_POINTER (popsize)[0];
  int chsize1 = NUMERIC_POINTER (chsize)[0];
  int elitism1 = NUMERIC_POINTER (elitism)[0];
  double crossp1 = NUMERIC_POINTER (crossp)[0];
  double mutatep1 = NUMERIC_POINTER (mutatep)[0];
  double min1 = NUMERIC_POINTER (min)[0];
  double max1 = NUMERIC_POINTER (max)[0];
  int maxiter1 = NUMERIC_POINTER (maxiter)[0];
  double currentfitness;

  SEXP fn, sexp_fvec;
  struct Mcga *mcga =
    mcga_create (popsize1, chsize1, crossp1, mutatep1, UNIFORM_CROSS_OVER,
		 elitism1, NULL);
  struct Mcga *mcga2 =
    mcga_create (popsize1, chsize1, crossp1, mutatep1, UNIFORM_CROSS_OVER,
		 elitism1, NULL);
  mcga_randomize (mcga, min1, max1);

  for (int i = 0; i < maxiter1; i++)
    {
      mcga_tournament_selection (mcga, mcga2);
      for (int j = 0; j < popsize1; j++)
	{
	  for (int h = 0; h < chsize1; h++)
	    {
	      NUMERIC_POINTER (par)[h] = mcga->chromosomes[j].genes[h];
	    }
	  fn = lang2 (evalFunc, par);
	  sexp_fvec = eval (fn, env);
	  currentfitness = NUMERIC_POINTER (sexp_fvec)[0];
	  mcga->chromosomes[j].cost = currentfitness;
	}
    }

  mcga_sortpopulation (mcga);

  for (int i = 0; i < popsize1; i++)
    {
      for (int j = 0; j < chsize1; j++)
	{
	  NUMERIC_POINTER (population)[i * chsize1 + j] =
	    mcga->chromosomes[i].genes[j];
	}
      NUMERIC_POINTER (costs)[i] = mcga->chromosomes[i].cost;
    }

	mcga_free(mcga);
	mcga_free(mcga2);

  return (popsize);
}

