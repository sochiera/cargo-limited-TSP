#ifndef DEFINES_H_
#define DEFINES_H_

#define POPULATION_SIZE 100 
#define CITIES_PER_COURSE 3
#define SIGMA1 0.3
#define SIGMA2 0.1

#include <cstdlib>
#include <ctime>

bool doubleRandom(double d){
	return (double(rand() % 10000)/10000.0 < d);
}

#endif

