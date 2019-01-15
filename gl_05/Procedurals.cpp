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
		{glm::vec3(positionX, positionY + height, positionZ),					glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 1.f, 0.f)},//xz
		{glm::vec3(positionX, positionY + height, positionZ),					glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, -1.f)},//xy
		{glm::vec3(positionX, positionY + height, positionZ),					glm::vec3(1.f, 0.f, 0.f),			glm::vec3(-1.f, 0.f, 0.f)},//yz
		{glm::vec3(positionX, positionY + height, positionZ + length),			glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 1.f, 0.f)},//xz
		{glm::vec3(positionX, positionY + height, positionZ + length),			glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, 1.f)},//xy
		{glm::vec3(positionX, positionY + height, positionZ + length),			glm::vec3(1.f, 0.f, 0.f),			glm::vec3(-1.f, 0.f, 0.f)},//yz
		{glm::vec3(positionX + width, positionY + height, positionZ),			glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 1.f, 0.f)},//xz
		{glm::vec3(positionX + width, positionY + height, positionZ),			glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, -1.f)},//xy
		{glm::vec3(positionX + width, positionY + height, positionZ),			glm::vec3(1.f, 0.f, 0.f),			glm::vec3(1.f, 0.f, 0.f)},//yz
		{glm::vec3(positionX + width, positionY + height, positionZ + length),	glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 1.f, 0.f)},//xz
		{glm::vec3(positionX + width, positionY + height, positionZ + length),	glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, 1.f)},//xy
		{glm::vec3(positionX + width, positionY + height, positionZ + length),	glm::vec3(1.f, 0.f, 0.f),			glm::vec3(1.f, 0.f, 0.f)},//yz
		{glm::vec3(positionX, positionY, positionZ),							glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, -1.f, 0.f)},//xz
		{glm::vec3(positionX, positionY, positionZ),							glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, -1.f)},//xy
		{glm::vec3(positionX, positionY, positionZ),							glm::vec3(1.f, 0.f, 0.f),			glm::vec3(-1.f, 0.f, 0.f)},//yz
		{glm::vec3(positionX, positionY, positionZ + length),					glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, -1.f, 0.f)},//xz
		{glm::vec3(positionX, positionY, positionZ + length),					glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, 1.f)},//xy
		{glm::vec3(positionX, positionY, positionZ + length),					glm::vec3(1.f, 0.f, 0.f),			glm::vec3(-1.f, 0.f, 0.f)},//yz
		{glm::vec3(positionX + width, positionY, positionZ),					glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, -1.f, 0.f)},//xz
		{glm::vec3(positionX + width, positionY, positionZ),					glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, -1.f)},//xy
		{glm::vec3(positionX + width, positionY, positionZ),					glm::vec3(1.f, 0.f, 0.f),			glm::vec3(1.f, 0.f, 0.f)},//yz
		{glm::vec3(positionX + width, positionY, positionZ + length),			glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, -1.f, 0.f)},//xz
		{glm::vec3(positionX + width, positionY, positionZ + length),			glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, 1.f)},//xy
		{glm::vec3(positionX + width, positionY, positionZ + length),			glm::vec3(1.f, 0.f, 0.f),			glm::vec3(1.f, 0.f, 0.f)},//yz
	};

	return cuboidVertices;
}

std::vector<GLuint> Procedurals::drawCuboidIndices(GLuint startingIndex) {
	std::vector<GLuint> cuboidIndices = {
		startingIndex, startingIndex + 3, startingIndex + 9,//xz
		startingIndex, startingIndex + 6, startingIndex + 9,//xz
		startingIndex + 1, startingIndex + 7, startingIndex + 19,//xy
		startingIndex + 1, startingIndex + 13, startingIndex + 19,//xy
		startingIndex + 2, startingIndex + 5, startingIndex + 17,//yz
		startingIndex + 2, startingIndex + 14, startingIndex + 17,//yz
		startingIndex + 12, startingIndex + 16, startingIndex + 21,//xz
		startingIndex + 12, startingIndex + 18, startingIndex + 21,//xz
		startingIndex + 4, startingIndex + 10, startingIndex + 22,//xy
		startingIndex + 4, startingIndex + 16, startingIndex + 22,//xy
		startingIndex + 8, startingIndex + 11, startingIndex + 23,//yz
		startingIndex + 8, startingIndex + 20, startingIndex + 23//yz
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
