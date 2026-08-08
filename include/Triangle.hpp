#pragma once
#include "math/Vec2.hpp"
#include <vector>

/**
 * Represents a triangle with 3 points in 3-dimensional space
 */
class Triangle
{

public:
    /**
     * Constructor to create a triangle in 2-dimensional space with 3 points
     */
    Triangle(Vec2 p1, Vec2 p2, Vec2 p3);

    /**
     * Constructor to create a triangle in 2-dimensional
     */
    Triangle();

    /**
     * Getter for point one
     */
    Vec2 getP1();

    /**
     * Getter for point two
     */
    Vec2 getP2();

    /**
     * Getter for point three
     */
    Vec2 getP3();


private:
    std::vector<Vec2> points;
};
