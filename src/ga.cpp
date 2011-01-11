#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "ga.h"

/*
Implementation of Chromosome Class
*/
Chromosome::~Chromosome(){
    //printf("Clean values...\n");

    if (this->values != NULL)    
        delete this->values;
}

Chromosome::Chromosome(){
    this->values=NULL;
}

Chromosome::Chromosome(int chsize){
    this->setChromosomeSize(chsize);
}

void Chromosome::setFitness(double value){
    this->fitness=value;
}

double Chromosome::getFitness(){
    return(this->fitness);
}

void Chromosome::dump(){
    double *ptr=this->values;
    printf("%0.5f] ",this->fitness);
    for (int i=0;i<this->chsize;i++){
        printf("%0.5f ",*ptr);
        ptr++;
    }
    printf("\n");
}

void Chromosome::randomize(double min, double max){
    for (int i=0;i<this->chsize;i++){
        this->values[i]=min + ((double) rand() / RAND_MAX) * (max - min);
    }
}

void Chromosome::setChromosomeSize(int size){
    this->chsize=size;
    this->values=new double[chsize];
}

int Chromosome::getChromosomeSize(){
    return(this->chsize);
}


/*
Implementation of GA Class
*/

GA::~GA(){
    //printf("Clean chromosomes...\n");
    delete[] this->chromosomes;
    delete[] this->tempchromosomes;
}

GA::GA(int popsize, int chsize, int elitism, double crossprob, double mutateprob){
    this->chsize=chsize;
    this->popsize=popsize;
    this->elitism=elitism;
    this->crossprob=crossprob;
    this->mutateprob=mutateprob;
    this->verbose=0;
    this->chromosomes=new Chromosome[popsize+1];
    this->tempchromosomes=new Chromosome[popsize+1];

    for (int i=0;i<popsize;i++){
            this->chromosomes[i].setChromosomeSize(chsize);
            this->tempchromosomes[i].setChromosomeSize(chsize);
    }

}

void GA::setVerbose(short int verbose){
    this->verbose=verbose;
}

void GA::dump(){
    for (int i=0;i<this->popsize;i++){
        (this->chromosomes[i]).dump();
    }
}


void GA::randomize(double min, double max){
    srand(time(NULL));
    for (int i=0;i<this->popsize;i++){
        this->chromosomes[i].randomize(min, max);
    }
}

void GA::setFitness(int index, double value){
    this->chromosomes[index].setFitness(value);
}

Chromosome* GA::getChromosome(int index){
    Chromosome *ptr=this->chromosomes;
    ptr+=index;
    return(ptr);
}

int GA::getChromosomeSize(){
    return(this->chsize);
}

int GA::getPopulationSize(){
    return(this->popsize);
}

int sorter(const void *c1, const void *c2){
    Chromosome *cc1=(Chromosome*)c1;
    Chromosome *cc2=(Chromosome*)c2;
    if(cc1->getFitness() <= cc2->getFitness()){
        return(-1);
    }else{
        return(1);
    }
}

void GA::sortPopulation(){
    qsort(this->chromosomes, this->popsize, sizeof(Chromosome), sorter);
}

void GA::Mutate(Chromosome *c1){
    char *cptr=(char *)c1->values;
    int mutatepoint=(rand() % (this->chsize * sizeof(double)));
    cptr+=mutatepoint;

        if(((float)rand()/RAND_MAX)<0.5){
            (*cptr)+=1;
        }else{
            (*cptr)-=1;
        }

}

int GA::Tournament(){
    int index1=(rand() % this->popsize);
    int index2=(rand() % this->popsize);
    if(this->chromosomes[index1].getFitness() < this->chromosomes[index2].getFitness()){
        return(index1);
    }else{
        return(index2);
    }
}

void GA::UniformCrossOver(Chromosome *source1, Chromosome *source2, Chromosome *offspring1, Chromosome *offspring2){
    char *cptr1=(char*) source1->values;
    char *cptr2=(char*) source2->values;
    char *cptr3=(char*) offspring1->values;
    char *cptr4=(char*) offspring2->values;
    int totalchars=this->getChromosomeSize() * sizeof(double);
    double arand;
    for (int i=0;i<totalchars;i++){
        arand=((float)rand() / RAND_MAX);
        if(arand<0.5){
            *cptr3=*cptr1;
            *cptr4=*cptr2;
        }else{
            *cptr3=*cptr2;
            *cptr4=*cptr1;
        }
        cptr1++; cptr2++; cptr3++; cptr4++;
    }
}


void GA::Selection(){
    int m=0;
    int index1=0,index2=0;
    Chromosome *tmpc=this->tempchromosomes, *c1, *c2;
    this->sortPopulation();
    for (int i=0;i<this->elitism;i++){
        *tmpc=this->tempchromosomes[i];
        m++;
        tmpc++;
    }
    while(m<this->popsize){
        index1=Tournament();
        index2=Tournament();
        c1=tmpc;
        m++;
        tmpc++;
        if(m==this->popsize) break;
        c2=tmpc;
        m++;
        tmpc++;
        UniformCrossOver(this->getChromosome(index1), this->getChromosome(index2), c1,c2);
        Mutate(c1);
        Mutate(c2);
    }

    for (int i=0;i<this->popsize;i++){
        memcpy(this->chromosomes[i].values, this->tempchromosomes[i].values, sizeof(double) * this->chsize);
    }
}


