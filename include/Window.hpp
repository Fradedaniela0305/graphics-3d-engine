#pragma once
#include "Color.hpp"
#include "Triangle.hpp"
#include <SDL.h>
#include <cstdint>

/**
 * Owns the SDL2 window/renderer, the event loop, input state, and timing.
 */
class Window {

    public:

    /**
     * Constructor to create a window
     * @param title - the window's title
     * @param width - the window's width in pixels
     * @param height - the window's height in pixels
     */
    Window(const char* title, int width, int height);

    /**
     * Destructor, destroys the SDL renderer and window
     */
    ~Window();

    /**
     * Creates the SDL window and renderer
     * @returns false if window/renderer creation failed
     */
    bool init();

    /**
     * Pumps the SDL event queue; updates input state and quit flag
     */
    void pollEvents();

    /**
     * Getter for whether the window has been requested to close
     */
    bool shouldClose() const { return quit; }

    /**
     * Advances the frame clock
     * @returns delta time in seconds since the last call
     */
    float tick();

    /**
     * Clears the renderer to a solid color
     * @param color - the color to clear the screen to
     */
    void clear(Color color);

    /**
     * Presents the rendered frame to the screen
     */
    void present();

    /**
     * Draws a single pixel
     * @param x - x-coordinate of the pixel
     * @param y - y-coordinate of the pixel
     * @param color - color of the pixel
     */
    void drawPixel(int x, int y, Color color);

    /**
     * Draws a line between two points
     * @param x1 - x-coordinate of the first point
     * @param y1 - y-coordinate of the first point
     * @param x2 - x-coordinate of the second point
     * @param y2 - y-coordinate of the second point
     * @param color - color of the line
     */
    void drawLine(int x1, int y1, int x2, int y2, Color color);

    /**
     * Draws a rectangle
     * @param x - x-coordinate of the top-left corner
     * @param y - y-coordinate of the top-left corner
     * @param w - width of the rectangle
     * @param h - height of the rectangle
     * @param color - color of the rectangle
     * @param filled - whether the rectangle is filled or just outlined
     */
    void drawRect(int x, int y, int w, int h, Color color, bool filled = true);

    /**
     * Draws a circle
     * @param centerX - x-coordinate of the circle's center
     * @param centerY - y-coordinate of the circle's center
     * @param radius - radius of the circle
     * @param color - color of the circle
     * @param filled - whether the circle is filled or just outlined
     */
    void drawCircle(int centerX, int centerY, int radius, Color color, bool filled = true);

    /**
     * Draws a triangle
     * @param triangle - the triangle to draw
     * @param color - color of the triangle
     */
    void drawTriangle(Triangle triangle, Color color);

    /**
     * Draws a filled triangle
     * @param triangle - the triangle to draw
     * @param color - color of the triangle
     */
    void drawFilledTriangle(Triangle triangle, Color color);

    /**
     * Getter for whether a keyboard key is currently pressed
     * @param key - the SDL scancode of the key to check
     */
    bool isKeyDown(SDL_Scancode key) const;

    /**
     * Getter for whether a mouse button is currently pressed
     * @param button - the SDL button index to check
     */
    bool isMouseButtonDown(uint8_t button) const;

    /**
     * Getter for the current mouse position
     * @param x - output parameter for the mouse x-coordinate
     * @param y - output parameter for the mouse y-coordinate
     */
    void getMousePosition(int& x, int& y) const;

    /**
     * Getter for the window width
     */
    int getWidth() const { return width; }

    /**
     * Getter for the window height
     */
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
