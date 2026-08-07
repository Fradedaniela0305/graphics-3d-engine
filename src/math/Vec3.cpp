#include "math/Vec3.hpp"

/**
 * Constructor to create a 3rd dimensional vector
 * @param x - represents x-coordinate
 * @param y - represents y-coordinate
 * @param z - represents z-coordinate
 */
Vec3::Vec3(int x, int y, int z)
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
int Vec3::getX()
{
    return components[0];
}

/**
 * Getter for y component
 */
int Vec3::getY()
{
    return components[1];
}

/**
 * Getter for z component
 */
int Vec3::getZ()
{
    return components[2];
}
