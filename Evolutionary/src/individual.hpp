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

	int evaluate(vector< vector<int> > dist);

private:
	vector<Course> courses_;

	int computeOneCourse(vector< vector<int> > dist, Course c);
};

#endif