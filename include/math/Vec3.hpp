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
    Vec3(int x, int y, int z);

    /**
     * Constructor to create a 3rd dimensional vector
     */
    Vec3();

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

private:
    int components[3];
};
