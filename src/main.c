#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/timeb.h>
#include "mcga.h"

/*
This sample function has 5 parameters and has a global minimum of 0.0
at
x1=1
x2=7
x3=77
x4=777
x5=7777
where -10000<xi<10000
*/

double sample_function (struct Chromosome *params)
{
    double cost = 0.0;
    cost += pow(params->genes[0] - 1.0 ,2.0);
    cost += pow(params->genes[1] - 7.0 ,2.0);
    cost += pow(params->genes[2] - 77.0 ,2.0);
    cost += pow(params->genes[3] - 777.0 ,2.0);
    cost += pow(params->genes[4] - 7777.0 ,2.0);
    return(cost);
}



/*
main function for test
*/
int main()
{
    /*
    Configuration for initial random population
    */
    double min = -10000.0;
    double max = 10000.0;

    /*
    Creating mcga with population size 200, number of parameters 5, crossover probability 1.0,
    mutation probability 0.01, cross over type uniform, number of elitism 1.
    Address of sample_function is given to mcga_create as parameter.
    */
    struct Mcga *mcga = mcga_create(200, 5, 1.0, 0.01, UNIFORM_CROSS_OVER, 1, &sample_function);

    /*
    This implementation of mcga is not a steady state genetic algorithm, we need a temporary
    population. This temporary population is not used by the user manually.
    */
    struct Mcga *mcga2 = mcga_create(200, 5, 1.0, 0.01, UNIFORM_CROSS_OVER, 1, &sample_function);

    /*
    All of the optimization procedure is done here. mcga_start() is called with the population mcga,
    the temporary population mcga2, number of generations 3000 and probability distribution of Uniform(min,max)
    for initial population.
    */
    mcga_start(mcga, mcga2, 3000, min, max);

    /*
    Population mcga is sorted by ascending order of cost values. The first chromosome, mcga->chromosomes[0], is
    the best over all generations, if elitisim is greater than zero.
    */
    mcga_sortpopulation(mcga);

    /*
    Dumps the best chromosome with its cost value.
    */
    mcga_dump_chromosome(&mcga->chromosomes[0], 0);

    /*
    Free the memory
    */
    mcga_free(mcga2);
    mcga_free(mcga);
    /*
    End of test.
    */
    return 0;
}
