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

TEST(Vec3Test, PrintOutputsComponents)
{
    Vec3 v(3.0f, 4.0f, 5.0f);
    testing::internal::CaptureStdout();
    v.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Vec3(3, 4, 5)\n");
}
