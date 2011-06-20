#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/timeb.h>
#include "mcga.h"
#include "dejong.h"
#include "dejongcosts.h"
#include "normals.h"

void simulations()
{

    char filename[255];
    int *pops = malloc(sizeof(int) * 6);
    int *iters = malloc(sizeof(int) * 6);
    pops[0]=30;
    pops[1]=50;
    pops[2]=100;
    pops[3]=200;
    pops[4]=500;
    pops[5]=1000;
    iters[0]=100;
    iters[1]=500;
    iters[2]=1000;
    iters[3]=2500;
    int i,j, simu;
    double min = -20.0;
    double max = 20.0;
    int max_simu=50;

    //srand(time(NULL));
    srand(12345);

    for (i=0; i<6; i++)
    {
        for (j=0; j<4; j++)
        {
            printf("/media/LinuxDrive/mcga-article/simulations/F4-N%d-I%d.txt",pops[i],iters[j]);
            sprintf(filename, "/media/LinuxDrive/mcga-article/simulations/F4-N%d-I%d.txt",pops[i],iters[j]);
            //FILE *file = fopen(filename, "w");
            for (simu=1; simu<max_simu; simu++)
            {
                struct Mcga *mcga = mcga_create(pops[i], 3, 1.0, 0.01, UNIFORM_CROSS_OVER, 1, &dejongcost1);
                struct Mcga *mcga2 = mcga_create(pops[i], 30, 1.0, 0.01, UNIFORM_CROSS_OVER, 1, &dejongcost1);
                dejong_anormal = normals_get_next();

                mcga_start(mcga, mcga2, iters[i], min, max);


                mcga_sortpopulation(mcga);
                mcga_dump_chromosome(&mcga->chromosomes[0], 0);

                //fprintf(file, "%f\n", mcga->chromosomes[0].cost);
                //fflush(file);
                mcga_free(mcga);
                mcga_free(mcga2);
            }
            //fclose(file);
        }
    }
}

