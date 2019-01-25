#pragma once
#include <vector>

#include "Vertex.h"
#define GLEW_STATIC
#include <GL/glew.h>

class Procedurals {
  public:
    Procedurals();
    ~Procedurals();

    static std::vector<Vertex> drawCuboidVertices(float positionX, float positionY, float positionZ, float width, float height, float length);
    static std::vector<GLuint> drawCuboidIndices(GLuint startingIndex);
    static std::vector<Vertex> drawRectangleVertices(float positionX, float positionY, float positionZ, float width, float length);
    static std::vector<GLuint> drawRectangleIndices(GLuint startingIndex);
    static std::vector<Vertex> drawCylinderVertices(float positionX, float positionY, float positionZ, float height, float radius, float baseRatio, unsigned int accuracy);
    static std::vector<GLuint> drawCylinderIndices(GLuint startingIndex, unsigned int accuracy);
	static std::vector<Vertex> drawSlouchedCuboidVertices(float positionX, float positionY, float positionZ, float width, float height, float length);
	static std::vector<Vertex> drawTriangularPrismVertices(float positionX, float positionY, float positionZ, float width, float height, float length);
	static std::vector<GLuint> drawTriangularPrismIndices(GLuint startingIndex);
	static std::vector<Vertex> drawTriangleBasedPyramidVertices(float positionX, float positionY, float positionZ, float width, float height, float length);
	static std::vector<GLuint> drawTriangleBasedPyramidIndices(GLuint startingIndex);
	static std::vector<Vertex> drawBaselessCylinderVertices(float positionX, float positionY, float positionZ, float height, float radius, float baseRatio, unsigned int accuracy);
	static std::vector<GLuint> drawBaselessCylinderIndices(GLuint startingIndex, unsigned int accuracy);

};


