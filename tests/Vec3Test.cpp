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

TEST(Vec3Test, ShiftAddsAmountToEachComponent)
{
    Vec3 v(3.0f, 4.0f, 5.0f);
    Vec3 result = v.shift(2.0f, 5.0f, 1.0f);
    EXPECT_FLOAT_EQ(result.getX(), 5.0f);
    EXPECT_FLOAT_EQ(result.getY(), 9.0f);
    EXPECT_FLOAT_EQ(result.getZ(), 6.0f);
    EXPECT_FLOAT_EQ(v.getX(), 3.0f);
    EXPECT_FLOAT_EQ(v.getY(), 4.0f);
    EXPECT_FLOAT_EQ(v.getZ(), 5.0f);
}

TEST(Vec3Test, ScaleMultipliesEachComponent)
{
    Vec3 v(3.0f, 4.0f, 5.0f);
    Vec3 result = v.scale(2.0f);
    EXPECT_FLOAT_EQ(result.getX(), 6.0f);
    EXPECT_FLOAT_EQ(result.getY(), 8.0f);
    EXPECT_FLOAT_EQ(result.getZ(), 10.0f);
    EXPECT_FLOAT_EQ(v.getX(), 3.0f);
    EXPECT_FLOAT_EQ(v.getY(), 4.0f);
    EXPECT_FLOAT_EQ(v.getZ(), 5.0f);
}

TEST(Vec3Test, ScaleComponentsMultipliesEachComponentByOwnFactor)
{
    Vec3 v(3.0f, 4.0f, 5.0f);
    Vec3 result = v.scale(2.0f, 5.0f, 3.0f);
    EXPECT_FLOAT_EQ(result.getX(), 6.0f);
    EXPECT_FLOAT_EQ(result.getY(), 20.0f);
    EXPECT_FLOAT_EQ(result.getZ(), 15.0f);
    EXPECT_FLOAT_EQ(v.getX(), 3.0f);
    EXPECT_FLOAT_EQ(v.getY(), 4.0f);
    EXPECT_FLOAT_EQ(v.getZ(), 5.0f);
}

TEST(Vec3Test, SubtractSubtractsEachComponent)
{
    Vec3 v(3.0f, 4.0f, 5.0f);
    Vec3 other(1.0f, 5.0f, 2.0f);
    Vec3 result = v.subtract(other);
    EXPECT_FLOAT_EQ(result.getX(), 2.0f);
    EXPECT_FLOAT_EQ(result.getY(), -1.0f);
    EXPECT_FLOAT_EQ(result.getZ(), 3.0f);
    EXPECT_FLOAT_EQ(v.getX(), 3.0f);
    EXPECT_FLOAT_EQ(v.getY(), 4.0f);
    EXPECT_FLOAT_EQ(v.getZ(), 5.0f);
}

TEST(Vec3Test, CrossCalculatesThisCrossOther)
{
    Vec3 v(1.0f, 0.0f, 0.0f);
    Vec3 other(0.0f, 1.0f, 0.0f);
    Vec3 result = v.cross(other);
    EXPECT_FLOAT_EQ(result.getX(), 0.0f);
    EXPECT_FLOAT_EQ(result.getY(), 0.0f);
    EXPECT_FLOAT_EQ(result.getZ(), 1.0f);
    EXPECT_FLOAT_EQ(v.getX(), 1.0f);
    EXPECT_FLOAT_EQ(v.getY(), 0.0f);
    EXPECT_FLOAT_EQ(v.getZ(), 0.0f);
}

TEST(Vec3Test, CrossIsNotCommutative)
{
    Vec3 v(2.0f, 3.0f, 4.0f);
    Vec3 other(5.0f, 6.0f, 7.0f);
    Vec3 result = v.cross(other);
    Vec3 reversed = other.cross(v);
    EXPECT_FLOAT_EQ(result.getX(), -3.0f);
    EXPECT_FLOAT_EQ(result.getY(), 6.0f);
    EXPECT_FLOAT_EQ(result.getZ(), -3.0f);
    EXPECT_FLOAT_EQ(reversed.getX(), 3.0f);
    EXPECT_FLOAT_EQ(reversed.getY(), -6.0f);
    EXPECT_FLOAT_EQ(reversed.getZ(), 3.0f);
}

TEST(Vec3Test, DotCalculatesDotProduct)
{
    Vec3 v(3.0f, 4.0f, 5.0f);
    Vec3 other(1.0f, 5.0f, 2.0f);
    float result = v.dot(other);
    EXPECT_FLOAT_EQ(result, 33.0f);
    EXPECT_FLOAT_EQ(v.getX(), 3.0f);
    EXPECT_FLOAT_EQ(v.getY(), 4.0f);
    EXPECT_FLOAT_EQ(v.getZ(), 5.0f);
}

TEST(Vec3Test, DotIsCommutative)
{
    Vec3 v(2.0f, 3.0f, 4.0f);
    Vec3 other(5.0f, 6.0f, 7.0f);
    float result = v.dot(other);
    float reversed = other.dot(v);
    EXPECT_FLOAT_EQ(result, reversed);
}

TEST(Vec3Test, DotOfPerpendicularVectorsIsZero)
{
    Vec3 v(1.0f, 0.0f, 0.0f);
    Vec3 other(0.0f, 1.0f, 0.0f);
    float result = v.dot(other);
    EXPECT_FLOAT_EQ(result, 0.0f);
}

TEST(Vec3Test, PrintOutputsComponents)
{
    Vec3 v(3.0f, 4.0f, 5.0f);
    testing::internal::CaptureStdout();
    v.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Vec3(3, 4, 5)\n");
}
