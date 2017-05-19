#include "Cube.h"

Cube::Cube()
{
    // front
    Vertex v0 = { -1.0, -1.0, 1.0 };
    Vertex v1 = { 1.0, -1.0, 1.0 };
    Vertex v2 = { 1.0, 1.0, 1.0 };
    Vertex v3 = { -1.0, 1.0, 1.0 };

    // back
    Vertex v4 = { -1.0, -1.0, -1.0 };
    Vertex v5 = { 1.0, -1.0, -1.0 };
    Vertex v6 = { 1.0, 1.0, -1.0 };
    Vertex v7 = { -1.0, 1.0, -1.0 };

    _vertices = { v0,v1,v2,v3,v4,v5,v6,v7 };

    _indices = {
        // front
        0, 1, 2,
        2, 3, 0,
        // top
        1, 5, 6,
        6, 2, 1,
        // back
        7, 6, 5,
        5, 4, 7,
        // bottom
        4, 0, 3,
        3, 7, 4,
        // left
        4, 5, 1,
        1, 0, 4,
        // right
        3, 2, 6,
        6, 7, 3,
    };

    setup();
}
