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

TEST(MeshTest, SortMeshOrdersTrianglesByZthMidPointAscending)
{
    // zthMidPoint values: near = 1, mid = 5, far = 9
    Triangle near(Vec4(0.0f, 0.0f, 0.0f, 1.0f), Vec4(0.0f, 0.0f, 1.0f, 1.0f), Vec4(0.0f, 0.0f, 2.0f, 1.0f));
    Triangle mid(Vec4(0.0f, 0.0f, 4.0f, 1.0f), Vec4(0.0f, 0.0f, 5.0f, 1.0f), Vec4(0.0f, 0.0f, 6.0f, 1.0f));
    Triangle far(Vec4(0.0f, 0.0f, 8.0f, 1.0f), Vec4(0.0f, 0.0f, 9.0f, 1.0f), Vec4(0.0f, 0.0f, 10.0f, 1.0f));

    Mesh mesh;
    mesh.addTriangle(near);
    mesh.addTriangle(far);
    mesh.addTriangle(mid);

    mesh.sortMesh();

    std::vector<Triangle> sorted = mesh.getMesh();
    ASSERT_EQ(sorted.size(), 3u);
    EXPECT_FLOAT_EQ(sorted[0].zthMidPoint(), 1.0f);
    EXPECT_FLOAT_EQ(sorted[1].zthMidPoint(), 5.0f);
    EXPECT_FLOAT_EQ(sorted[2].zthMidPoint(), 9.0f);
}

TEST(MeshTest, SortMeshOnEmptyMeshDoesNotCrash)
{
    Mesh mesh;
    mesh.sortMesh();
    EXPECT_EQ(mesh.getMesh().size(), 0u);
}

TEST(MeshTest, ClearMeshRemovesAllTriangles)
{
    Triangle t1(Vec4(0.0f, 0.0f, 0.0f, 1.0f), Vec4(1.0f, 0.0f, 0.0f, 1.0f), Vec4(0.0f, 1.0f, 0.0f, 1.0f));
    Triangle t2(Vec4(1.0f, 1.0f, 0.0f, 1.0f), Vec4(2.0f, 1.0f, 0.0f, 1.0f), Vec4(1.0f, 2.0f, 0.0f, 1.0f));

    Mesh mesh;
    mesh.addTriangle(t1);
    mesh.addTriangle(t2);

    mesh.clearMesh();

    EXPECT_EQ(mesh.getMesh().size(), 0u);
}

TEST(MeshTest, ClearMeshOnEmptyMeshDoesNotCrash)
{
    Mesh mesh;
    mesh.clearMesh();
    EXPECT_EQ(mesh.getMesh().size(), 0u);
}
