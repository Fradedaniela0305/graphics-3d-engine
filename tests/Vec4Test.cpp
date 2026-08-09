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

TEST(Vec4Test, ShiftAddsAmountToEachComponent)
{
    Vec4 v(3.0f, 4.0f, 5.0f, 6.0f);
    Vec4 result = v.shift(2.0f, 5.0f, 1.0f, 0.5f);
    EXPECT_FLOAT_EQ(result.getX(), 5.0f);
    EXPECT_FLOAT_EQ(result.getY(), 9.0f);
    EXPECT_FLOAT_EQ(result.getZ(), 6.0f);
    EXPECT_FLOAT_EQ(result.getW(), 6.5f);
    EXPECT_FLOAT_EQ(v.getX(), 3.0f);
    EXPECT_FLOAT_EQ(v.getY(), 4.0f);
    EXPECT_FLOAT_EQ(v.getZ(), 5.0f);
    EXPECT_FLOAT_EQ(v.getW(), 6.0f);
}

TEST(Vec4Test, ScaleMultipliesEachComponent)
{
    Vec4 v(3.0f, 4.0f, 5.0f, 6.0f);
    Vec4 result = v.scale(2.0f);
    EXPECT_FLOAT_EQ(result.getX(), 6.0f);
    EXPECT_FLOAT_EQ(result.getY(), 8.0f);
    EXPECT_FLOAT_EQ(result.getZ(), 10.0f);
    EXPECT_FLOAT_EQ(result.getW(), 12.0f);
    EXPECT_FLOAT_EQ(v.getX(), 3.0f);
    EXPECT_FLOAT_EQ(v.getY(), 4.0f);
    EXPECT_FLOAT_EQ(v.getZ(), 5.0f);
    EXPECT_FLOAT_EQ(v.getW(), 6.0f);
}

TEST(Vec4Test, ScaleComponentsMultipliesEachComponentByOwnFactor)
{
    Vec4 v(3.0f, 4.0f, 5.0f, 6.0f);
    Vec4 result = v.scale(2.0f, 5.0f, 3.0f, 0.5f);
    EXPECT_FLOAT_EQ(result.getX(), 6.0f);
    EXPECT_FLOAT_EQ(result.getY(), 20.0f);
    EXPECT_FLOAT_EQ(result.getZ(), 15.0f);
    EXPECT_FLOAT_EQ(result.getW(), 3.0f);
    EXPECT_FLOAT_EQ(v.getX(), 3.0f);
    EXPECT_FLOAT_EQ(v.getY(), 4.0f);
    EXPECT_FLOAT_EQ(v.getZ(), 5.0f);
    EXPECT_FLOAT_EQ(v.getW(), 6.0f);
}

TEST(Vec4Test, PerspectiveDivideDividesXYAndZByW)
{
    Vec4 v(6.0f, 8.0f, 5.0f, 2.0f);
    Vec4 result = v.perspectiveDivide();
    EXPECT_FLOAT_EQ(result.getX(), 3.0f);
    EXPECT_FLOAT_EQ(result.getY(), 4.0f);
    EXPECT_FLOAT_EQ(result.getZ(), 2.5f);
    EXPECT_FLOAT_EQ(result.getW(), 2.0f);
    EXPECT_FLOAT_EQ(v.getX(), 6.0f);
    EXPECT_FLOAT_EQ(v.getY(), 8.0f);
    EXPECT_FLOAT_EQ(v.getZ(), 5.0f);
    EXPECT_FLOAT_EQ(v.getW(), 2.0f);
}

TEST(Vec4Test, PerspectiveDivideLeavesWUnchanged)
{
    Vec4 v(10.0f, 20.0f, -3.5f, 4.0f);
    Vec4 result = v.perspectiveDivide();
    EXPECT_FLOAT_EQ(result.getZ(), -0.875f);
    EXPECT_FLOAT_EQ(result.getW(), 4.0f);
}

TEST(Vec4Test, PrintOutputsComponents)
{
    Vec4 v(3.0f, 4.0f, 5.0f, 6.0f);
    testing::internal::CaptureStdout();
    v.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Vec4(3, 4, 5, 6)\n");
}
