#include "Window.hpp"
#include "math/Vec4.hpp"
#include "math/Matrix4x4.hpp"
#include <cmath>
#include <iostream>

int main()
{

    Window window("3D Graphics Engine", 800, 600);
    if (!window.init())
    {
        return 1;
    }

    int width = 400;
    int height = 300;
    int a = width / height;
    const int speed = 300; // pixels per second
    float angle = 100;
    float zFar = 10;
    float zNear = 100;

    float f = 1.0f / std::tan(angle / 2.0f);
    float q = zFar / (zFar - zNear);

    Vec4 r1{a*f, 0, 0, 0};
    Vec4 r2{0, f, 0, 0};
    Vec4 r3{0, 0, q, -zNear * q};
    Vec4 r4{0, 0, 1, 0};

    Matrix4x4 transformationMatrix{r1,r2,r3,r4};

    



    while (!window.shouldClose())
    {
        window.pollEvents();
        float deltaTime = window.tick();

        if (window.isKeyDown(SDL_SCANCODE_W))
            height -= (int)(speed * deltaTime);
        if (window.isKeyDown(SDL_SCANCODE_S))
            height += (int)(speed * deltaTime);
        if (window.isKeyDown(SDL_SCANCODE_A))
            width -= (int)(speed * deltaTime);
        if (window.isKeyDown(SDL_SCANCODE_D))
            width += (int)(speed * deltaTime);
        if (window.isKeyDown(SDL_SCANCODE_ESCAPE))
            break;

        window.clear({20, 20, 20});

        window.drawRect(50, 50, 100, 60, {200, 60, 60});


        if (window.isMouseButtonDown(SDL_BUTTON_LEFT))
        {
            int mouseX, mouseY;
            window.getMousePosition(mouseX, mouseY);
        }

        window.present();
    }

    return 0;
}
