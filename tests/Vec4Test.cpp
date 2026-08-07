/**
 * @file Vec4Test.cpp
 */

#include <gtest/gtest.h>
#include "math/Vec4.hpp"

TEST(Vec4Test, ConstructorSetsComponents)
{
    Vec4 v(3, 4, 5, 6);
    EXPECT_EQ(v.getX(), 3);
    EXPECT_EQ(v.getY(), 4);
    EXPECT_EQ(v.getZ(), 5);
    EXPECT_EQ(v.getW(), 6);
}

TEST(Vec4Test, DefaultConstructorConstructs)
{
    Vec4 v;
    (void)v;
}
