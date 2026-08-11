#include "math/Vec2.hpp"
#include <iostream>

/**
 * Constructor to create a 2nd dimensional vector
 * @param x - represents x-coordinate
 * @param y - represents y-coordinate
 */
Vec2::Vec2(float x, float y)
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
float Vec2::getX()
{
    return components[0];
}

/**
 * Getter for y component
 */
float Vec2::getY()
{
    return components[1];
}

/**
 * Returns a new vector with the given amounts added to each component
 */
Vec2 Vec2::shift(float xAmount, float yAmount)
{
    return Vec2(components[0] + xAmount, components[1] + yAmount);
}

/**
 * Returns a new vector with each component multiplied by the given factor
 */
Vec2 Vec2::scale(float factor)
{
    return Vec2(components[0] * factor, components[1] * factor);
}

/**
 * Returns a new vector with each component multiplied by its own given factor
 */
Vec2 Vec2::scale(float xFactor, float yFactor)
{
    return Vec2(components[0] * xFactor, components[1] * yFactor);
}

/**
 * Returns a new vector representing this vector minus the given vector
 */
Vec2 Vec2::subtract(Vec2 other)
{
    return Vec2(components[0] - other.getX(), components[1] - other.getY());
}

/**
 * Returns the cross product of this vector and the given vector, calculated as this x other
 */
float Vec2::cross(Vec2 other)
{
    return components[0] * other.getY() - components[1] * other.getX();
}

/**
 * Returns the dot product of this vector and the given vector
 */
float Vec2::dot(Vec2 other)
{
    return components[0] * other.getX() + components[1] * other.getY();
}

/**
 * Prints the vector's components to standard output
 */
void Vec2::print()
{
    std::cout << "Vec2(" << components[0] << ", " << components[1] << ")" << std::endl;
}
