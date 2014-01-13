#include "population.hpp"

using namespace std;

unsigned int Population::size() {
	return individuals_.size();
}

Population::Population() {
	int size = POPULATION_SIZE;
	while(size--)
		individuals_.push_back(Individual(vector<Individual::Course>()));
};

void Population::reproduction(){
	for(int i = 0; i < POPULATION_SIZE; i += 2) {
		pair<Individual, Individual> children = 
			individuals_[i].crossover(individuals_[i+1]);
		individuals_.push_back(children.first);
		individuals_.push_back(children.second);
	}
}

void Population::mutation(){
	for(int i = 0; i < this->size(); i++) {
		if(double(rand() % 10000)/10000.0 < SIGMA) individuals_[i].mutate();
	}
}