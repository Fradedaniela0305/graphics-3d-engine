/**
 * @file Vec3Test.cpp
 */

#include <gtest/gtest.h>
#include "math/Vec3.hpp"

TEST(Vec3Test, ConstructorSetsComponents)
{
    Vec3 v(3.0f, 4.0f, 5.0f);
    EXPECT_FLOAT_EQ(v.getX(), 3.0f);
    EXPECT_FLOAT_EQ(v.getY(), 4.0f);
    EXPECT_FLOAT_EQ(v.getZ(), 5.0f);
}

TEST(Vec3Test, DefaultConstructorConstructs)
{
    Vec3 v;
    (void)v;
}
