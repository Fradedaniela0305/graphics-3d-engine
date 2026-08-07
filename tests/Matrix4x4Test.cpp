/**
 * @file Matrix4x4Test.cpp
 */

#include <gtest/gtest.h>
#include "math/Matrix4x4.hpp"
#include "math/Vec4.hpp"

TEST(Matrix4x4Test, ConstructorSetsColumns)
{
    Vec4 c1(1, 2, 3, 4);
    Vec4 c2(5, 6, 7, 8);
    Vec4 c3(9, 10, 11, 12);
    Vec4 c4(13, 14, 15, 16);
    Matrix4x4 m(c1, c2, c3, c4);

    EXPECT_EQ(m.getC1().getX(), 1);
    EXPECT_EQ(m.getC1().getW(), 4);

    EXPECT_EQ(m.getC2().getX(), 5);
    EXPECT_EQ(m.getC2().getW(), 8);

    EXPECT_EQ(m.getC3().getX(), 9);
    EXPECT_EQ(m.getC3().getW(), 12);

    EXPECT_EQ(m.getC4().getX(), 13);
    EXPECT_EQ(m.getC4().getW(), 16);
}
