#include "Procedurals.h"

#define PI 3.14159265359

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
		{glm::vec3(positionX, positionY, positionZ),							glm::vec3(0.21f, 0.43f, 0.36f),			glm::vec3(0.f, 1.f, 0.f)},
		{glm::vec3(positionX, positionY, positionZ + length),					glm::vec3(0.21f, 0.43f, 0.36f),			glm::vec3(0.f, 1.f, 0.f)},
		{glm::vec3(positionX + width, positionY, positionZ),					glm::vec3(0.21f, 0.43f, 0.36f),			glm::vec3(0.f, 1.f, 0.f)},
		{glm::vec3(positionX + width, positionY, positionZ + length),			glm::vec3(0.21f, 0.43f, 0.36f),			glm::vec3(0.f, 1.f, 0.f)}
	};

	return rectangleVertices;
}

std::vector<GLuint> Procedurals::drawRectangleIndices(GLuint startingIndex) {
	std::vector<GLuint> rectangleIndices = {
		startingIndex, startingIndex + 1, startingIndex + 2,
		startingIndex + 1, startingIndex + 2, startingIndex + 3
	};

	return rectangleIndices;
}

std::vector<Vertex> Procedurals::drawCylinderVertices(float positionX, float positionY, float positionZ, float height, float radius, float baseRatio, unsigned int accuracy) {
	float sinAlpha = radius*(1 - baseRatio) / (sqrt(pow(height,2) + pow((radius * (1 - baseRatio)),2)));
	float cosAlpha = height / (sqrt(pow(height, 2) + pow((radius * (1 - baseRatio)), 2)));

	std::vector<Vertex> cylinderVertices = {
		{glm::vec3(positionX, positionY, positionZ),																																		glm::vec3(1.f, 0.f, 0.f),		glm::vec3(-1.f, 0.f, 0.f)}
	};

	for (float degree = 0; degree < 360; degree += 360.f/accuracy) {
		cylinderVertices.push_back({glm::vec3(positionX, positionY + radius * sin(degree * PI/180.f), positionZ + radius * cos(degree * PI/180.f)),											glm::vec3(1.f, 0.f, 0.f),		glm::vec3(cosAlpha, sin(degree * PI / 180.f) * sinAlpha, cos(degree * PI / 180.f) * sinAlpha)});
	};

	cylinderVertices.push_back({glm::vec3(positionX + height, positionY, positionZ),																										glm::vec3(1.f, 0.f, 0.f),		glm::vec3(1.f, 0.f, 0.f)});

	for (float degree = 0; degree < 360; degree += 360.f/accuracy) {
		cylinderVertices.push_back({glm::vec3(positionX + height, positionY + (radius*baseRatio) * sin(degree * PI / 180.f), positionZ  + (radius*baseRatio) * cos(degree * PI / 180.f)),	glm::vec3(1.f, 0.f, 0.f),		glm::vec3(cosAlpha, sin(degree * PI / 180.f) * sinAlpha, cos(degree * PI / 180.f) * sinAlpha)});
	};

	return cylinderVertices;
}

std::vector<Vertex> Procedurals::drawSpotlightVertices(float positionX, float positionY, float positionZ, float height, float radius, float baseRatio, unsigned int accuracy) {
	float sinAlpha = radius * (1 - baseRatio) / (sqrt(pow(height, 2) + pow((radius * (1 - baseRatio)), 2)));
	float cosAlpha = height / (sqrt(pow(height, 2) + pow((radius * (1 - baseRatio)), 2)));

	std::vector<Vertex> cylinderVertices = {
		{glm::vec3(positionX, positionY, positionZ),																																		glm::vec3(1.f, 1.f, 0.f),		glm::vec3(-1.f, 0.f, 0.f)}
	};

	for (float degree = 0; degree < 360; degree += 360.f / accuracy) {
		cylinderVertices.push_back({ glm::vec3(positionX, positionY + radius * sin(degree * PI / 180.f), positionZ + radius * cos(degree * PI / 180.f)),											glm::vec3(1.f, 1.f, 0.f),		glm::vec3(cosAlpha, sin(degree * PI / 180.f) * sinAlpha, cos(degree * PI / 180.f) * sinAlpha) });
	};

	cylinderVertices.push_back({ glm::vec3(positionX + height, positionY, positionZ),																										glm::vec3(1.f, 1.f, 0.f),		glm::vec3(1.f, 0.f, 0.f) });

	for (float degree = 0; degree < 360; degree += 360.f / accuracy) {
		cylinderVertices.push_back({ glm::vec3(positionX + height, positionY + (radius*baseRatio) * sin(degree * PI / 180.f), positionZ + (radius*baseRatio) * cos(degree * PI / 180.f)),	glm::vec3(1.f, 1.f, 0.f),		glm::vec3(cosAlpha, sin(degree * PI / 180.f) * sinAlpha, cos(degree * PI / 180.f) * sinAlpha) });
	};

	return cylinderVertices;
}


