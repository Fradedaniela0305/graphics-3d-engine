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
    Vec2(int x, int y);

    /**
     * Constructor to create a 2nd dimensional vector
     */
    Vec2();

    /**
     * Getter for x component
     */
    int getX();

    /**
     * Getter for y component
     */
    int getY();

private:
    int components[2];
};
