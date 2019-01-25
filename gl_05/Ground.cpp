#include "Ground.h"



Ground::Ground() {
	std::vector<Vertex> *groundVertices = new std::vector<Vertex>();
	std::vector<Vertex> tempVertices;

	*groundVertices = Procedurals::drawRectangleVertices(-150.f, 0.f, -150.f, 300.f, 300.f);

	std::vector<GLuint> *groundIndices = new std::vector<GLuint>();
	std::vector<GLuint> tempIndices;

	*groundIndices = Procedurals::drawRectangleIndices(0);

	Primitive::_vertices = *groundVertices;
	Primitive::_indices = *groundIndices;

	Primitive::initVAO();
	updateModelMatrix();
}
