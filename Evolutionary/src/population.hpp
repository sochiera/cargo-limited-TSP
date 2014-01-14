#ifndef POPULATION_H_
#define POPULATION_H_

using namespace std;

#include <vector>
#include "individual.hpp"

class Population {
public:
	Population(int cities, vector<vector<int> > dist);

	void iteration();
	unsigned int size();
	int getBest();

private:
	void reproduction();
	void mutation();
	void evaluation();
	void replacement();

	std::vector <Individual> individuals_;
	int best_;
	vector<vector<int> > dist_;
};

#endif