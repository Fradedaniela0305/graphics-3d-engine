/**
 * @file Vec2Test.cpp
 */

#include <gtest/gtest.h>
#include "math/Vec2.hpp"

TEST(Vec2Test, ConstructorSetsComponents)
{
    Vec2 v(3.0f, 4.0f);
    EXPECT_FLOAT_EQ(v.getX(), 3.0f);
    EXPECT_FLOAT_EQ(v.getY(), 4.0f);
}

TEST(Vec2Test, DefaultConstructorConstructs)
{
    Vec2 v;
    (void)v;
}
