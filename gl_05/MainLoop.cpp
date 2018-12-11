#include "MainLoop.h"
#include <GLFW/glfw3.h>
#include <exception>
#include <GL/glew.h>


MainLoop::MainLoop(GLFWwindow *window, ShaderProgram *shaderProgram, Camera *camera)
{
	//Init
	_vao = 0;
	_vbo = 0;
	_window = window;
	_shaderProgram = shaderProgram;
	_camera = camera;

	glGenVertexArrays(1, &_vao);

	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(_vao);


	GLfloat floor[] = {
		-1.0, 0.0, -1.0,
		1.0, 0.0, -1.0,
		-1.0, 0.0, 1.0,
		1.0, 0.0, -1.0,
		-1.0, 0.0, 1.0,
		1.0, 0.0, 1.0
	};
	
	glGenBuffers(1, &_vbo);

	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(floor), floor, GL_STATIC_DRAW);
	// Build, compile and link shader program
	//_shaderProgram;
	
}


MainLoop::~MainLoop()
{
	glDeleteVertexArrays(1, &_vao);
	glDeleteBuffers(1, &_vbo);
}

void MainLoop::PerformMainLoop()
{
	CheckEvents();

	CleanScreen();

	_shaderProgram->Use();


	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		false,
		0,
		(void*)0
	);


	// Send our transformation to the currently bound shader, in the "MVP" uniform
	// This is done in the main loop since each model will have a different MVP matrix (At least for the M part)
	glUniformMatrix4fv(_camera->MatrixID, 1, GL_FALSE, &(_camera->MVPMatrix[0][0]));

	glDrawArrays(GL_TRIANGLES, 0, 2 * 3); //2 triangles of 3 vertices
	glDisableVertexAttribArray(0);

	glfwSwapBuffers(_window);
}


int MainLoop::CheckEvents()
{
	try
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
	}
	catch (std::exception ex)
	{
		return 1;
	}
	return 0;
}

int MainLoop::CleanScreen()
{
	try {
		// Clear the colorbuffer
		glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	catch (std::exception ex)
	{
		return 1;
	}
	return 0;
}