std::vector<Vertex> Procedurals::drawSpotlightBorderVertices(float positionX, float positionY, float positionZ, float height, float radius, float baseRatio, unsigned int accuracy) {
	float sinAlpha = radius * (1 - baseRatio) / (sqrt(pow(height, 2) + pow((radius * (1 - baseRatio)), 2)));
	float cosAlpha = height / (sqrt(pow(height, 2) + pow((radius * (1 - baseRatio)), 2)));

	std::vector<Vertex> cylinderVertices = {
		{glm::vec3(positionX, positionY, positionZ),																																		glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec3(-1.f, 0.f, 0.f)}
	};

	for (float degree = 0; degree < 360; degree += 360.f / accuracy) {
		cylinderVertices.push_back({ glm::vec3(positionX, positionY + radius * sin(degree * PI / 180.f), positionZ + radius * cos(degree * PI / 180.f)),											glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec3(cosAlpha, sin(degree * PI / 180.f) * sinAlpha, cos(degree * PI / 180.f) * sinAlpha) });
	};

	cylinderVertices.push_back({ glm::vec3(positionX + height, positionY, positionZ),																										glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec3(1.f, 0.f, 0.f) });

	for (float degree = 0; degree < 360; degree += 360.f / accuracy) {
		cylinderVertices.push_back({ glm::vec3(positionX + height, positionY + (radius*baseRatio) * sin(degree * PI / 180.f), positionZ + (radius*baseRatio) * cos(degree * PI / 180.f)),	glm::vec3(0.5f, 0.5f, 0.5f),		glm::vec3(cosAlpha, sin(degree * PI / 180.f) * sinAlpha, cos(degree * PI / 180.f) * sinAlpha) });
	};

	return cylinderVertices;
}

std::vector<GLuint> Procedurals::drawCylinderIndices(GLuint startingIndex, unsigned int accuracy) {
	std::vector<GLuint> cylinderIndices = {};

	for (unsigned int i = 1; i < accuracy; ++i) {
		cylinderIndices.push_back(startingIndex);
		cylinderIndices.push_back(startingIndex + i);
		cylinderIndices.push_back(startingIndex + i+1);
	}

	cylinderIndices.push_back(startingIndex);
	cylinderIndices.push_back(startingIndex + accuracy);
	cylinderIndices.push_back(startingIndex + 1);

	for (unsigned int i = accuracy + 2; i < 2 * accuracy + 1; ++i) {
		cylinderIndices.push_back(startingIndex + accuracy + 1);
		cylinderIndices.push_back(startingIndex + i);
		cylinderIndices.push_back(startingIndex + i+1);
	}

	cylinderIndices.push_back(startingIndex + accuracy + 1);
	cylinderIndices.push_back(startingIndex + 2 * accuracy + 1);
	cylinderIndices.push_back(startingIndex + accuracy + 2);

	for (unsigned int i = 1; i < accuracy; ++i) {
		cylinderIndices.push_back(startingIndex + i);
		cylinderIndices.push_back(startingIndex + i+1);
		cylinderIndices.push_back(startingIndex + accuracy + 1 + i);

		cylinderIndices.push_back(startingIndex + i + 1);
		cylinderIndices.push_back(startingIndex + accuracy + 1 + i);
		cylinderIndices.push_back(startingIndex + accuracy + 2 + i);
	}

	cylinderIndices.push_back(startingIndex + accuracy);
	cylinderIndices.push_back(startingIndex + 1);
	cylinderIndices.push_back(startingIndex + 2 * accuracy + 1);

	cylinderIndices.push_back(startingIndex + 1);
	cylinderIndices.push_back(startingIndex + 2 * accuracy + 1);
	cylinderIndices.push_back(startingIndex + accuracy + 2);

	return cylinderIndices;
}

