/**
 * @file Matrix4x4Test.cpp
 */

#include <gtest/gtest.h>
#include "math/Matrix4x4.hpp"
#include "math/Vec4.hpp"

TEST(Matrix4x4Test, ConstructorSetsColumns)
{
    Vec4 c1(1.0f, 2.0f, 3.0f, 4.0f);
    Vec4 c2(5.0f, 6.0f, 7.0f, 8.0f);
    Vec4 c3(9.0f, 10.0f, 11.0f, 12.0f);
    Vec4 c4(13.0f, 14.0f, 15.0f, 16.0f);
    Matrix4x4 m(c1, c2, c3, c4);

    EXPECT_FLOAT_EQ(m.getC1().getX(), 1.0f);
    EXPECT_FLOAT_EQ(m.getC1().getW(), 4.0f);

    EXPECT_FLOAT_EQ(m.getC2().getX(), 5.0f);
    EXPECT_FLOAT_EQ(m.getC2().getW(), 8.0f);

    EXPECT_FLOAT_EQ(m.getC3().getX(), 9.0f);
    EXPECT_FLOAT_EQ(m.getC3().getW(), 12.0f);

    EXPECT_FLOAT_EQ(m.getC4().getX(), 13.0f);
    EXPECT_FLOAT_EQ(m.getC4().getW(), 16.0f);
}
