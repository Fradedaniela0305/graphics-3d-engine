#include "Triangle.hpp"

/**
 * Constructor to create a triangle in 2-dimensional space with 3 points
 */
Triangle::Triangle(Vec2 p1, Vec2 p2, Vec2 p3)
{
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
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
Vec2 Triangle::getP1()
{
    return points[0];
}

/**
 * Getter for point two
 */
Vec2 Triangle::getP2()
{
    return points[1];
}

/**
 * Getter for point three
 */
Vec2 Triangle::getP3()
{
    return points[2];
}
