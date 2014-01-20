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

	bool doubleRandom(double d){
		return (double(rand() % 10000)/10000.0 < d);
	}

private:
	void reproduction();
	void mutation();
	void localSearch();
	void evaluation();
	void replacement();

	std::vector <Individual> individuals_;
	int best_;
	vector<vector<int> > dist_;
	int cities_;
};

#endif