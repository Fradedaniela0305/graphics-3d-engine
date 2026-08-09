#include "Triangle.hpp"
#include <iostream>

/**
 * Constructor to create a triangle in 2-dimensional space with 3 points
 */
Triangle::Triangle(Vec4 p1, Vec4 p2, Vec4 p3)
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
