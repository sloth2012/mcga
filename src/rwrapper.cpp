#include "ga.h"
#include <R.h>
#include <Rdefines.h>
#include <stdio.h>

extern "C" {
	
SEXP mcga (SEXP popsize, SEXP chsize, SEXP elitism, SEXP min, SEXP max, SEXP maxiter, SEXP par, SEXP best, SEXP evalFunc, SEXP population, SEXP env){
	int popsize1=NUMERIC_POINTER(popsize)[0];
	int chsize1=NUMERIC_POINTER(chsize)[0];
	int elitism1=NUMERIC_POINTER(elitism)[0];
	double min1=NUMERIC_POINTER(min)[0];
	double max1=NUMERIC_POINTER(max)[0];
	int maxiter1=NUMERIC_POINTER(maxiter)[0];
	double bestfitnessval=99999999999999.9;
	double currentfitness;

	SEXP fn, sexp_fvec;
	
	GA ga=GA(popsize1, chsize1, elitism1, 1,1);

	ga.randomize(min1, max1);

	for (int i=0;i<maxiter1;i++){
		ga.Selection();
		for (int j=0;j<popsize1;j++){
			for (int h = 0; h < chsize1; h++) {
				NUMERIC_POINTER(par)[h] = ga.getChromosome(j)->values[h];
			}
			fn=lang2(evalFunc, par);
			sexp_fvec=eval(fn,env);
			currentfitness=NUMERIC_POINTER(sexp_fvec)[0];
			ga.setFitness(j,currentfitness);
			if(currentfitness<bestfitnessval){
				bestfitnessval=currentfitness;
				for (int k=0;k<chsize1;k++) NUMERIC_POINTER(best)[k]=NUMERIC_POINTER(par)[k];
				//printf("Best fitness changed to %f\n",bestfitnessval);
			}
		}
	}
	ga.sortPopulation();
	for (int i=0;i<popsize1;i++){
		for (int j=0;j<chsize1;j++){
			NUMERIC_POINTER(population)[i*chsize1+j]=ga.getChromosome(i)->values[j];
		}
	}

	
	return(population);
}

}//END of Extern "C"
