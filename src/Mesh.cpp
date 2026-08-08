#include "Mesh.hpp"

/**
 * Constructor to create a mesh
 */
Mesh::Mesh(std::vector<Triangle> mesh) : mesh(mesh)
{
}

/**
 * Constructor to create a mesh
 */
Mesh::Mesh()
{
}

/**
 * Add a triangle to the mesh
 */
void Mesh::addTriangle(Triangle triangle)
{
    mesh.push_back(triangle);
}

/**
 * Getter for mesh
 */
std::vector<Triangle> Mesh::getMesh()
{
    return mesh;
}
