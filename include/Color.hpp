#pragma once
#include <cstdint>

/**
 * Represents an RGBA color, with 8 bits per channel
 */
class Color
{

public:
    uint8_t r, g, b, a;

    /**
     * Constructor to create a color
     * @param r - red channel
     * @param g - green channel
     * @param b - blue channel
     * @param a - alpha channel, defaults to fully opaque
     */
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);

    /**
     * Constructor to create an opaque black color
     */
    Color();

    /**
     * Returns a new color with the r, g, and b channels scaled by the given factor, e.g. for shading.
     * The factor is clamped to [0, 1] before scaling; the alpha channel is left unchanged.
     * @param factor - amount to scale each of the r, g, b channels by
     */
    Color scale(float factor) const;

    /**
     * Returns a new color that is linearly interpolated between this color and the given color
     * @param other - color to interpolate towards
     * @param t - interpolation amount, clamped to [0, 1], where 0 returns this color and 1 returns other
     */
    Color lerp(Color other, float t) const;

    /**
     * Returns a new grayscale color using the dot product to determine the value
     * @param dot - the dot product of the vectors
     */

    Color static getColor(float dot);

    /**
     * Equality operator, compares all four channels
     */
    bool operator==(const Color &other) const;

    /**
     * Inequality operator, compares all four channels
     */
    bool operator!=(const Color &other) const;

    static const Color White;
    static const Color Black;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
};
