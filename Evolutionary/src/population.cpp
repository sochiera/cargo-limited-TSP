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