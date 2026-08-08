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

private:
    float components[2];
};
