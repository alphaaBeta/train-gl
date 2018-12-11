#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include "ShaderProgram.h"
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include <iostream>
#include "Camera.h"
using namespace std;

class MainLoop
{
public:

	void PerformMainLoop();	
	ShaderProgram* _shaderProgram;

	MainLoop(GLFWwindow *window, ShaderProgram *shaderProgram, Camera *camera);

	~MainLoop();
private:
	int CleanScreen();
	int CheckEvents();
	static MainLoop* _instance;
	GLuint _vao;
	GLuint _vbo;
	Camera* _camera;
	GLFWwindow* _window;
};

