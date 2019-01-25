#include "Piston.h"



Piston::Piston() {
	std::vector<Vertex> *pistonVertices = new std::vector<Vertex>();

	*pistonVertices = Procedurals::drawSlouchedCuboidVertices(0.f, 0.f, 0.f, 0.8f, 5.5f, 0.4f);

	std::vector<GLuint> *pistonIndices = new std::vector<GLuint>();

	*pistonIndices = Procedurals::drawCuboidIndices(0);

	Primitive::_vertices = *pistonVertices;
	Primitive::_indices = *pistonIndices;

	Primitive::initVAO();
	updateModelMatrix();
}

