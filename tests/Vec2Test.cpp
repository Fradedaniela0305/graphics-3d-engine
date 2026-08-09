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

TEST(Vec2Test, ShiftAddsAmountToEachComponent)
{
    Vec2 v(3.0f, 4.0f);
    Vec2 result = v.shift(2.0f, 5.0f);
    EXPECT_FLOAT_EQ(result.getX(), 5.0f);
    EXPECT_FLOAT_EQ(result.getY(), 9.0f);
    EXPECT_FLOAT_EQ(v.getX(), 3.0f);
    EXPECT_FLOAT_EQ(v.getY(), 4.0f);
}

TEST(Vec2Test, ScaleMultipliesEachComponent)
{
    Vec2 v(3.0f, 4.0f);
    Vec2 result = v.scale(2.0f);
    EXPECT_FLOAT_EQ(result.getX(), 6.0f);
    EXPECT_FLOAT_EQ(result.getY(), 8.0f);
    EXPECT_FLOAT_EQ(v.getX(), 3.0f);
    EXPECT_FLOAT_EQ(v.getY(), 4.0f);
}

TEST(Vec2Test, ScaleComponentsMultipliesEachComponentByOwnFactor)
{
    Vec2 v(3.0f, 4.0f);
    Vec2 result = v.scale(2.0f, 5.0f);
    EXPECT_FLOAT_EQ(result.getX(), 6.0f);
    EXPECT_FLOAT_EQ(result.getY(), 20.0f);
    EXPECT_FLOAT_EQ(v.getX(), 3.0f);
    EXPECT_FLOAT_EQ(v.getY(), 4.0f);
}

TEST(Vec2Test, PrintOutputsComponents)
{
    Vec2 v(3.0f, 4.0f);
    testing::internal::CaptureStdout();
    v.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Vec2(3, 4)\n");
}