std::vector<Vertex> Procedurals::drawSlouchedCuboidVertices(float positionX, float positionY, float positionZ, float width, float height, float length) {
	std::vector<Vertex> slouchedCuboidVertices = {
		{glm::vec3(positionX + 1.f, positionY + height, positionZ),						glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 1.f, 0.f)},//xz
		{glm::vec3(positionX + 1.f, positionY + height, positionZ),						glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, -1.f)},//xy
		{glm::vec3(positionX + 1.f, positionY + height, positionZ),						glm::vec3(1.f, 0.f, 0.f),			glm::vec3(-1.f, 0.f, 0.f)},//yz
		{glm::vec3(positionX + 1.f, positionY + height, positionZ + length),			glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 1.f, 0.f)},//xz
		{glm::vec3(positionX + 1.f, positionY + height, positionZ + length),			glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, 1.f)},//xy
		{glm::vec3(positionX + 1.f, positionY + height, positionZ + length),			glm::vec3(1.f, 0.f, 0.f),			glm::vec3(-1.f, 0.f, 0.f)},//yz
		{glm::vec3(positionX + width + 1.f, positionY + height, positionZ),				glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 1.f, 0.f)},//xz
		{glm::vec3(positionX + width + 1.f, positionY + height, positionZ),				glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, -1.f)},//xy
		{glm::vec3(positionX + width + 1.f, positionY + height, positionZ),				glm::vec3(1.f, 0.f, 0.f),			glm::vec3(1.f, 0.f, 0.f)},//yz
		{glm::vec3(positionX + width + 1.f, positionY + height, positionZ + length),	glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 1.f, 0.f)},//xz
		{glm::vec3(positionX + width + 1.f, positionY + height, positionZ + length),	glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, 1.f)},//xy
		{glm::vec3(positionX + width + 1.f, positionY + height, positionZ + length),	glm::vec3(1.f, 0.f, 0.f),			glm::vec3(1.f, 0.f, 0.f)},//yz
		{glm::vec3(positionX, positionY, positionZ),									glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, -1.f, 0.f)},//xz
		{glm::vec3(positionX, positionY, positionZ),									glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, -1.f)},//xy
		{glm::vec3(positionX, positionY, positionZ),									glm::vec3(1.f, 0.f, 0.f),			glm::vec3(-1.f, 0.f, 0.f)},//yz
		{glm::vec3(positionX, positionY, positionZ + length),							glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, -1.f, 0.f)},//xz
		{glm::vec3(positionX, positionY, positionZ + length),							glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, 1.f)},//xy
		{glm::vec3(positionX, positionY, positionZ + length),							glm::vec3(1.f, 0.f, 0.f),			glm::vec3(-1.f, 0.f, 0.f)},//yz
		{glm::vec3(positionX + width, positionY, positionZ),							glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, -1.f, 0.f)},//xz
		{glm::vec3(positionX + width, positionY, positionZ),							glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, -1.f)},//xy
		{glm::vec3(positionX + width, positionY, positionZ),							glm::vec3(1.f, 0.f, 0.f),			glm::vec3(1.f, 0.f, 0.f)},//yz
		{glm::vec3(positionX + width, positionY, positionZ + length),					glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, -1.f, 0.f)},//xz
		{glm::vec3(positionX + width, positionY, positionZ + length),					glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, 1.f)},//xy
		{glm::vec3(positionX + width, positionY, positionZ + length),					glm::vec3(1.f, 0.f, 0.f),			glm::vec3(1.f, 0.f, 0.f)},//yz
	};

	return slouchedCuboidVertices;
}

