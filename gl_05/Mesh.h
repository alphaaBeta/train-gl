#pragma once

#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Vertex.h"
#include "ShaderProgram.h"

class Mesh
{
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
	void updateModelMatrix();
public:
	Mesh(std::vector<Vertex> &vertices,
		std::vector<GLuint> &indices,
		glm::vec3 position = glm::vec3(0.f),
		glm::vec3 origin = glm::vec3(0.f),
		glm::vec3 rotation = glm::vec3(0.f),
		glm::vec3 scale = glm::vec3(1.f));
	~Mesh();
	void render(ShaderProgram *shader);
	void setPos(const glm::vec3 position);
	void setOrigin(const glm::vec3 origin);
	void setRotation(const glm::vec3 rotation);
	void setScale(const glm::vec3 scale);
};

