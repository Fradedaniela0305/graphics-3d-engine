#pragma once
#include "math/Vec4.hpp"
#include <vector>

/**
 * Represents a triangle with 3 points in 3-dimensional space, points are in clockwise order
 */
class Triangle
{

public:
    /**
     * Constructor to create a triangle in 2-dimensional space with 3 points
     */
    Triangle(Vec4 p1, Vec4 p2, Vec4 p3);

    /**
     * Constructor to create a triangle in 2-dimensional
     */
    Triangle();

    /**
     * Getter for point one
     */
    Vec4 getP1();

    /**
     * Getter for point two
     */
    Vec4 getP2();

    /**
     * Getter for point three
     */
    Vec4 getP3();

    /**
     * Prints the triangle's points to standard output
     */
    void print();

private:
    std::vector<Vec4> points;
};
