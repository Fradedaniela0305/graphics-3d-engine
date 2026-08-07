/**
 * @file Vec3Test.cpp
 */

#include <gtest/gtest.h>
#include "math/Vec3.hpp"

TEST(Vec3Test, ConstructorSetsComponents)
{
    Vec3 v(3, 4, 5);
    EXPECT_EQ(v.getX(), 3);
    EXPECT_EQ(v.getY(), 4);
    EXPECT_EQ(v.getZ(), 5);
}

TEST(Vec3Test, DefaultConstructorConstructs)
{
    Vec3 v;
    (void)v;
}
