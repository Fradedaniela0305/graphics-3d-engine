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

    /**
     * Returns a new vector with the given amounts added to each component
     * @param xAmount - value to add to the x component
     * @param yAmount - value to add to the y component
     * @param zAmount - value to add to the z component
     */
    Vec3 shift(float xAmount, float yAmount, float zAmount);

    /**
     * Returns a new vector with each component multiplied by the given factor
     * @param factor - value to multiply each component by
     */
    Vec3 scale(float factor);

    /**
     * Returns a new vector with each component multiplied by its own given factor
     * @param xFactor - value to multiply the x component by
     * @param yFactor - value to multiply the y component by
     * @param zFactor - value to multiply the z component by
     */
    Vec3 scale(float xFactor, float yFactor, float zFactor);

    /**
     * Prints the vector's components to standard output
     */
    void print();

private:
    float components[3];
};
