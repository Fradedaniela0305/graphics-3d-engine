#include "math/Vec2.hpp"

/**
 * Constructor to create a 2nd dimensional vector
 * @param x - represents x-coordinate
 * @param y - represents y-coordinate
 */
Vec2::Vec2(int x, int y)
{
    components[0] = x;
    components[1] = y;
}

/**
 * Constructor to create a 2nd dimensional vector
 */
Vec2::Vec2()
{
}

/**
 * Getter for x component
 */
int Vec2::getX()
{
    return components[0];
}

/**
 * Getter for y component
 */
int Vec2::getY()
{
    return components[1];
}
