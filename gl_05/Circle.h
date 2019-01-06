#pragma once
#include "Primitive.h"
class Circle :
	public Primitive
{
public:
	Circle(glm::vec3 coords, GLfloat radious, GLuint noOfSides);

	void draw() override;
};

