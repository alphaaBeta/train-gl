#pragma once

#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Vertex.h"
#include "ShaderProgram.h"
#include "Model.h"
enum
{
	kolko
	walce
	stozke
};
class Primitive : public Model{
  private:
    std::vector<Vertex> _vertices;
    std::vector<GLuint> _indices;

    GLuint _vao;
    GLuint _vbo;
    GLuint _ebo;

    glm::vec3 _pos;
    glm::vec3 _origin;
    glm::vec3 _rotation;
    glm::vec3 _scale;

    glm::mat4 _ModelMatrix;

    void initVAO();
  public:
    Primitive(std::vector<Vertex> &vertices,
         const std::vector<GLuint> &indices,
         glm::vec3 position = glm::vec3(0.f),
         glm::vec3 origin = glm::vec3(0.f),
         glm::vec3 rotation = glm::vec3(0.f),
         glm::vec3 scale = glm::vec3(1.f));

    ~Primitive();
    void draw() override;

    void setPos(const glm::vec3 pos);
    void move(const glm::vec3 pos);

    void setOrigin(const glm::vec3 origin);

    void setRotation(const glm::vec3 rotation);
    void rotate(const glm::vec3 rotation);

    void setScale(const glm::vec3 scale);
    void scale(const glm::vec3 scale);
};

