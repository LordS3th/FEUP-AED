#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funSearchProblem.h"

using testing::Eq;

TEST(test, facingsun){
    vector<int> test1;
    ASSERT_EQ(0,FunSearchProblem::facingSun(test1));
    test1.push_back(1);
    test1.push_back(2);
    test1.push_back(3);
    test1.push_back(4);
    ASSERT_EQ(4, FunSearchProblem::facingSun(test1));
    test1.push_back(6);
    test1.push_back(5);
    ASSERT_EQ(5,FunSearchProblem::facingSun(test1));

}

TEST(test, squareR){
    ASSERT_EQ(3,FunSearchProblem::squareR(9));
    ASSERT_EQ(3,FunSearchProblem::squareR(10));
    ASSERT_EQ(2,FunSearchProblem::squareR(5));
    ASSERT_EQ(5, FunSearchProblem::squareR(26));
    ASSERT_EQ(5, FunSearchProblem::squareR(27));
}

TEST(test, missingvalue){
vector<int> test2;
vector<int> test3;
vector<int> empty;
test2={0,-10,1,4,-20,3};
test3={0,1,2,3,4,5};
    ASSERT_EQ(2,FunSearchProblem::smallestMissingValue(test2));
    ASSERT_EQ(6,FunSearchProblem::smallestMissingValue(test3));
    ASSERT_EQ(0, FunSearchProblem::smallestMissingValue(empty));
}
/*
TEST(test, minPages){

}

*/