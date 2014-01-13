#include "individual.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

Individual::Individual(vector<Individual::Course> courses){
	courses_ = courses;
}

vector<Individual::Course> Individual::getCourses(){
	return courses_;
}

Individual::Individual(){
	vector<int> cities;
	for(int i = 0; i < CITIES; i++){
		cities.push_back(i);
		random_shuffle(cities.begin(), cities.end());
		while(cities.size()){
			Course course;
			for(int j = 0; j < CITIES_PER_COURSE; j++){
				course.push_back(*cities.rbegin());
				cities.pop_back();
				if(!cities.size())
					break;
			}
			courses_.push_back(course);
		}
	}
}