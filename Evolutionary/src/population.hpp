#ifndef POPULATION_H_
#define POPULATION_H_

#include <vector>

class Population {
public:
	Population(int size);

	unsigned int size();

private:
	std::vector <int> individuals_;
};

#endif