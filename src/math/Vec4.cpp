#include "math/Vec4.hpp"
#include <iostream>

/**
 * Constructor to create a 4th dimensional vector
 * @param x - represents x-coordinate
 * @param y - represents y-coordinate
 * @param z - represents z-coordinate
 * @param w - represents w-coordinate
 */
Vec4::Vec4(float x, float y, float z, float w)
{
    components[0] = x;
    components[1] = y;
    components[2] = z;
    components[3] = w;
}

/**
 * Constructor to create a 4th dimensional vector
 */
Vec4::Vec4()
{
}

/**
 * Getter for x component
 */
float Vec4::getX()
{
    return components[0];
}

/**
 * Getter for y component
 */

float Vec4::getY()
{
    return components[1];
}

/**
 * Getter for z component
 */
float Vec4::getZ()
{
    return components[2];
}

/**
 * Getter for w component
 */
float Vec4::getW()
{
    return components[3];
}

/**
 * Returns a new vector with the given amounts added to each component
 */
Vec4 Vec4::shift(float xAmount, float yAmount, float zAmount, float wAmount)
{
    return Vec4(components[0] + xAmount, components[1] + yAmount, components[2] + zAmount, components[3] + wAmount);
}

/**
 * Returns a new vector with each component multiplied by the given factor
 */
Vec4 Vec4::scale(float factor)
{
    return Vec4(components[0] * factor, components[1] * factor, components[2] * factor, components[3] * factor);
}

/**
 * Returns a new vector with each component multiplied by its own given factor
 */
Vec4 Vec4::scale(float xFactor, float yFactor, float zFactor, float wFactor)
{
    return Vec4(components[0] * xFactor, components[1] * yFactor, components[2] * zFactor, components[3] * wFactor);
}

/**
 * Returns a new vector with the x and y components divided by w (perspective divide)
 */
Vec4 Vec4::perspectiveDivide()
{

    if (components[3] != 0)
    {
        return Vec4(components[0] / components[3], components[1] / components[3], components[2] / components[3], components[3]);
    } 
    return Vec4(components[0], components[1], components[2], components[3]);
}

/**
 * Prints the vector's components to standard output
 */
void Vec4::print()
{
    std::cout << "Vec4(" << components[0] << ", " << components[1] << ", " << components[2] << ", " << components[3] << ")" << std::endl;
}
