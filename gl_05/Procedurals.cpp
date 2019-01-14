#include "Procedurals.h"

Procedurals::Procedurals()
{
}

Procedurals::~Procedurals()
{
}

std::vector<Vertex> Procedurals::drawCuboidVertices(float positionX, float positionY, float positionZ, float width, float height, float length)
{
	std::vector<Vertex> cuboidVertices = {
		{glm::vec3(positionX, positionY + height, positionZ),					glm::vec3(1.f, 0.f, 0.f)},
		{glm::vec3(positionX, positionY + height, positionZ + length),			glm::vec3(1.f, 0.f, 0.f)},
		{glm::vec3(positionX + width, positionY + height, positionZ),			glm::vec3(1.f, 0.f, 0.f)},
		{glm::vec3(positionX + width, positionY + height, positionZ + length),	glm::vec3(1.f, 0.f, 0.f)},
		{glm::vec3(positionX, positionY, positionZ),							glm::vec3(1.f, 0.f, 0.f)},
		{glm::vec3(positionX, positionY, positionZ + length),					glm::vec3(1.f, 0.f, 0.f)},
		{glm::vec3(positionX + width, positionY, positionZ),					glm::vec3(1.f, 0.f, 0.f)},
		{glm::vec3(positionX + width, positionY, positionZ + length),			glm::vec3(1.f, 0.f, 0.f)}
	};

	return cuboidVertices;
}

std::vector<GLuint> Procedurals::drawCuboidIndices(GLuint startingIndex) {
	std::vector<GLuint> cuboidIndices = {
		startingIndex, startingIndex + 1, startingIndex + 3,
		startingIndex, startingIndex + 2, startingIndex + 3,
		startingIndex, startingIndex + 4, startingIndex + 6,
		startingIndex, startingIndex + 2, startingIndex + 6,
		startingIndex, startingIndex + 1, startingIndex + 4,
		startingIndex + 1, startingIndex + 4, startingIndex + 5,
		startingIndex + 1, startingIndex + 5, startingIndex + 7,
		startingIndex + 1, startingIndex + 3, startingIndex + 7,
		startingIndex + 2, startingIndex + 3, startingIndex + 6,
		startingIndex + 3, startingIndex + 6, startingIndex + 7,
		startingIndex + 4, startingIndex + 6, startingIndex + 7,
		startingIndex + 4, startingIndex + 5, startingIndex + 7 
	};

	return cuboidIndices;
}

std::vector<Vertex> Procedurals::drawRectangleVertices(float positionX, float positionY, float positionZ, float width, float length)
{
	std::vector<Vertex> rectangleVertices = {
		{glm::vec3(positionX, positionY, positionZ),							glm::vec3(1.f, 0.f, 0.f)},
		{glm::vec3(positionX, positionY, positionZ + length),					glm::vec3(1.f, 0.f, 0.f)},
		{glm::vec3(positionX + width, positionY, positionZ),					glm::vec3(1.f, 0.f, 0.f)},
		{glm::vec3(positionX + width, positionY, positionZ + length),			glm::vec3(1.f, 0.f, 0.f)}
	};

	return rectangleVertices;
}

std::vector<GLuint> Procedurals::drawRectangleIndices(GLuint startingIndex)
{
	std::vector<GLuint> rectangleIndices = {
		startingIndex, startingIndex + 1, startingIndex + 2,
		startingIndex + 1, startingIndex + 2, startingIndex + 3,
	};

	return rectangleIndices;
}
