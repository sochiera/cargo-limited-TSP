#include "src/population.cpp"
#include "src/individual.cpp"
#include <gtest/gtest.h>
#include "src/defines.hpp"

TEST(PopulationTest, HasDefinedSize) {
    vector<vector<int> > dist;
    Population p(6, dist);
    ASSERT_EQ(p.size(), POPULATION_SIZE);
    ASSERT_EQ(0, POPULATION_SIZE%2);
}

TEST(IndividualTest, RandomIndividualHasVisitedDefinedNumberOfCities) {
    Individual ind(60);
    vector<Individual::Course> courses = ind.getCourses();
    int sum = 0;
    for(int i = 0; i < courses.size(); i++){
        sum += courses[i].size();
    }
    ASSERT_EQ(sum, 60);
}

TEST(IndividualTest, RandomIndividualHasVisitedAllCities) {
    Individual ind(40);
    vector<int> cities;
    vector<Individual::Course> courses = ind.getCourses();
    for(vector<Individual::Course>::iterator it = courses.begin(); it != courses.end(); it++){
        for(vector<int>::iterator cit = it->begin(); cit != it->end(); cit++){
            cities.push_back(*cit);
        }
    }
    sort(cities.begin(), cities.end());
    
    ASSERT_EQ(cities.size(), 40);
    for(int i = 0; i < 40; i++){
        ASSERT_EQ(cities[i], i+1);
    }
}

TEST(IndividualTest, FitnessComputesCorrectly) {
    int tab[] = {0, 1, 1, 1, 2, 2, 2,
               2, 0, 3, 1, 3, 1, 2,
               3, 1, 0, 2, 1, 3, 2,
               2, 3, 3, 0, 2, 1, 3,
               1, 1, 3, 1, 0, 3, 1,
               2, 4, 3, 1, 3, 0, 3,
               3, 1, 1, 1, 1, 2, 0};
    vector< vector<int> > dist;
    for(int i = 0; i < 7; i++){
        vector<int> distToOne;
        distToOne.assign(tab + 7*i, tab + 7*i+7);
        dist.push_back(distToOne);
    }
    
    vector<Individual::Course> courses;
    Individual::Course a;
    a.push_back(1); a.push_back(6); a.push_back(2); 
    courses.push_back(a);
    Individual::Course b;
    b.push_back(5); b.push_back(3); 
    courses.push_back(b);
    Individual::Course c;
    c.push_back(4);
    courses.push_back(c);
    Individual ind(courses);
    ind.evaluate(dist);
    ASSERT_EQ(ind.getValue(), 15);
}

TEST(IndividualTest, OneIndividualBetterThanAnother) {
    int tab[] = {0, 1, 1, 1, 2, 2, 2,
               2, 0, 3, 1, 3, 1, 2,
               3, 1, 0, 2, 1, 3, 2,
               2, 3, 3, 0, 2, 1, 3,
               1, 1, 3, 1, 0, 3, 1,
               2, 4, 3, 1, 3, 0, 3,
               3, 1, 1, 1, 1, 2, 0};
    vector< vector<int> > dist;
    for(int i = 0; i < 7; i++){
        vector<int> distToOne;
        distToOne.assign(tab + 7*i, tab + 7*i+7);
        dist.push_back(distToOne);
    }
    
    vector<Individual::Course> courses1;
    Individual::Course a;
    a.push_back(1); a.push_back(6); a.push_back(2); 
    courses1.push_back(a);
    Individual::Course b;
    b.push_back(5); b.push_back(3); 
    courses1.push_back(b);
    Individual::Course c;
    c.push_back(4);
    courses1.push_back(c);

    Individual ind(courses1);
    ind.evaluate(dist);

    vector<Individual::Course> courses2;
    courses2.push_back(a);
    b.push_back(4);
    courses2.push_back(b);

    Individual ind2(courses2);
    ind2.evaluate(dist);

    ASSERT_EQ(true, ind2 < ind);
}

TEST(IndividualTest, LocalSearchComputesCorrectly) {
    int tab[] = {0, 2, 3, 2,
                 2, 0, 1, 3,
                 3, 1, 0, 2,
                 2, 3, 2, 0};
    vector< vector<int> > dist;
    for(int i = 0; i < 4; i++){
        vector<int> distToOne;
        distToOne.assign(tab + 4*i, tab + 4*i+4);
        dist.push_back(distToOne);
    }
    
    vector<Individual::Course> courses1;
    Individual::Course a;
    a.push_back(1); a.push_back(3); a.push_back(2); 
    courses1.push_back(a);

    Individual ind(courses1);

    ind.evaluate(dist);
    ASSERT_EQ(ind.getValue(), 10);

    ind.localSearch(dist);

    ind.evaluate(dist);
    ASSERT_EQ(ind.getValue(), 7);
}

TEST(IndividualTest, MutationWorksCorrectly) {
    int tab[] = {0, 1, 1, 1, 2, 2, 2,
               2, 0, 3, 1, 3, 1, 2,
               3, 1, 0, 2, 1, 3, 2,
               2, 3, 3, 0, 2, 1, 3,
               1, 1, 3, 1, 0, 3, 1,
               2, 4, 3, 1, 3, 0, 3,
               3, 1, 1, 1, 1, 2, 0};
    vector< vector<int> > dist;
    for(int i = 0; i < 7; i++){
        vector<int> distToOne;
        distToOne.assign(tab + 7*i, tab + 7*i+7);
        dist.push_back(distToOne);
    }
    
    vector<Individual::Course> courses;
    Individual::Course a;
    a.push_back(1); a.push_back(6); a.push_back(2); 
    courses.push_back(a);
    Individual::Course b;
    b.push_back(5); b.push_back(3); b.push_back(4);
    courses.push_back(b);
    Individual ind(courses);


    srand(45);
    ASSERT_EQ(rand()%2, 0);
    ASSERT_EQ(rand()%2, 1);
    ASSERT_EQ(rand()%3, 2);
    ASSERT_EQ(rand()%3, 1);
    srand(45);
    ind.mutate();
    a = ind.getCourses()[0];
    b = ind.getCourses()[1];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ASSERT_EQ(a[0], 1);
    ASSERT_EQ(a[1], 2);
    ASSERT_EQ(a[2], 4);
    ASSERT_EQ(b[0], 3);
    ASSERT_EQ(b[1], 5);
    ASSERT_EQ(b[2], 6);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}