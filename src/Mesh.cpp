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

/**
 * Loader for .obj files
 */
bool Mesh::loadFromObjectFile(std::string path)
{
    std::ifstream file(path);

    if (!file.is_open())
    {
        return false;
    }

    std::string line;

    std::vector<Vec4> vertex;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "v")
        {
            float x, y, z;
            ss >> x >> y >> z;
            vertex.push_back(Vec4{x, y, z, 1});
        }

        else if (type == "f")
        {
            int v1, v2, v3;
            ss >> v1 >> v2 >> v3;

            mesh.push_back(Triangle{vertex.at(v1 - 1), vertex.at(v2 - 1), vertex.at(v3 - 1)});
        }
    }

    return true;
}

/**
 * Sorts mesh based on triangle's zth-component. From largest to smallest.
 */
void Mesh::sortMesh()
{
    std::sort(mesh.begin(), mesh.end(), [](Triangle &a, Triangle &b)
              { return a.zthMidPoint() > b.zthMidPoint(); });
}

/**
 * Removes all triangles from the mesh
 */
void Mesh::clearMesh()
{
    mesh.clear();
}