std::vector<Vertex> Procedurals::drawTriangularPrismVertices(float positionX, float positionY, float positionZ, float width, float height, float length) {
	std::vector<Vertex> triangularPrismVertices = {
	{glm::vec3(positionX, positionY, positionZ),													glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.707f, -0.707f)},//
	{glm::vec3(positionX, positionY, positionZ),													glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, -1.f)},//
	{glm::vec3(positionX, positionY, positionZ),													glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, -1.f, 0.f)},//
	{glm::vec3(positionX + width, positionY, positionZ),											glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, -1.f)},//
	{glm::vec3(positionX + width, positionY, positionZ),											glm::vec3(1.f, 0.f, 0.f),			glm::vec3(1.f, 0.f, 0.f)},//
	{glm::vec3(positionX + width, positionY, positionZ),											glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, -1.f, 0.f)},//
	{glm::vec3(positionX, positionY, positionZ + length),											glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.707f, -0.707f)},//
	{glm::vec3(positionX, positionY, positionZ + length),											glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, 1.f)},//
	{glm::vec3(positionX, positionY, positionZ + length),											glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, -1.f, 0.f)},//
	{glm::vec3(positionX + width, positionY, positionZ + length),									glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, 1.f)},//
	{glm::vec3(positionX + width, positionY, positionZ + length),									glm::vec3(1.f, 0.f, 0.f),			glm::vec3(1.f, 0.f, 0.f)},//
	{glm::vec3(positionX + width, positionY, positionZ + length),									glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, -1.f, 0.f)},//
	{glm::vec3(positionX + width, positionY + height, positionZ),									glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.707f, -0.707f)},//
	{glm::vec3(positionX + width, positionY + height, positionZ),									glm::vec3(1.f, 0.f, 0.f),			glm::vec3(1.f, 0.f, 0.f)},//
	{glm::vec3(positionX + width, positionY + height, positionZ),									glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, -1.f)},//
	{glm::vec3(positionX + width, positionY + height, positionZ + length),							glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.707f, -0.707f)},//
	{glm::vec3(positionX + width, positionY + height, positionZ + length),							glm::vec3(1.f, 0.f, 0.f),			glm::vec3(1.f, 0.f, 0.f)},//
	{glm::vec3(positionX + width, positionY + height, positionZ + length),							glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, 1.f)},//
	};

	return triangularPrismVertices;
}

std::vector<GLuint> Procedurals::drawTriangularPrismIndices(GLuint startingIndex) {
	std::vector<GLuint> triangularPrismIndices = {
	startingIndex, startingIndex + 6, startingIndex + 12,
	startingIndex + 6, startingIndex + 12, startingIndex + 15,
	startingIndex + 1, startingIndex + 3, startingIndex + 14,
	startingIndex + 7, startingIndex + 9, startingIndex + 17,
	startingIndex + 4, startingIndex + 10, startingIndex + 13,
	startingIndex + 10, startingIndex + 13, startingIndex + 16,
	startingIndex + 2, startingIndex + 8, startingIndex + 11,
	startingIndex + 2, startingIndex + 5, startingIndex + 11
	};

	return triangularPrismIndices;
}

std::vector<Vertex> Procedurals::drawTriangleBasedPyramidVertices(float positionX, float positionY, float positionZ, float width, float height, float length)
{
	std::vector<Vertex> triangleBasedPyramidVertices = {
	{glm::vec3(positionX, positionY, positionZ),													glm::vec3(1.f, 0.f, 0.f),			glm::vec3(-0.577f, 0.577f, 0.816f)},//
	{glm::vec3(positionX, positionY, positionZ),													glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, -1.f, 0.f)},//
	{glm::vec3(positionX, positionY, positionZ),													glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, -1.f)},//
	{glm::vec3(positionX + width, positionY, positionZ),											glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, -1.f)},//
	{glm::vec3(positionX + width, positionY, positionZ),											glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, -1.f, 0.f)},//
	{glm::vec3(positionX + width, positionY, positionZ),											glm::vec3(1.f, 0.f, 0.f),			glm::vec3(1.f, 0.f, 0.f)},//
	{glm::vec3(positionX + width, positionY, positionZ + length),									glm::vec3(1.f, 0.f, 0.f),			glm::vec3(-0.577f, 0.577f, 0.816f)},//
	{glm::vec3(positionX + width, positionY, positionZ + length),									glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, -1.f, 0.f)},//
	{glm::vec3(positionX + width, positionY, positionZ + length),									glm::vec3(1.f, 0.f, 0.f),			glm::vec3(1.f, 0.f, 0.f)},//
	{glm::vec3(positionX + width, positionY + height, positionZ),							glm::vec3(1.f, 0.f, 0.f),			glm::vec3(-0.576f, 0.576f, 0.816f)},//
	{glm::vec3(positionX + width, positionY + height, positionZ),							glm::vec3(1.f, 0.f, 0.f),			glm::vec3(0.f, 0.f, -1.f)},//
	{glm::vec3(positionX + width, positionY + height, positionZ),							glm::vec3(1.f, 0.f, 0.f),			glm::vec3(1.f, 0.f, 0.f)},//
	};

	return triangleBasedPyramidVertices;
}

