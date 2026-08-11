#include "math/Vec4.hpp"
#include <cmath>
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
 * Returns a new vector representing this vector minus the given vector
 */
Vec4 Vec4::subtract(Vec4 other)
{
    return Vec4(components[0] - other.getX(), components[1] - other.getY(), components[2] - other.getZ(), components[3] - other.getW());
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
 * Returns the cross product of this vector and the given vector, calculated as this x other
 */
Vec4 Vec4::cross(Vec4 other)
{
    return Vec4(
        components[1] * other.getZ() - components[2] * other.getY(),
        components[2] * other.getX() - components[0] * other.getZ(),
        components[0] * other.getY() - components[1] * other.getX(),
        0.0f);
}

/**
 * Returns the dot product of the normalized versions of this vector and the given vector
 */
float Vec4::dot(Vec4 other)
{
    float thisLength = std::sqrt(components[0] * components[0] + components[1] * components[1] + components[2] * components[2] + components[3] * components[3]);
    float otherLength = std::sqrt(other.getX() * other.getX() + other.getY() * other.getY() + other.getZ() * other.getZ() + other.getW() * other.getW());
    if (thisLength == 0 || otherLength == 0)
    {
        return 0.0f;
    }
    return (components[0] * other.getX() + components[1] * other.getY() + components[2] * other.getZ() + components[3] * other.getW()) / (thisLength * otherLength);
}

/**
 * Prints the vector's components to standard output
 */
void Vec4::print()
{
    std::cout << "Vec4(" << components[0] << ", " << components[1] << ", " << components[2] << ", " << components[3] << ")" << std::endl;
}
