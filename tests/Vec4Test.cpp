/**
 * @file Vec4Test.cpp
 */

#include <gtest/gtest.h>
#include "math/Vec4.hpp"

TEST(Vec4Test, ConstructorSetsComponents)
{
    Vec4 v(3.0f, 4.0f, 5.0f, 6.0f);
    EXPECT_FLOAT_EQ(v.getX(), 3.0f);
    EXPECT_FLOAT_EQ(v.getY(), 4.0f);
    EXPECT_FLOAT_EQ(v.getZ(), 5.0f);
    EXPECT_FLOAT_EQ(v.getW(), 6.0f);
}

TEST(Vec4Test, DefaultConstructorConstructs)
{
    Vec4 v;
    (void)v;
}