std::vector<GLuint> Procedurals::drawTriangleBasedPyramidIndices(GLuint startingIndex)
{
	std::vector<GLuint> triangleBasedPyramidIndices = {
	startingIndex, startingIndex + 6, startingIndex + 9,
	startingIndex + 1, startingIndex + 4, startingIndex + 7,
	startingIndex + 5, startingIndex + 8, startingIndex + 11,
	startingIndex + 2, startingIndex + 3, startingIndex + 10,
	};

	return triangleBasedPyramidIndices;
}

std::vector<Vertex> Procedurals::drawBaselessCylinderVertices(float positionX, float positionY, float positionZ, float height, float radius, float baseRatio, unsigned int accuracy)
{
	float sinAlpha = radius * (1 - baseRatio) / (sqrt(pow(height, 2) + pow((radius * (1 - baseRatio)), 2)));
	float cosAlpha = height / (sqrt(pow(height, 2) + pow((radius * (1 - baseRatio)), 2)));

	std::vector<Vertex> baselessCylinderVertices = {};

	for (float degree = 0; degree < 360; degree += 360.f / accuracy) {
		baselessCylinderVertices.push_back({ glm::vec3(positionX, positionY + radius * sin(degree * PI / 180.f), positionZ + radius * cos(degree * PI / 180.f)),											glm::vec3(1.f, 0.f, 0.f),		glm::vec3(cosAlpha, sin(degree * PI / 180.f) * sinAlpha, cos(degree * PI / 180.f) * sinAlpha) });
	};

	for (float degree = 0; degree < 360; degree += 360.f / accuracy) {
		baselessCylinderVertices.push_back({ glm::vec3(positionX + height, positionY + (radius*baseRatio) * sin(degree * PI / 180.f), positionZ + (radius*baseRatio) * cos(degree * PI / 180.f)),	glm::vec3(1.f, 0.f, 0.f),		glm::vec3(cosAlpha, sin(degree * PI / 180.f) * sinAlpha, cos(degree * PI / 180.f) * sinAlpha) });
	};

	return baselessCylinderVertices;
}

std::vector<GLuint> Procedurals::drawBaselessCylinderIndices(GLuint startingIndex, unsigned int accuracy)
{
	std::vector<GLuint> baselessCylinderIndices = {};

	for (unsigned int i = 0; i < accuracy - 1; ++i) {
		baselessCylinderIndices.push_back(startingIndex + i);
		baselessCylinderIndices.push_back(startingIndex + i + 1);
		baselessCylinderIndices.push_back(startingIndex + accuracy + 1 + i);

		baselessCylinderIndices.push_back(startingIndex + i);
		baselessCylinderIndices.push_back(startingIndex + accuracy + i);
		baselessCylinderIndices.push_back(startingIndex + accuracy + 1 + i);
	}

	baselessCylinderIndices.push_back(startingIndex + accuracy - 1);
	baselessCylinderIndices.push_back(startingIndex);
	baselessCylinderIndices.push_back(startingIndex + 2 * accuracy - 1);

	baselessCylinderIndices.push_back(startingIndex);
	baselessCylinderIndices.push_back(startingIndex + 2 * accuracy - 1);
	baselessCylinderIndices.push_back(startingIndex + accuracy);

	return baselessCylinderIndices;
}


