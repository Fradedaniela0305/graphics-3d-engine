#include "Triangle.hpp"
#include <iostream>
#include <cmath>

/**
 * Constructor to create a triangle in 2-dimensional space with 3 points
 */
Triangle::Triangle(Vec4 p1, Vec4 p2, Vec4 p3)
{
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    normal = calculateNormal();
}

/**
 * Constructor to create a triangle in 2-dimensional
 */
Triangle::Triangle()
{
}

/**
 * Getter for point one
 */
Vec4 Triangle::getP1()
{
    return points[0];
}

/**
 * Getter for point two
 */
Vec4 Triangle::getP2()
{
    return points[1];
}

/**
 * Getter for point three
 */
Vec4 Triangle::getP3()
{
    return points[2];
}

/**
 * Getter for the triangle's normal vector
 */
Vec4 Triangle::getNormal()
{
    return normal;
}

/**
 * Calculates the normalized normal vector of the triangle from its points
 */
Vec4 Triangle::calculateNormal()
{
    Vec4 edge1 = points[1].subtract(points[0]);
    Vec4 edge2 = points[2].subtract(points[0]);

    Vec4 cross = edge1.cross(edge2);

    float length = std::sqrt(cross.getX() * cross.getX() + cross.getY() * cross.getY() + cross.getZ() * cross.getZ());
    if (length == 0)
    {
        return cross;
    }
    return cross.scale(1.0f / length);
}

/**
 * Prints the triangle's points to standard output
 */
void Triangle::print()
{
    std::cout << "Triangle(" << std::endl;
    std::cout << "  P1: ";
    points[0].print();
    std::cout << "  P2: ";
    points[1].print();
    std::cout << "  P3: ";
    points[2].print();
    std::cout << ")" << std::endl;
}
