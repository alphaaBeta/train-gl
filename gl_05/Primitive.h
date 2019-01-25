#pragma once

#include <vector>
#define GLEW_STATIC
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Vertex.h"
#include "ShaderProgram.h"
#include "Model.h"

class Primitive : public Model {
  private:
    GLuint _vao;
    GLuint _vbo;
    GLuint _ebo;

  public:
    std::vector<Vertex> _vertices;
    std::vector<GLuint> _indices;

    Primitive(std::vector<Vertex> &vertices,
              const std::vector<GLuint> &indices);
    Primitive();
    ~Primitive();

    void draw();

    void initVAO();
};

