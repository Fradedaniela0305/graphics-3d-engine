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
     * Setter for x component
     * @param x - value to set the x component to
     */
    void setX(float x);

    /**
     * Setter for y component
     * @param y - value to set the y component to
     */
    void setY(float y);

    /**
     * Setter for z component
     * @param z - value to set the z component to
     */
    void setZ(float z);

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
     * Returns a new vector representing this vector minus the given vector
     * @param other - vector to subtract from this vector
     */
    Vec3 subtract(Vec3 other);

    /**
     * Returns the cross product of this vector and the given vector, calculated as this x other
     * @param other - vector to cross with this vector
     */
    Vec3 cross(Vec3 other);

    /**
     * Returns the dot product of the normalized versions of this vector and the given vector,
     * equivalent to the cosine of the angle between them. Returns 0 if either vector has zero length.
     * @param other - vector to dot with this vector
     */
    float dot(Vec3 other);

    /**
     * Prints the vector's components to standard output
     */
    void print();

private:
    float components[3];
};
