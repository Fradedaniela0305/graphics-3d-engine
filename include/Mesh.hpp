#pragma once
#include <vector>
#include "Triangle.hpp"

/**
 * Represents a mesh
 */
class Mesh
{

public:
    /**
     * Constructor to create a mesh
     */
    Mesh(std::vector<Triangle> mesh);

    /**
     * Constructor to create a mesh
     */
    Mesh();

    /**
     * Add a triangle to the mesh
     */
    void addTriangle(Triangle triangle);

    /**
     * Getter for mesh
     */
    std::vector<Triangle> getMesh();


private:
    std::vector<Triangle> mesh;
};
