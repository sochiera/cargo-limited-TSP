#include "individual.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

Individual::Individual(vector<Individual::Course> courses) : fitnessValue(-1) {
	courses_ = courses;
}


// #include<iostream>


Individual::Individual(int numberOfCities) : fitnessValue(-1) {
	vector<int> cities;
	for(int i = 1; i <= numberOfCities; i++){
		cities.push_back(i);
	}
	random_shuffle(cities.begin(), cities.end());
	while(cities.size()){
		Course course;
		for(int j = 0; j < CITIES_PER_COURSE; j++){
			course.push_back(cities.back());
			cities.pop_back();
			if(!cities.size())
				break;
		}
		courses_.push_back(course);
	}

 //    for(vector<Course>::iterator it = courses_.begin(); it != courses_.end(); it++){
 //        for(vector<int>::iterator cit = it->begin(); cit != it->end(); cit++){
 //            cout << *cit << "   ";
 //        }
 //        cout << "\n          ";
 //    }
	// cout << "\n\n";


}

vector<Individual::Course> Individual::getCourses() const {
	return courses_;
}

int Individual::getValue() const {
	assert(fitnessValue != -1);
	return fitnessValue;
}

void Individual::evaluate(vector< vector<int> > dist){
	if(fitnessValue != -1) return;
	int result = 0;
	for(int i = 0; i < courses_.size(); i++){
		// cout << result << "   ";
		result += computeOneCourse(dist, courses_[i]);
	}
	fitnessValue = result;
	// cout << "  final:  " << result << "\n";
}

int Individual::computeOneCourse(vector< vector<int> > dist, Course c){
	int result = 0;
	if(!c.size()) return result;
	result += dist[0][c[0]];
	for(int i = 1; i < c.size(); i++){
		result += dist[c[i-1]][c[i]];
	}
	result += dist[c.back()][0];
	return result;
}

bool Individual::operator<(const Individual & another) const {
	return getValue() < another.getValue();
}

pair<Individual, Individual> Individual::crossover(const Individual & dad) const {
	return pair<Individual, Individual>(*this, dad);
}

void Individual::mutate() {
	for(int i = 0; i < courses_.size(); i++){
		if(doubleRandom(SIGMA2)) {
			random_shuffle(courses_[i].begin(), courses_[i].end());
			fitnessValue = -1;
		}
	}
}