#include "Window.hpp"
#include "math/Vec4.hpp"
#include "math/Matrix4x4.hpp"
#include "Mesh.hpp"
#include "Triangle.hpp"
#include <algorithm>
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

    float yawAngle = 0;

    Vec4 worldUp{0, 1, 0, 0};
    Vec4 worldRight{1, 0, 0, 0};
    Vec4 worldForward{0, 0, 1, 0};

    Vec4 cameraForward{0, 0, 1, 0};
    Vec4 cameraRight{1, 0, 0, 0};
    Vec4 cameraUp{0, 1, 0, 0};

    Vec4 camera{0.0, 0.0, -1.0, 0.0};

    Vec4 r1{(float)f / aspectRatio, 0, 0, 0};
    Vec4 r2{0, f, 0, 0};
    Vec4 r3{0, 0, q, -fNear * q};
    Vec4 r4{0, 0, 1, 0};

    Matrix4x4 projectionMat{r1, r2, r3, r4};

    Matrix4x4 translationMat{
        Vec4{1, 0, 0, 0},
        Vec4{0, 1, 0, 0},
        Vec4{0, 0, 1, 4},
        Vec4{0, 0, 0, 1}};

    Mesh shipMesh;
    bool loaded = shipMesh.loadFromObjectFile("objects/teapot.obj");
    Mesh sortedShipMesh;
    Mesh clippedTrianglesMesh;

    Vec4 normal;

    if (!loaded)
    {
        std::cerr << "Failed to load objects/cube.obj. Run from the project root.\n";
        return 1;
    }

    float angle = 45.0f * M_PI / 180.0f;
    Matrix4x4 rotationMat;
    Vec4 lightVec{0.0, 0.0, -1.0, 0.0};

    while (!window.shouldClose())
    {
        window.pollEvents();

        if (window.isKeyDown(SDL_SCANCODE_W))
        {
            camera.setZ(camera.getZ() + 0.1);
        }
        if (window.isKeyDown(SDL_SCANCODE_A))
        {
            camera.setX(camera.getX() - 0.1);
        }
        if (window.isKeyDown(SDL_SCANCODE_S))
        {
            camera.setZ(camera.getZ() - 0.1);
        }
        if (window.isKeyDown(SDL_SCANCODE_D))
        {
            camera.setX(camera.getX() + 0.1);
        }
        if (window.isKeyDown(SDL_SCANCODE_UP))
        {
            camera.setY(camera.getY() - 0.1);
        }
        if (window.isKeyDown(SDL_SCANCODE_LEFT))
        {
            yawAngle -= 0.1f;
        }
        if (window.isKeyDown(SDL_SCANCODE_RIGHT))
        {
            yawAngle += 0.1f;
        }
        if (window.isKeyDown(SDL_SCANCODE_DOWN))
        {
            camera.setY(camera.getY() + 0.1);
        }

        cameraForward.setX(sinf(yawAngle));
        cameraForward.setY(0.0f);
        cameraForward.setZ(cosf(yawAngle));

        cameraRight = worldUp.cross(cameraForward);
        cameraUp = cameraForward.cross(cameraRight);

        window.clear({20, 20, 20});
        angle += 0.01;
        sortedShipMesh.clearMesh();
        clippedTrianglesMesh.clearMesh();
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

            Matrix4x4 cameraRotationMatrix{cameraRight, cameraUp, cameraForward, Vec4{0, 0, 0, 1}};
            Triangle cameraViewTriangle = cameraRotationMatrix.transformTriangle(viewedTriangle);

            normal = cameraViewTriangle.getNormal();
            Vec4 cameraToPlaneVec = cameraViewTriangle.getP1();

            if (normal.dot(cameraToPlaneVec) >= 0.0f)
            {
                continue;
            }

            if (cameraViewTriangle.isBehindNearPlane(fNear))
            {

                std::vector<Vec4> inside;
                std::vector<Vec4> outside;

                for (Vec4 vec : cameraViewTriangle.getPoints())
                {

                    if (vec.getZ() >= fNear)
                    {
                        inside.push_back(vec);
                    }
                    else
                    {
                        outside.push_back(vec);
                    }
                }

                if (inside.size() == 1)
                {

                    Vec4 A = inside[0];

                    Vec4 B = outside[0];
                    Vec4 C = outside[1];

                    Vec4 directionAB = B.subtract(A);
                    Vec4 directionAC = C.subtract(A);

                    float tAB =
                        (fNear - A.getZ()) /
                        directionAB.getZ();

                    float tAC =
                        (fNear - A.getZ()) /
                        directionAC.getZ();

                    Vec4 intersectionAB = Vec4{A.getX() + (directionAB.getX()) * tAB,
                                               A.getY() + (directionAB.getY()) * tAB,
                                               A.getZ() + (directionAB.getZ()) * tAB,
                                               1};

                    Vec4 intersectionAC = Vec4{A.getX() + (directionAC.getX()) * tAC,
                                               A.getY() + (directionAC.getY()) * tAC,
                                               A.getZ() + (directionAC.getZ()) * tAC,
                                               1};

                    Triangle newTriangle = Triangle(A, intersectionAB, intersectionAC);
                    clippedTrianglesMesh.addTriangle(newTriangle);
                }
                else if (inside.size() == 2)
                {
                    Vec4 A = inside[0];
                    Vec4 B = inside[1];

                    Vec4 C = outside[0];

                    Vec4 directionAC = C.subtract(A);
                    Vec4 directionBC = C.subtract(B);

                    float tAC =
                        (fNear - A.getZ()) /
                        directionAC.getZ();

                    float tBC =
                        (fNear - B.getZ()) /
                        directionBC.getZ();

                    Vec4 intersectionAC = Vec4{A.getX() + (directionAC.getX()) * tAC,
                                               A.getY() + (directionAC.getY()) * tAC,
                                               A.getZ() + (directionAC.getZ()) * tAC,
                                               1};

                    Vec4 intersectionBC = Vec4{B.getX() + (directionBC.getX()) * tBC,
                                               B.getY() + (directionBC.getY()) * tBC,
                                               B.getZ() + (directionBC.getZ()) * tBC,
                                               1};

                    Triangle newTriangleLeft = Triangle(A, intersectionBC, intersectionAC);
                    Triangle newTriangleRight = Triangle(A, B, intersectionBC);
                    clippedTrianglesMesh.addTriangle(newTriangleLeft);
                    clippedTrianglesMesh.addTriangle(newTriangleRight);
                }
                else
                {
                    continue;
                }
            }
            else
            {

                clippedTrianglesMesh.addTriangle(cameraViewTriangle);
            }
        }

        for (Triangle &t : clippedTrianglesMesh.getMesh()) {

            Triangle projectedTriangle = projectionMat.transformTriangle(t);

            Vec4 p1 = projectedTriangle.getP1().perspectiveDivide().shift(1.0f, 1.0f, 0, 0).scale(0.5f * width, 0.5f * height, 1, 1);
            Vec4 p2 = projectedTriangle.getP2().perspectiveDivide().shift(1.0f, 1.0f, 0, 0).scale(0.5f * width, 0.5f * height, 1, 1);
            Vec4 p3 = projectedTriangle.getP3().perspectiveDivide().shift(1.0f, 1.0f, 0, 0).scale(0.5f * width, 0.5f * height, 1, 1);

            Triangle drawnTriangle{p1, p2, p3};
            Color triangleColor = Color::getColor(std::clamp(normal.dot(lightVec), 0.0f, 1.0f));

            drawnTriangle.setColor(Color(255,255,255)); // TODO

            sortedShipMesh.addTriangle(drawnTriangle);
        }

        sortedShipMesh.sortMesh();

        for (Triangle &drawnTriangle : sortedShipMesh.getMesh())
        {

            window.drawFilledTriangle(drawnTriangle, drawnTriangle.getColor());
            window.drawTriangle(drawnTriangle, {0, 0, 0});
        }

        window.present();
    }

    return 0;
}
