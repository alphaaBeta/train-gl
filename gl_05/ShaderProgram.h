#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class ShaderProgram
{
	GLuint program_id; 	// The program ID
public:
	// Constructor reads and builds the shader
	ShaderProgram(const GLchar* vertexPath, const GLchar* fragmentPath);

	static const ShaderProgram* usedProgram;

	// Use the program
	void Use() const
	{
		usedProgram = this;
		glUseProgram(get_programID());
	}

	void unuse() const
	{
		glUseProgram(0);
	}


	// returns program ID
	GLuint get_programID() const
	{
		return program_id;
	}

	void set1i(GLint value, const GLchar* name) const
	{
		this->Use();

		glUniform1i(glGetUniformLocation(this->get_programID(), name), value);

		this->unuse();
	}

	void set1f(GLfloat value, const GLchar* name) const
	{
		this->Use();

		glUniform1f(glGetUniformLocation(this->get_programID(), name), value);

		this->unuse();
	}

	void setVec2f(glm::fvec2 value, const GLchar* name) const
	{
		this->Use();

		glUniform2fv(glGetUniformLocation(this->get_programID(), name), 1, glm::value_ptr(value));

		this->unuse();
	}

	void setVec3f(glm::fvec3 value, const GLchar* name) const
	{
		this->Use();

		glUniform3fv(glGetUniformLocation(this->get_programID(), name), 1, glm::value_ptr(value));

		this->unuse();
	}

	void setVec4f(glm::fvec4 value, const GLchar* name) const
	{
		this->Use();

		glUniform4fv(glGetUniformLocation(this->get_programID(), name), 1, glm::value_ptr(value));

		this->unuse();
	}

	void setMat3fv(glm::mat3 value, const GLchar* name, GLboolean transpose = GL_FALSE) const
	{
		this->Use();

		glUniformMatrix3fv(glGetUniformLocation(this->get_programID(), name), 1, transpose, glm::value_ptr(value));

		this->unuse();
	}

	void setMat4fv(glm::mat4 value, const GLchar* name, GLboolean transpose = GL_FALSE) const
	{
		this->Use();

		glUniformMatrix4fv(glGetUniformLocation(this->get_programID(), name), 1, transpose, glm::value_ptr(value));

		this->unuse();
	}
};