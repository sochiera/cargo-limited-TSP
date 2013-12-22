#include "population.hpp"

using namespace std;

unsigned int Population::size() {
	return individuals_.size();
}

Population::Population(int size) {
	while(size--)
		individuals_.push_back(1);
};