#include "math/Vec4.hpp"

/**
 * Constructor to create a 4th dimensional vector
 * @param x - represents x-coordinate
 * @param y - represents y-coordinate
 * @param z - represents z-coordinate
 * @param w - represents w-coordinate
 */
Vec4::Vec4(int x, int y, int z, int w)
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
int Vec4::getX()
{
    return components[0];
}

/**
 * Getter for y component
 */

int Vec4::getY()
{
    return components[1];
}

/**
 * Getter for z component
 */
int Vec4::getZ()
{
    return components[2];
}

/**
 * Getter for w component
 */
int Vec4::getW()
{
    return components[3];
}
