#ifndef POPULATION_H_
#define POPULATION_H_

using namespace std;

#include <vector>
#include "individual.hpp"

class Population {
public:
	Population(int size);

	unsigned int size();

private:
	std::vector <Individual> individuals_;
};

#endif