#include "Window.hpp"
#include <iostream>

int main() {
    Window window("3D Graphics Engine", 800, 600);
    if (!window.init()) {
        return 1;
    }

    int x = 400;
    int y = 300;
    const int speed = 300; // pixels per second

    while (!window.shouldClose()) {
        window.pollEvents();
        float deltaTime = window.tick();

        if (window.isKeyDown(SDL_SCANCODE_W)) y -= (int)(speed * deltaTime);
        if (window.isKeyDown(SDL_SCANCODE_S)) y += (int)(speed * deltaTime);
        if (window.isKeyDown(SDL_SCANCODE_A)) x -= (int)(speed * deltaTime);
        if (window.isKeyDown(SDL_SCANCODE_D)) x += (int)(speed * deltaTime);
        if (window.isKeyDown(SDL_SCANCODE_ESCAPE)) break;

        window.clear({20, 20, 20});

        window.drawRect(50, 50, 100, 60, {200, 60, 60});
        window.drawCircle(x, y, 30, {60, 160, 220});

        if (window.isMouseButtonDown(SDL_BUTTON_LEFT)) {
            int mouseX, mouseY;
            window.getMousePosition(mouseX, mouseY);
            window.drawLine(x, y, mouseX, mouseY, {230, 230, 230});
        }

        window.present();
    }

    return 0;
}
