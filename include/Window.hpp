#pragma once

#include <SDL.h>
#include <cstdint>

struct Color {
    uint8_t r, g, b, a = 255;
};

/**
 * Owns the SDL2 window/renderer, the event loop, input state, and timing.
 */
class Window {

    public:

    Window(const char* title, int width, int height);
    ~Window();

    // Returns false if window/renderer creation failed.
    bool init();

    // Pumps the SDL event queue; updates input state and quit flag.
    void pollEvents();

    bool shouldClose() const { return quit; }

    // Advances the frame clock; returns delta time in seconds since the last call.
    float tick();

    void clear(Color color);
    void present();

    void drawPixel(int x, int y, Color color);
    void drawLine(int x1, int y1, int x2, int y2, Color color);
    void drawRect(int x, int y, int w, int h, Color color, bool filled = true);
    void drawCircle(int centerX, int centerY, int radius, Color color, bool filled = true);

    bool isKeyDown(SDL_Scancode key) const;
    bool isMouseButtonDown(uint8_t button) const;
    void getMousePosition(int& x, int& y) const;

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    private:

    const char* title;
    int width;
    int height;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    const uint8_t* keyboardState = nullptr;
    uint32_t mouseState = 0;
    int mouseX = 0;
    int mouseY = 0;

    uint64_t lastTickCounter = 0;
    bool quit = false;
};
