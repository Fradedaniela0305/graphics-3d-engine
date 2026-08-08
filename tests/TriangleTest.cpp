/**
 * @file TriangleTest.cpp
 */

#include <gtest/gtest.h>
#include "Triangle.hpp"
#include "math/Vec2.hpp"

TEST(TriangleTest, ConstructorSetsPoints)
{
    Vec2 p1(1.0f, 2.0f);
    Vec2 p2(3.0f, 4.0f);
    Vec2 p3(5.0f, 6.0f);
    Triangle t(p1, p2, p3);

    EXPECT_FLOAT_EQ(t.getP1().getX(), 1.0f);
    EXPECT_FLOAT_EQ(t.getP1().getY(), 2.0f);

    EXPECT_FLOAT_EQ(t.getP2().getX(), 3.0f);
    EXPECT_FLOAT_EQ(t.getP2().getY(), 4.0f);

    EXPECT_FLOAT_EQ(t.getP3().getX(), 5.0f);
    EXPECT_FLOAT_EQ(t.getP3().getY(), 6.0f);
}

TEST(TriangleTest, DefaultConstructorConstructs)
{
    Triangle t;
    (void)t;
}
