#pragma once

#include <iostream>
#include <vector>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp>

#include "ShaderProgram.h"
#include "Texture.h"
#include "Camera.h"
#include "Mesh.h"

class Game {
private:
	// Window related
	GLFWwindow *_window;
	const int W_WIDTH;
	const int W_HEIGHT;
	int _frameBuffWidth;
	int _frameBuffHeight;

	// OpenGL version
	// ...

	// Game loop related


	// Mouse input
	// ...
	double _lastMouseX;
	double _lastMouseY;
	double _mouseX;
	double _mouseY;
	double _mouseOffsetX;
	double _mouseOffsetY;
	bool _firstMouse;
	// Camera
	Camera _camera;

	// Matrixes
	glm::mat4 _ViewMatrix;
	glm::vec3 _camPos;
	glm::vec3 _worldUp;
	glm::vec3 _camFront;

	glm::mat4 _ProjMatrix;
	float _fov;
	float _nearPlane;
	float _farPlane;

	// Shaders
	ShaderProgram *_shader;

	// Textures

	// Materials

	// Models
	Mesh *_mesh;
	// Lights

	// Private functions
	void initGLFW();
	void initWindow(const char *title, bool resizable);
	void initGLEW(); // use after context is created
	void initOpenGLOptions();
	void initMatrices();
	void initShaders();
	void initTextures();
	//void initMaterials();
	//void initModels();
	//void initLights();
	void initUniforms();

public:
	Game(const char *title, const int width, const int height, bool resizable);
	~Game();
	void updateKeyInput(const float &dt);
	void updateMouseInput();
	int getWindowShouldClose();
	void update(const float &dt);
	void render();
	void updateUniforms();
};

