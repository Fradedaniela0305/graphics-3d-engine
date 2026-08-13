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

TEST(Vec2Test, SetXChangesXComponentOnly)
{
    Vec2 v(3.0f, 4.0f);
    v.setX(10.0f);
    EXPECT_FLOAT_EQ(v.getX(), 10.0f);
    EXPECT_FLOAT_EQ(v.getY(), 4.0f);
}

TEST(Vec2Test, SetYChangesYComponentOnly)
{
    Vec2 v(3.0f, 4.0f);
    v.setY(10.0f);
    EXPECT_FLOAT_EQ(v.getX(), 3.0f);
    EXPECT_FLOAT_EQ(v.getY(), 10.0f);
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

TEST(Vec2Test, SubtractSubtractsEachComponent)
{
    Vec2 v(3.0f, 4.0f);
    Vec2 other(1.0f, 5.0f);
    Vec2 result = v.subtract(other);
    EXPECT_FLOAT_EQ(result.getX(), 2.0f);
    EXPECT_FLOAT_EQ(result.getY(), -1.0f);
    EXPECT_FLOAT_EQ(v.getX(), 3.0f);
    EXPECT_FLOAT_EQ(v.getY(), 4.0f);
}

TEST(Vec2Test, CrossCalculatesThisCrossOther)
{
    Vec2 v(1.0f, 0.0f);
    Vec2 other(0.0f, 1.0f);
    float result = v.cross(other);
    EXPECT_FLOAT_EQ(result, 1.0f);
    EXPECT_FLOAT_EQ(v.getX(), 1.0f);
    EXPECT_FLOAT_EQ(v.getY(), 0.0f);
}

TEST(Vec2Test, CrossIsNotCommutative)
{
    Vec2 v(2.0f, 3.0f);
    Vec2 other(5.0f, 6.0f);
    float result = v.cross(other);
    float reversed = other.cross(v);
    EXPECT_FLOAT_EQ(result, -3.0f);
    EXPECT_FLOAT_EQ(reversed, 3.0f);
}

TEST(Vec2Test, DotCalculatesDotProductOfNormalizedVectors)
{
    Vec2 v(3.0f, 4.0f);
    Vec2 other(1.0f, 5.0f);
    float result = v.dot(other);
    EXPECT_NEAR(result, 0.9021342f, 1e-6f);
    EXPECT_FLOAT_EQ(v.getX(), 3.0f);
    EXPECT_FLOAT_EQ(v.getY(), 4.0f);
}

TEST(Vec2Test, DotIsCommutative)
{
    Vec2 v(2.0f, 3.0f);
    Vec2 other(5.0f, 6.0f);
    float result = v.dot(other);
    float reversed = other.dot(v);
    EXPECT_FLOAT_EQ(result, reversed);
}

TEST(Vec2Test, DotOfPerpendicularVectorsIsZero)
{
    Vec2 v(1.0f, 0.0f);
    Vec2 other(0.0f, 1.0f);
    float result = v.dot(other);
    EXPECT_FLOAT_EQ(result, 0.0f);
}

TEST(Vec2Test, DotOfParallelVectorsIsOne)
{
    Vec2 v(2.0f, 0.0f);
    Vec2 other(5.0f, 0.0f);
    float result = v.dot(other);
    EXPECT_FLOAT_EQ(result, 1.0f);
}

TEST(Vec2Test, DotOfOppositeVectorsIsNegativeOne)
{
    Vec2 v(2.0f, 0.0f);
    Vec2 other(-5.0f, 0.0f);
    float result = v.dot(other);
    EXPECT_FLOAT_EQ(result, -1.0f);
}

TEST(Vec2Test, DotWithZeroLengthVectorIsZero)
{
    Vec2 v(3.0f, 4.0f);
    Vec2 zero(0.0f, 0.0f);
    EXPECT_FLOAT_EQ(v.dot(zero), 0.0f);
    EXPECT_FLOAT_EQ(zero.dot(v), 0.0f);
}

TEST(Vec2Test, PrintOutputsComponents)
{
    Vec2 v(3.0f, 4.0f);
    testing::internal::CaptureStdout();
    v.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Vec2(3, 4)\n");
}
