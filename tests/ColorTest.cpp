/**
 * @file ColorTest.cpp
 */

#include <gtest/gtest.h>
#include "Color.hpp"

TEST(ColorTest, ConstructorSetsChannels)
{
    Color c(10, 20, 30, 40);
    EXPECT_EQ(c.r, 10);
    EXPECT_EQ(c.g, 20);
    EXPECT_EQ(c.b, 30);
    EXPECT_EQ(c.a, 40);
}

TEST(ColorTest, ConstructorDefaultsAlphaToOpaque)
{
    Color c(10, 20, 30);
    EXPECT_EQ(c.a, 255);
}

TEST(ColorTest, DefaultConstructorIsOpaqueBlack)
{
    Color c;
    EXPECT_EQ(c.r, 0);
    EXPECT_EQ(c.g, 0);
    EXPECT_EQ(c.b, 0);
    EXPECT_EQ(c.a, 255);
}

TEST(ColorTest, ScaleMultipliesRgbChannelsAndLeavesAlpha)
{
    Color c(100, 50, 200, 128);
    Color result = c.scale(0.5f);
    EXPECT_EQ(result.r, 50);
    EXPECT_EQ(result.g, 25);
    EXPECT_EQ(result.b, 100);
    EXPECT_EQ(result.a, 128);
}

TEST(ColorTest, ScaleClampsFactorToZeroAndOne)
{
    Color c(100, 50, 200);
    EXPECT_EQ(c.scale(-1.0f), Color(0, 0, 0));
    EXPECT_EQ(c.scale(2.0f), Color(100, 50, 200));
}

TEST(ColorTest, LerpAtZeroReturnsThisColor)
{
    Color a(0, 0, 0, 0);
    Color b(255, 255, 255, 255);
    EXPECT_EQ(a.lerp(b, 0.0f), a);
}

TEST(ColorTest, LerpAtOneReturnsOtherColor)
{
    Color a(0, 0, 0, 0);
    Color b(255, 255, 255, 255);
    EXPECT_EQ(a.lerp(b, 1.0f), b);
}

TEST(ColorTest, LerpAtHalfInterpolatesEachChannel)
{
    Color a(0, 0, 0, 0);
    Color b(200, 100, 50, 20);
    Color result = a.lerp(b, 0.5f);
    EXPECT_EQ(result.r, 100);
    EXPECT_EQ(result.g, 50);
    EXPECT_EQ(result.b, 25);
    EXPECT_EQ(result.a, 10);
}

TEST(ColorTest, LerpClampsTToZeroAndOne)
{
    Color a(0, 0, 0);
    Color b(255, 255, 255);
    EXPECT_EQ(a.lerp(b, -1.0f), a);
    EXPECT_EQ(a.lerp(b, 2.0f), b);
}

TEST(ColorTest, EqualityComparesAllChannels)
{
    EXPECT_TRUE(Color(1, 2, 3, 4) == Color(1, 2, 3, 4));
    EXPECT_FALSE(Color(1, 2, 3, 4) == Color(1, 2, 3, 5));
    EXPECT_TRUE(Color(1, 2, 3, 4) != Color(9, 2, 3, 4));
    EXPECT_FALSE(Color(1, 2, 3, 4) != Color(1, 2, 3, 4));
}

TEST(ColorTest, PresetsHaveExpectedChannels)
{
    EXPECT_EQ(Color::White, Color(255, 255, 255));
    EXPECT_EQ(Color::Black, Color(0, 0, 0));
    EXPECT_EQ(Color::Red, Color(255, 0, 0));
    EXPECT_EQ(Color::Green, Color(0, 255, 0));
    EXPECT_EQ(Color::Blue, Color(0, 0, 255));
}
