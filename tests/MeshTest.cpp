/**
 * @file MeshTest.cpp
 */

#include <gtest/gtest.h>
#include "Mesh.hpp"
#include "Triangle.hpp"
#include "math/Vec4.hpp"

TEST(MeshTest, ConstructorSetsMesh)
{
    Triangle t1(Vec4(0.0f, 0.0f, 0.0f, 1.0f), Vec4(1.0f, 0.0f, 0.0f, 1.0f), Vec4(0.0f, 1.0f, 0.0f, 1.0f));
    Triangle t2(Vec4(1.0f, 1.0f, 0.0f, 1.0f), Vec4(2.0f, 1.0f, 0.0f, 1.0f), Vec4(1.0f, 2.0f, 0.0f, 1.0f));
    std::vector<Triangle> triangles{t1, t2};

    Mesh mesh(triangles);

    EXPECT_EQ(mesh.getMesh().size(), 2u);
    EXPECT_FLOAT_EQ(mesh.getMesh()[1].getP1().getX(), 1.0f);
}

TEST(MeshTest, DefaultConstructorConstructs)
{
    Mesh mesh;
    EXPECT_EQ(mesh.getMesh().size(), 0u);
}

TEST(MeshTest, AddTriangleAppendsTriangle)
{
    Mesh mesh;
    Triangle t(Vec4(0.0f, 0.0f, 0.0f, 1.0f), Vec4(1.0f, 0.0f, 0.0f, 1.0f), Vec4(0.0f, 1.0f, 0.0f, 1.0f));

    mesh.addTriangle(t);

    ASSERT_EQ(mesh.getMesh().size(), 1u);
    EXPECT_FLOAT_EQ(mesh.getMesh()[0].getP2().getX(), 1.0f);
}
