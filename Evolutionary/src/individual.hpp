#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

using namespace std;

#include <vector>
#include "defines.hpp"

class Individual {
public:
	typedef vector<int> Course;

	Individual(vector<Course> courses);
	Individual();


	vector<Course> getCourses();

private:
	vector<Course> courses_;
};

#endif