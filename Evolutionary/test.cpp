#include "src/population.cpp"
#include "src/individual.cpp"
#include <gtest/gtest.h>


TEST(PopulationTest, HasGivenInConstructorSize) {
    Population p(30);
    ASSERT_EQ(p.size(), 30);
}

TEST(PopulationTest, HasGivenInConstructorSize2) {
    Population p(30);
    ASSERT_EQ(p.size(), 30);
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}