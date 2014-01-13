#ifndef POPULATION_H_
#define POPULATION_H_

using namespace std;

#include <vector>
#include "individual.hpp"

class Population {
public:
	Population();

	void iteration();
	unsigned int size();

private:
	void reproduction();
	void mutation();
	void replacement();

	std::vector <Individual> individuals_;
};

#endif