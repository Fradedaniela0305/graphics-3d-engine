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

    /**
     * Returns a new vector with the given amounts added to each component
     * @param xAmount - value to add to the x component
     * @param yAmount - value to add to the y component
     * @param zAmount - value to add to the z component
     * @param wAmount - value to add to the w component
     */
    Vec4 shift(float xAmount, float yAmount, float zAmount, float wAmount);

    /**
     * Returns a new vector with each component multiplied by the given factor
     * @param factor - value to multiply each component by
     */
    Vec4 scale(float factor);

    /**
     * Returns a new vector with each component multiplied by its own given factor
     * @param xFactor - value to multiply the x component by
     * @param yFactor - value to multiply the y component by
     * @param zFactor - value to multiply the z component by
     * @param wFactor - value to multiply the w component by
     */
    Vec4 scale(float xFactor, float yFactor, float zFactor, float wFactor);

    /**
     * Returns a new vector with the x, y, and z components divided by w (perspective divide)
     */
    Vec4 perspectiveDivide();

    /**
     * Prints the vector's components to standard output
     */
    void print();

private:
    float components[4];
};
