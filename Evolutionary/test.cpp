#include "src/population.cpp"
#include "src/individual.cpp"
#include <gtest/gtest.h>
#include "src/defines.hpp"

TEST(PopulationTest, HasDefinedSize) {
    Population p;
    ASSERT_EQ(p.size(), POPULATION_SIZE);
}

TEST(IndividualTest, RandomIndividualHasVisitedDefinedNumberOfCities) {
    Individual ind;
    vector<Individual::Course> courses = ind.getCourses();
    int sum = 0;
    for(int i = 0; i < courses.size(); i++){
        sum += courses[i].size();
    }
    ASSERT_EQ(sum, CITIES);
}

TEST(IndividualTest, RandomIndividualHasVisitedAllCities) {
    Individual ind;
    vector<int> cities;
    vector<Individual::Course> courses = ind.getCourses();
    for(vector<Individual::Course>::iterator it = courses.begin(); it != courses.end(); it++){
        for(vector<int>::iterator cit = it->begin(); cit != it->end(); cit++){
            cities.push_back(*cit);
        }
    }
    sort(cities.begin(), cities.end());
    
    ASSERT_EQ(cities.size(), CITIES);
    for(int i = 0; i < CITIES; i++){
        ASSERT_EQ(cities[i], i);
    }
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}