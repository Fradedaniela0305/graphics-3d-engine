#include "Window.hpp"
#include <iostream>

Window::Window(const char *title, int width, int height)
    : title(title), width(width), height(height)
{
}

Window::~Window()
{
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
    }
    if (window)
    {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}

bool Window::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cerr << "SDL_CreateWindow failed: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "SDL_CreateRenderer failed: " << SDL_GetError() << std::endl;
        return false;
    }

    keyboardState = SDL_GetKeyboardState(nullptr);
    lastTickCounter = SDL_GetPerformanceCounter();

    return true;
}

void Window::pollEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            quit = true;
        }
    }
    mouseState = SDL_GetMouseState(&mouseX, &mouseY);
}

float Window::tick()
{
    uint64_t now = SDL_GetPerformanceCounter();
    float deltaTime = (float)(now - lastTickCounter) / (float)SDL_GetPerformanceFrequency();
    lastTickCounter = now;
    return deltaTime;
}

void Window::clear(Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}

void Window::present()
{
    SDL_RenderPresent(renderer);
}

void Window::drawPixel(int x, int y, Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(renderer, x, y);
}

void Window::drawLine(int x1, int y1, int x2, int y2, Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void Window::drawTriangle(Triangle triangle, Color color)
{
    drawLine(triangle.getP1().getX(), triangle.getP1().getY(), triangle.getP2().getX(), triangle.getP2().getY(), color);
    drawLine(triangle.getP2().getX(), triangle.getP2().getY(), triangle.getP3().getX(), triangle.getP3().getY(), color);
    drawLine(triangle.getP3().getX(), triangle.getP3().getY(), triangle.getP1().getX(), triangle.getP1().getY(), color);
}

/**
 * Draws a filled triangle
 * @param triangle - the triangle to draw
 * @param color - color of the triangle
 */
void Window::drawFilledTriangle(Triangle triangle, Color color)
{
    SDL_Color sdlColor = {color.r, color.g, color.b, color.a};
    SDL_Vertex vertices[3] = {
        {{(float)triangle.getP1().getX(), (float)triangle.getP1().getY()}, sdlColor, {0, 0}},
        {{(float)triangle.getP2().getX(), (float)triangle.getP2().getY()}, sdlColor, {0, 0}},
        {{(float)triangle.getP3().getX(), (float)triangle.getP3().getY()}, sdlColor, {0, 0}},
    };
    SDL_RenderGeometry(renderer, nullptr, vertices, 3, nullptr, 0);
}

void Window::drawRect(int x, int y, int w, int h, Color color, bool filled)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = {x, y, w, h};
    if (filled)
    {
        SDL_RenderFillRect(renderer, &rect);
    }
    else
    {
        SDL_RenderDrawRect(renderer, &rect);
    }
}

void Window::drawCircle(int centerX, int centerY, int radius, Color color, bool filled)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        if (filled)
        {
            SDL_RenderDrawLine(renderer, centerX - x, centerY + y, centerX + x, centerY + y);
            SDL_RenderDrawLine(renderer, centerX - x, centerY - y, centerX + x, centerY - y);
            SDL_RenderDrawLine(renderer, centerX - y, centerY + x, centerX + y, centerY + x);
            SDL_RenderDrawLine(renderer, centerX - y, centerY - x, centerX + y, centerY - x);
        }
        else
        {
            SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
            SDL_RenderDrawPoint(renderer, centerX + y, centerY + x);
            SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);
            SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
            SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
            SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);
            SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
            SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);
        }

        y++;
        if (err <= 0)
        {
            err += 2 * y + 1;
        }
        if (err > 0)
        {
            x--;
            err -= 2 * x + 1;
        }
    }
}

bool Window::isKeyDown(SDL_Scancode key) const
{
    return keyboardState && keyboardState[key];
}

bool Window::isMouseButtonDown(uint8_t button) const
{
    return mouseState & SDL_BUTTON(button);
}

void Window::getMousePosition(int &x, int &y) const
{
    x = mouseX;
    y = mouseY;
}
