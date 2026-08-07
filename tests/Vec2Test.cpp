/**
 * @file Vec2Test.cpp
 */

#include <gtest/gtest.h>
#include "math/Vec2.hpp"

TEST(Vec2Test, ConstructorSetsComponents)
{
    Vec2 v(3, 4);
    EXPECT_EQ(v.getX(), 3);
    EXPECT_EQ(v.getY(), 4);
}

TEST(Vec2Test, DefaultConstructorConstructs)
{
    Vec2 v;
    (void)v;
}
