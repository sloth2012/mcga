
class Chromosome {
    private:
        int chsize;
        double fitness;

    public:
        double *values;
        ~Chromosome();
        Chromosome();
        Chromosome(int chsize);
        void setFitness(double value);
        double getFitness();
        void dump();
        void randomize(double min, double max);
        void setChromosomeSize(int size);
        int getChromosomeSize();
};

class GA {
    private:
        int popsize;
        int chsize;
        int elitism;
        double crossprob;
        double mutateprob;
        short int verbose;

    public:
        Chromosome *chromosomes;
        Chromosome *tempchromosomes;
        ~GA();
        GA();
        GA(int popsize, int chsize, int elitism, double crossprob, double mutateprob);
        void dump();
        void setVerbose(short int verbose);
        int getChromosomeSize();
        int getPopulationSize();
        Chromosome *getChromosome(int index);
        void randomize(double min, double max);
        void setFitness(int index, double value);
        friend int sorter(const void *c1, const void *c2);
        void sortPopulation();
        int Tournament();
        void Mutate(Chromosome *c1);
        void UniformCrossOver(Chromosome *source1, Chromosome *source2, Chromosome *offspring1, Chromosome *offspring2);
        void Selection();
};

