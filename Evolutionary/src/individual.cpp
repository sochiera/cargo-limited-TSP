#include "individual.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

Individual::Individual(vector<Individual::Course> courses, int cities) : 
	fitnessValue(-1), 
	courses_(courses), 
	cities_(cities) {
}


Individual::Individual(int numberOfCities) : fitnessValue(-1), cities_(numberOfCities) {
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

// Ugly function, needs refactoring
Individual Individual::crossover(const Individual & dad) const {
    const vector<Individual::Course> &dadCourses = dad.getCourses();
    
    vector<Individual::Course> childCourses;

    bool was[cities_];
    fill(was, was + cities_, false);

    for(int i = 0; i < courses_.size(); i++) {
    	if(doubleRandom(0.5)) childCourses.push_back(courses_[i]);
    }

    for(int i = 0; i < childCourses.size(); i++) {
    	for(int j = 0; j < childCourses[i].size(); j++) {
    		was[childCourses[i][j]] = true;
    	}
    }

    vector<int> rest;
	for(int i = 0; i < dadCourses.size(); i++) {
    	for(int j = 0; j < dadCourses[i].size(); j++) {
    		if(!was[dadCourses[i][j]]) {
    			rest.push_back(dadCourses[i][j]);
    		}
    	}
    }

    for(int i = 0; i < rest.size(); ) {
		Course c;
    	for(int j = 0; j < CITIES_PER_COURSE; j++) {
    		if(i >= rest.size()) break; 
    		c.push_back(rest[i]);
    		i++;
    	}
    	childCourses.push_back(c);
    }
    return Individual(childCourses, cities_);
}


void Individual::mutate() {

	int s = courses_.size();
	Course &first = courses_[rand() % s];
	Course &second = courses_[rand() % s];
	swap(first[rand()%first.size()], second[rand()%second.size()]);
	fitnessValue = -1;
}

void Individual::localSearch(vector< vector<int> > dist) {
	for(int i = 0; i < courses_.size(); i++){\
		courses_[i] = optimizeCourse(dist, courses_[i]);
		fitnessValue = -1;
	}
}

// Ugly function, needs refactoring
Individual::Course Individual::optimizeCourse(vector< vector<int> > dist, Course c) {
	int courseDistance = computeOneCourse(dist, c);
	if(c.size() == 1) return c;
	else if (c.size() == 2) {
		int shuffledCities1[] = {c[1], c[0]};
		Course shuffledCourse(shuffledCities1, shuffledCities1+2);
		if(computeOneCourse(dist, shuffledCourse) < courseDistance){
			courseDistance = computeOneCourse(dist, shuffledCourse);
			c = shuffledCourse;
		}
	}
	else if(CITIES_PER_COURSE == 3) {	

		int shuffledCities1[] = {c[0], c[2], c[1]};
		int shuffledCities2[] = {c[1], c[0], c[2]};
		Course shuffledCourse(shuffledCities1, shuffledCities1+3);
		if(computeOneCourse(dist, shuffledCourse) < courseDistance){
			courseDistance = computeOneCourse(dist, shuffledCourse);
			c = shuffledCourse;
		}
		shuffledCourse.assign(shuffledCities2, shuffledCities2+3);
		if(computeOneCourse(dist, shuffledCourse) < courseDistance){
			courseDistance = computeOneCourse(dist, shuffledCourse);
			c = shuffledCourse;
		}
	}
	else {
		int times = 4;
		while(times--){
			Course shuffledCourse(c);
			random_shuffle(shuffledCourse.begin(), shuffledCourse.end());
			if(computeOneCourse(dist, shuffledCourse) < courseDistance){
				courseDistance = computeOneCourse(dist, shuffledCourse);
				c = shuffledCourse;
			}
		}
	}
	return c;
}
