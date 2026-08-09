#include "math/Vec3.hpp"
#include <iostream>

/**
 * Constructor to create a 3rd dimensional vector
 * @param x - represents x-coordinate
 * @param y - represents y-coordinate
 * @param z - represents z-coordinate
 */
Vec3::Vec3(float x, float y, float z)
{
    components[0] = x;
    components[1] = y;
    components[2] = z;
}

/**
 * Constructor to create a 3rd dimensional vector
 */
Vec3::Vec3()
{
}

/**
 * Getter for x component
 */
float Vec3::getX()
{
    return components[0];
}

/**
 * Getter for y component
 */
float Vec3::getY()
{
    return components[1];
}

/**
 * Getter for z component
 */
float Vec3::getZ()
{
    return components[2];
}

/**
 * Returns a new vector with the given amounts added to each component
 */
Vec3 Vec3::shift(float xAmount, float yAmount, float zAmount)
{
    return Vec3(components[0] + xAmount, components[1] + yAmount, components[2] + zAmount);
}

/**
 * Returns a new vector with each component multiplied by the given factor
 */
Vec3 Vec3::scale(float factor)
{
    return Vec3(components[0] * factor, components[1] * factor, components[2] * factor);
}

/**
 * Returns a new vector with each component multiplied by its own given factor
 */
Vec3 Vec3::scale(float xFactor, float yFactor, float zFactor)
{
    return Vec3(components[0] * xFactor, components[1] * yFactor, components[2] * zFactor);
}

/**
 * Prints the vector's components to standard output
 */
void Vec3::print()
{
    std::cout << "Vec3(" << components[0] << ", " << components[1] << ", " << components[2] << ")" << std::endl;
}
