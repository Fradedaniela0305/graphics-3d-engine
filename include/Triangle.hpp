#pragma once
#include "Color.hpp"
#include "math/Vec4.hpp"
#include <vector>
#include "Color.hpp"

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
     * Constructor to create a triangle in 3-d with color and normal given
     */
    Triangle(Vec4 p1, Vec4 p2, Vec4 p3, Color color, Vec4 normal);

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
     * Getter for triangle's color
     */
    Color getColor();

    /**
     * Getter for the triangle's normal vector
     */
    Vec4 getNormal();

    /**
     * Returns the triangle's bottom point, i.e. the point with the largest y value.
     * If multiple points share the largest y value, the first such point (in P1, P2, P3 order) is returned.
     */
    Vec4 getBottomPoint();

    /**
     * Returns the triangle's top point, i.e. the point with the smallest y value.
     * If multiple points share the smallest y value, the first such point (in P1, P2, P3 order) is returned.
     */
    Vec4 getTopPoint();

    /**
     * Returns the triangle's leftmost point, i.e. the point with the smallest x value.
     * If multiple points share the smallest x value, the first such point (in P1, P2, P3 order) is returned.
     */
    Vec4 getLeftmostPoint();

    /**
     * Returns the triangle's rightmost point, i.e. the point with the largest x value.
     * If multiple points share the largest x value, the first such point (in P1, P2, P3 order) is returned.
     */
    Vec4 getRightmostPoint();

    /**
     * Prints the triangle's points to standard output
     */
    void print();

private:
    std::vector<Vec4> points;
    Vec4 normal;
    Color color;

    /**
     * Calculates the normalized normal vector of the triangle from its points.
     * The resulting vector's w component is always 0, since a normal represents
     * a direction rather than a position.
     */
    Vec4 calculateNormal();
};
