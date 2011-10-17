/*
#include <assert.h>
*/

#include "mcga.h"
#include "dejong.h"

double dejong_anormal =0.0;

double dejongcost1 (struct Chromosome *c)
{
    /* assert(c->ch_size == 3); */
    return(dejong1(c->genes));
}

double dejongcost2 (struct Chromosome *c)
{
    /* assert(c->ch_size == 2); */
    return(dejong2(c->genes));
}

double dejongcost3 (struct Chromosome *c)
{
    /* assert(c->ch_size == 5); */
    return(dejong3(c->genes));
}


