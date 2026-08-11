#pragma once

/**
 * Represents a 2nd dimensional vector
 */
class Vec2
{

public:
    /**
     * Constructor to create a 2nd dimensional vector
     * @param x - represents x-coordinate
     * @param y - represents y-coordinate
     */
    Vec2(float x, float y);

    /**
     * Constructor to create a 2nd dimensional vector
     */
    Vec2();

    /**
     * Getter for x component
     */
    float getX();

    /**
     * Getter for y component
     */
    float getY();

    /**
     * Returns a new vector with the given amounts added to each component
     * @param xAmount - value to add to the x component
     * @param yAmount - value to add to the y component
     */
    Vec2 shift(float xAmount, float yAmount);

    /**
     * Returns a new vector with each component multiplied by the given factor
     * @param factor - value to multiply each component by
     */
    Vec2 scale(float factor);

    /**
     * Returns a new vector with each component multiplied by its own given factor
     * @param xFactor - value to multiply the x component by
     * @param yFactor - value to multiply the y component by
     */
    Vec2 scale(float xFactor, float yFactor);

    /**
     * Returns a new vector representing this vector minus the given vector
     * @param other - vector to subtract from this vector
     */
    Vec2 subtract(Vec2 other);

    /**
     * Returns the cross product of this vector and the given vector, calculated as this x other.
     * In 2 dimensions this is a scalar equal to the z-component of the equivalent 3-dimensional cross product.
     * @param other - vector to cross with this vector
     */
    float cross(Vec2 other);

    /**
     * Returns the dot product of this vector and the given vector
     * @param other - vector to dot with this vector
     */
    float dot(Vec2 other);

    /**
     * Prints the vector's components to standard output
     */
    void print();

private:
    float components[2];
};
