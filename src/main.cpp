#include "Window.hpp"
#include "math/Vec4.hpp"
#include "math/Matrix4x4.hpp"
#include "Mesh.hpp"
#include "Triangle.hpp"
#include <cmath>
#include <iostream>
#include <vector>

int main()
{

    Window window("3D Graphics Engine", 800, 600);
    if (!window.init())
    {
        return 1;
    }

    int width = 800;
    int height = 600;

    float aspectRatio = (float)width / height;
    float fView = 90.0f;
    float fFar = 1000.0f;
    float fNear = 0.1f;

    float fViewRad = fView * (float)M_PI / 180.0f;
    float f = 1.0f / std::tan(fViewRad / 2.0f);
    float q = fFar / (fFar - fNear);

    Vec4 r1{(float)f / aspectRatio, 0, 0, 0};
    Vec4 r2{0, f, 0, 0};
    Vec4 r3{0, 0, q, -fNear * q};
    Vec4 r4{0, 0, 1, 0};

    Matrix4x4 projectionMat{r1, r2, r3, r4};

    Matrix4x4 translationMat{
        Vec4{1, 0, 0, 0},
        Vec4{0, 1, 0, 0},
        Vec4{0, 0, 1, 5},
        Vec4{0, 0, 0, 1}};

    Mesh shipMesh;
    bool loaded = shipMesh.loadFromObjectFile("objects/teapot.obj");

    Mesh sortedShipMesh;

    if (!loaded)
    {
        return 0;
    }

    float angle = 45.0f * M_PI / 180.0f;
    Matrix4x4 rotationMat;
    Vec4 lightVec{0.0, 0.0, -1.0, 0.0};
    Vec4 camera{0.0, 0.0, 0.0, 0.0};

    while (!window.shouldClose())
    {
        window.pollEvents();

        if (window.isKeyDown(SDL_SCANCODE_W))
        {
            camera.setZ(camera.getZ()+0.1);
        }
        if (window.isKeyDown(SDL_SCANCODE_A))
        {
            camera.setX(camera.getX()-0.1);
        }
        if (window.isKeyDown(SDL_SCANCODE_S))
        {
            camera.setZ(camera.getZ()-0.1);
        }
        if (window.isKeyDown(SDL_SCANCODE_D))
        {
            camera.setX(camera.getX()+0.1);
        }
        if (window.isKeyDown(SDL_SCANCODE_UP))
        {
            camera.setY(camera.getY()+0.1);
        }
        if (window.isKeyDown(SDL_SCANCODE_LEFT))
        {
        }
        if (window.isKeyDown(SDL_SCANCODE_RIGHT))
        {
        }
        if (window.isKeyDown(SDL_SCANCODE_DOWN))
        {
            camera.setY(camera.getY()-0.1);
        }

        window.clear({20, 20, 20});
        angle += 0.01;
        sortedShipMesh.clearMesh();
        for (Triangle &t : shipMesh.getMesh())
        {

            float c = cosf(angle);
            float s = sinf(angle);
            float ch = cosf(angle * 0.5f);
            float sh = sinf(angle * 0.5f);

            rotationMat = Matrix4x4{
                Vec4{c, s * ch, s * sh, 0},
                Vec4{-s, c * ch, c * sh, 0},
                Vec4{0, -sh, ch, 0},
                Vec4{0, 0, 0, 1}};

            Triangle transformedTriangle = rotationMat.transformTriangle(t);
            Triangle translatedTriangle = translationMat.transformTriangle(transformedTriangle);

            Triangle viewedTriangle{translatedTriangle.getP1().subtract(camera),
                                    translatedTriangle.getP2().subtract(camera),
                                    translatedTriangle.getP3().subtract(camera)};

            Vec4 normal = viewedTriangle.getNormal();
            Vec4 cameraToPlaneVec = viewedTriangle.getP1().subtract(camera);

            if (normal.dot(cameraToPlaneVec) > 0)
            {
                continue;
            }

            Triangle projectedTriangle = projectionMat.transformTriangle(viewedTriangle);

            Vec4 p1 = projectedTriangle.getP1().perspectiveDivide().shift(1.0f, 1.0f, 0, 0).scale(0.5f * width, 0.5f * height, 1, 1);
            Vec4 p2 = projectedTriangle.getP2().perspectiveDivide().shift(1.0f, 1.0f, 0, 0).scale(0.5f * width, 0.5f * height, 1, 1);
            Vec4 p3 = projectedTriangle.getP3().perspectiveDivide().shift(1.0f, 1.0f, 0, 0).scale(0.5f * width, 0.5f * height, 1, 1);

            Triangle drawnTriangle{p1, p2, p3};
            Color triangleColor = Color::getColor(normal.dot(camera));
            drawnTriangle.setColor(triangleColor);

            sortedShipMesh.addTriangle(drawnTriangle);
        }

        sortedShipMesh.sortMesh();

        for (Triangle &drawnTriangle : sortedShipMesh.getMesh())
        {

            window.drawFilledTriangle(drawnTriangle, drawnTriangle.getColor());
            // window.drawTriangle(drawnTriangle, {0, 0, 0});
        }

        window.present();
    }

    return 0;
}
