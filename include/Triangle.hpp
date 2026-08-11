#pragma once
#include "math/Vec4.hpp"
#include <vector>

/**
 * Represents a triangle with 3 points in 3-dimensional space, points are in clockwise order.
 * Points are fixed at construction time and cannot be changed afterwards.
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
     * Getter for the triangle's normal vector
     */
    Vec4 getNormal();

    /**
     * Prints the triangle's points to standard output
     */
    void print();

private:
    std::vector<Vec4> points;
    Vec4 normal;

    /**
     * Calculates the normalized normal vector of the triangle from its points.
     * The resulting vector's w component is always 0, since a normal represents
     * a direction rather than a position.
     */
    Vec4 calculateNormal();
};
