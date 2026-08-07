#pragma once

/**
 * Represents a 4th dimensional vector
 */
class Vec4
{

public:
    /**
     * Constructor to create a 4th dimensional vector
     * @param x - represents x-coordinate
     * @param y - represents y-coordinate
     * @param z - represents z-coordinate
     * @param w - represents w-coordinate
     */
    Vec4(int x, int y, int z, int w);

    /**
     * Constructor to create a 4th dimensional vector
     */
    Vec4();

    /**
     * Getter for x component
     */
    int getX();

    /**
     * Getter for y component
     */

    int getY();

    /**
     * Getter for z component
     */
    int getZ();

    /**
     * Getter for w component
     */
    int getW();

private:
    int components[4];
};
