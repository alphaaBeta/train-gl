#pragma once
#include <glm/detail/type_vec3.hpp>
#include <glm/mat4x2.hpp>
#include <glm/detail/type_mat4x4.hpp>

class ShaderProgram;

class Model
{
public:
	glm::vec3 _pos;
	glm::vec3 _origin;
	glm::vec3 _rotation;
	glm::vec3 _scale;

	glm::mat4 _ModelMatrix;

	virtual void draw() {};


	void render();
	void updateModelMatrix();

	void setPos(const glm::vec3 pos);
	void move(const glm::vec3 pos);

	void setOrigin(const glm::vec3 origin);

	void setRotation(const glm::vec3 rotation);
	void rotate(const glm::vec3 rotation);

	void setScale(const glm::vec3 scale);
	void scale(const glm::vec3 scale);

};

