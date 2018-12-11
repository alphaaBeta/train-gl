#include "Camera.h"
#include <glm/gtc/matrix_transform.inl>
#include <GL/glew.h>
#include "MainLoop.h"
#include <glm/detail/type_mat.hpp>


Camera::Camera(ShaderProgram &shader_program, glm::vec3 location, const float fov, const float aspectRatio, const float displayMin, const float displayMax)
{	
	//Dependency injection
	_shaderProgram = &shader_program;

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	_projection = glm::perspective(glm::radians(fov), aspectRatio, displayMin, displayMax);

	// Or, for an ortho camera :
	//_projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates

	SetCameraView(location);

	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 Model = glm::mat4();

	// Our ModelViewProjection : multiplication of our 3 matrices
	MVPMatrix = _projection * _view * Model;

	// Get a handle for our "MVP" uniform
	MatrixID = glGetUniformLocation(_shaderProgram->get_programID(), "MVP");
}

void Camera::SetCameraView(glm::vec3 location, glm::vec3 target, bool upsideDown)
{
	//Camera matrix
	_view = glm::lookAt(
		location, // Camera is at (x,y,z), in World Space
		target, // and looks at the origin
		glm::vec3(0, upsideDown ? -1 : 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
}
