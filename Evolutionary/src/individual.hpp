#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

using namespace std;

#include <vector>
#include "defines.hpp"

class Individual {
public:
	typedef vector<int> Course;

	Individual(vector<Course> courses);
	Individual(int cities);

	vector<Course> getCourses();

	void evaluate(vector< vector<int> > dist);
	int getValue() const;

	bool operator<(const Individual & another) const;

private:
	vector<Course> courses_;
	int fitnessValue;

	int computeOneCourse(vector< vector<int> > dist, Course c);
};

#endif