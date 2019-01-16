#include "Procedurals.h"

#define PI 3.14159265

Procedurals::Procedurals()
{
}

Procedurals::~Procedurals()
{
}

std::vector<Vertex> Procedurals::drawCuboidVertices(float positionX, float positionY, float positionZ, float width, float height, float length) {
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

std::vector<Vertex> Procedurals::drawRectangleVertices(float positionX, float positionY, float positionZ, float width, float length) {
	std::vector<Vertex> rectangleVertices = {
		{glm::vec3(positionX, positionY, positionZ),							glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 1.f, 0.f)},
		{glm::vec3(positionX, positionY, positionZ + length),					glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 1.f, 0.f)},
		{glm::vec3(positionX + width, positionY, positionZ),					glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 1.f, 0.f)},
		{glm::vec3(positionX + width, positionY, positionZ + length),			glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 1.f, 0.f)}
	};

	return rectangleVertices;
}

std::vector<GLuint> Procedurals::drawRectangleIndices(GLuint startingIndex) {
	std::vector<GLuint> rectangleIndices = {
		startingIndex, startingIndex + 1, startingIndex + 2,
		startingIndex + 1, startingIndex + 2, startingIndex + 3,
	};

	return rectangleIndices;
}

std::vector<Vertex> Procedurals::drawCylinderVertices(float positionX, float positionY, float positionZ, float height, float radius, unsigned int accuracy) {
	std::vector<Vertex> cylinderVertices = {
		{glm::vec3(positionX, positionY, positionZ),							glm::vec3(1.f, 0.f, 0.f),			glm::vec3(-1.f, 0.f, 0.f)}
	};

	for (float degree = 0; degree < 360; degree += 360.f/accuracy) {
		cylinderVertices.push_back({glm::vec3(positionX, positionY + radius * sin(degree * PI/180.f), positionZ + radius * cos(degree * PI / 180.f)), glm::vec3(1.f, 0.f, 0.f), glm::vec3(-1.f, 0.f, 0.f)});
	};

	cylinderVertices.push_back({glm::vec3(positionX + height, positionY, positionZ),			glm::vec3(1.f, 0.f, 0.f),			glm::vec3(-1.f, 0.f, 0.f)});

	for (float degree = 0; degree < 360; degree += 360.f/accuracy) {
		cylinderVertices.push_back({glm::vec3(positionX + height, positionY + radius * sin(degree * PI / 180.f), positionZ  + radius * cos(degree * PI / 180.f)), glm::vec3(1.f, 0.f, 0.f), glm::vec3(-1.f, 0.f, 0.f) });
	};

	return cylinderVertices;
}

std::vector<GLuint> Procedurals::drawCylinderIndices(GLuint startingIndex, unsigned int accuracy) {
	std::vector<GLuint> cylinderIndices = {};

	for (unsigned int i = 1; i < accuracy; ++i) {
		cylinderIndices.push_back(0);
		cylinderIndices.push_back(i);
		cylinderIndices.push_back(i+1);
	}

	cylinderIndices.push_back(0);
	cylinderIndices.push_back(accuracy);
	cylinderIndices.push_back(1);

	for (unsigned int i = accuracy + 1; i < 2 * accuracy; ++i) {
		cylinderIndices.push_back(accuracy + 2);
		cylinderIndices.push_back(i);
		cylinderIndices.push_back(i+1);
	}

	for (unsigned int i = 1; i < accuracy; ++i) {
		cylinderIndices.push_back(i);
		cylinderIndices.push_back(i + 1);
		cylinderIndices.push_back(accuracy + 1 + i);

		cylinderIndices.push_back(i + 1);
		cylinderIndices.push_back(accuracy + 1 + i);
		cylinderIndices.push_back(accuracy + 2 + i);
	}

	return cylinderIndices;
}
