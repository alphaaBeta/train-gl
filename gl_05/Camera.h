#pragma once
#include <glm/detail/type_mat4x4.hpp>
#include <GL/glew.h>
#include "ShaderProgram.h"
#include <glm/detail/type_vec3.hpp>


class Camera
{
public:
	Camera(ShaderProgram &shaderProgram, glm::vec3 location, const float fov = 45.0f, const float aspectRatio =	4.0f/3.0f, const float displayMin = 0.1f, const float displayMax = 100.0f);
	GLuint MatrixID;
	glm::mat4 MVPMatrix;
private:
	void SetCameraView(glm::vec3 location, glm::vec3 target = glm::vec3(0.0, 0.0, 0.0), bool upsideDown = false);
	glm::mat4 _projection;
	glm::mat4 _view;
	//Dependencies
	ShaderProgram* _shaderProgram;
};

