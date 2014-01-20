#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

using namespace std;

#include <vector>
#include "defines.hpp"

class Individual {
public:
	typedef vector<int> Course;

	Individual(vector<Course> courses, int cities);
	Individual(int cities);

	vector<Course> getCourses() const;
	int getValue() const;

	void mutate();
	Individual crossover(const Individual & dad) const;
	void localSearch(vector< vector<int> > dist);
	void evaluate(vector< vector<int> > dist);

	bool operator<(const Individual & another) const;

	bool doubleRandom(double d) const {
		return (double(rand() % 10000)/10000.0 < d);
	}

private:
	int fitnessValue;
	int cities_;
	vector<Course> courses_;

	int computeOneCourse(vector< vector<int> > dist, Course c);
	Course optimizeCourse(vector< vector<int> > dist, Course c);

};

#endif