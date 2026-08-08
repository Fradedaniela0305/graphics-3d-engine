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
    Vec4(float x, float y, float z, float w);

    /**
     * Constructor to create a 4th dimensional vector
     */
    Vec4();


    /**
     * Getter for x component
     */
    float getX();

    /**
     * Getter for y component
     */

    float getY();

    /**
     * Getter for z component
     */
    float getZ();

    /**
     * Getter for w component
     */
    float getW();

private:
    float components[4];
};
