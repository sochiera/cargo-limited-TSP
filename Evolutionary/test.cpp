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
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}