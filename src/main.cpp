#include "Window.hpp"
#include "math/Vec4.hpp"
#include "math/Matrix4x4.hpp"
#include "Mesh.hpp"
#include "Triangle.hpp"
#include <cmath>
#include <iostream>

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

    Vec4 camera(0,0,0,0);

    Matrix4x4 projectionMat{r1, r2, r3, r4};

    float x = 1.0f / std::sqrt(3.0f);
    float y = 1.0f / std::sqrt(3.0f);
    float z = 1.0f / std::sqrt(3.0f);

    Matrix4x4 translationMat{
        Vec4{1, 0, 0, 0},
        Vec4{0, 1, 0, 0},
        Vec4{0, 0, 1, 3},
        Vec4{0, 0, 0, 1}};

    Triangle southTop{
        Vec4(0, 1, 0, 1),
        Vec4(1, 1, 0, 1),
        Vec4(1, 0, 0, 1)};

    Triangle southBottom{
        Vec4(0, 1, 0, 1),
        Vec4(1, 0, 0, 1),
        Vec4(0, 0, 0, 1)};

    Triangle northTop{
        Vec4(0, 1, 1, 1),
        Vec4(1, 0, 1, 1),
        Vec4(1, 1, 1, 1)};

    Triangle northBottom{
        Vec4(0, 1, 1, 1),
        Vec4(0, 0, 1, 1),
        Vec4(1, 0, 1, 1)};

    Triangle eastTop{
        Vec4(1, 1, 0, 1),
        Vec4(1, 1, 1, 1),
        Vec4(1, 0, 1, 1)};

    Triangle eastBottom{
        Vec4(1, 1, 0, 1),
        Vec4(1, 0, 1, 1),
        Vec4(1, 0, 0, 1)};

    Triangle westTop{
        Vec4(0, 1, 0, 1),
        Vec4(0, 0, 1, 1),
        Vec4(0, 1, 1, 1)};

    Triangle westBottom{
        Vec4(0, 1, 0, 1),
        Vec4(0, 0, 0, 1),
        Vec4(0, 0, 1, 1)};

    Triangle topTop{
        Vec4(0, 1, 0, 1),
        Vec4(0, 1, 1, 1),
        Vec4(1, 1, 1, 1)};

    Triangle topBottom{
        Vec4(0, 1, 0, 1),
        Vec4(1, 1, 1, 1),
        Vec4(1, 1, 0, 1)};

    Triangle bottomTop{
        Vec4(0, 0, 0, 1),
        Vec4(1, 0, 1, 1),
        Vec4(0, 0, 1, 1)};

    Triangle bottomBottom{
        Vec4(0, 0, 0, 1),
        Vec4(1, 0, 0, 1),
        Vec4(1, 0, 1, 1)};

    std::vector<Triangle> triangles = {southTop, southBottom, northTop, northBottom, eastTop, eastBottom, westTop, westBottom, topTop, topBottom, bottomTop, bottomBottom};

    Mesh squareMesh{triangles};
    float angle = 45.0f * M_PI / 180.0f;
    Matrix4x4 rotationMat;
    Vec4 lightVec{0.0,0.0,-1.0,0.0};

    bool printed = false;
    while (!window.shouldClose())
    {
        window.pollEvents();

        window.clear({20, 20, 20});

        angle += 0.001;
        for (Triangle &t : squareMesh.getMesh())
        {

            float c = std::cos(angle);
            float s = std::sin(angle);

            rotationMat = Matrix4x4{
                Vec4{
                    c + x * x * (1 - c),
                    y * x * (1 - c) + z * s,
                    z * x * (1 - c) - y * s,
                    0},

                Vec4{
                    x * y * (1 - c) - z * s,
                    c + y * y * (1 - c),
                    z * y * (1 - c) + x * s,
                    0},

                Vec4{
                    x * z * (1 - c) + y * s,
                    y * z * (1 - c) - x * s,
                    c + z * z * (1 - c),
                    0},

                Vec4{0, 0, 0, 1}};

            Triangle transformedTriangle = rotationMat.transformTriangle(t);
            Triangle translatedTriangle = translationMat.transformTriangle(transformedTriangle);

            Vec4 normal = translatedTriangle.getNormal();
            Vec4 cameraToPlaneVec = translatedTriangle.getP1().subtract(camera);

            if (normal.dot(cameraToPlaneVec) > 0)
            {
                continue;
            }

            Triangle projectedTriangle = projectionMat.transformTriangle(translatedTriangle);

            Vec4 p1 = projectedTriangle.getP1().perspectiveDivide().shift(1.0f, 1.0f, 0, 0).scale(0.5f * width, 0.5f * height, 1, 1);
            Vec4 p2 = projectedTriangle.getP2().perspectiveDivide().shift(1.0f, 1.0f, 0, 0).scale(0.5f * width, 0.5f * height, 1, 1);
            Vec4 p3 = projectedTriangle.getP3().perspectiveDivide().shift(1.0f, 1.0f, 0, 0).scale(0.5f * width, 0.5f * height, 1, 1);

            Triangle drawnTriangle{p1, p2, p3};

            Color triangleColor = Color::getColor(normal.dot(lightVec));

            window.drawFilledTriangle(drawnTriangle, triangleColor);
        }

        window.present();
    }

    return 0;
}
