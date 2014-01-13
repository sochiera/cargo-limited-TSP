#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

using namespace std;

#include <vector>


class Individual {
public:
	struct Course {
		vector<int> Cities;
	};

	Individual(vector<Course> courses);

private:
	vector <Course> courses_;
};

#endif