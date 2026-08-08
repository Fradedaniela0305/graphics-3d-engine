#pragma once

/**
 * Represents a 3rd dimensional vector
 */
class Vec3
{

public:
    /**
     * Constructor to create a 3rd dimensional vector
     * @param x - represents x-coordinate
     * @param y - represents y-coordinate
     * @param z - represents z-coordinate
     */
    Vec3(float x, float y, float z);

    /**
     * Constructor to create a 3rd dimensional vector
     */
    Vec3();

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

private:
    float components[3];
};
