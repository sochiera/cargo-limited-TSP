#include "population.hpp"
#include <algorithm>

using namespace std;

unsigned int Population::size() {
	return individuals_.size();
}

Population::Population(int cities, vector<vector<int> > dist) :
	best_(100000000), dist_(dist)	
{
	int size = POPULATION_SIZE;
	while(size--)
		individuals_.push_back(Individual(cities));
};

void Population::reproduction(){
	for(int i = 0; i < POPULATION_SIZE; i += 2) {
		individuals_.push_back(individuals_[i].crossover(individuals_[i+1]));
		individuals_.push_back(individuals_[i+1].crossover(individuals_[i]));
	}
}

void Population::mutation(){
	for(int i = 0; i < this->size(); i++) {
		if(doubleRandom(SIGMA1)) individuals_[i].mutate();
	}
}

void Population::localSearch(){
	for(int i = 0; i < this->size(); i++) {
		individuals_[i].localSearch(dist_);
	}
}

void Population::evaluation() {
	for(int i = 0; i < individuals_.size(); i++) {
		individuals_[i].evaluate(dist_);
		if(individuals_[i].getValue() < best_)
			best_ = individuals_[i].getValue();
	}
}


void Population::replacement() {
	sort(individuals_.begin(), individuals_.end());
	while(individuals_.size() > POPULATION_SIZE) individuals_.pop_back();	
}

void Population::iteration() {
	reproduction();
	mutation();
	localSearch();
	evaluation();
	replacement();
}

int Population::getBest() {
	return best_;
}