#pragma once

#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Vertex.h"
#include "ShaderProgram.h"
#include "Model.h"

class Primitive : public Model{
  private:
    std::vector<Vertex> _vertices;
    std::vector<GLuint> _indices;

    GLuint _vao;
    GLuint _vbo;
    GLuint _ebo;

    void initVAO();
  public:
    Primitive(std::vector<Vertex> &vertices,
         const std::vector<GLuint> &indices);
	Primitive();
    ~Primitive();

    void draw();
};

