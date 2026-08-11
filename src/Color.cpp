#include "Color.hpp"
#include <algorithm>

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : r(r), g(g), b(b), a(a)
{
}

Color::Color()
    : r(0), g(0), b(0), a(255)
{
}

Color Color::scale(float factor) const
{
    factor = std::clamp(factor, 0.0f, 1.0f);
    return Color(
        (uint8_t)(r * factor),
        (uint8_t)(g * factor),
        (uint8_t)(b * factor),
        a);
}

Color Color::lerp(Color other, float t) const
{
    t = std::clamp(t, 0.0f, 1.0f);
    return Color(
        (uint8_t)(r + (other.r - r) * t),
        (uint8_t)(g + (other.g - g) * t),
        (uint8_t)(b + (other.b - b) * t),
        (uint8_t)(a + (other.a - a) * t));
}

Color Color::getColor(float dot) {
    uint8_t value = { static_cast<uint8_t>(dot*255)};
    return Color{value, value, value};
}

bool Color::operator==(const Color &other) const
{
    return r == other.r && g == other.g && b == other.b && a == other.a;
}

bool Color::operator!=(const Color &other) const
{
    return !(*this == other);
}

const Color Color::White{255, 255, 255};
const Color Color::Black{0, 0, 0};
const Color Color::Red{255, 0, 0};
const Color Color::Green{0, 255, 0};
const Color Color::Blue{0, 0, 255};
