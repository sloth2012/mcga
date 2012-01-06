#include <R.h>
#include "multi_mcga.h"

double *coster(struct MultiChromosome *c){
	double *result = (double*) malloc(sizeof(double) * 2);
	result[0] = pow(c->genes[0] - 3.141592,2.0);
	result[1] = pow(c->genes[1] - 2.71828 ,2.0);
	return(result);
}

void test(){
	int iter;
	Rprintf("Creating a multimcga\n");
	struct MultiMcga *m = multi_mcga_create (200, 2, 1.0, 0.01, UNIFORM_CROSS_OVER, 1, 2, coster);
	struct MultiMcga *temp = multi_mcga_create (200, 2, 1.0, 0.01, UNIFORM_CROSS_OVER, 1, 2, coster);
	
	multi_mcga_randomize(m,0.0,10.0);
	
	for (iter=0;iter<1000;iter++){
		multi_mcga_calculate_fitness(m);
		multi_mcga_calculate_ranks(m);
		multi_mcga_tournament_selection(m, temp);
	}

	multi_mcga_calculate_fitness(m);
	multi_mcga_calculate_ranks(m);
	multi_mcga_sortpopulation(m);
	multi_mcga_dump(m);

}
