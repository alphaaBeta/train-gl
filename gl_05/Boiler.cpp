#include "Boiler.h"



Boiler::Boiler() {
	std::vector<Vertex> *boilerVertices = new std::vector<Vertex>();

	*boilerVertices = Procedurals::drawCylinderVertices(4.f, 11.5f, 7.f, 17.f, 4.5f, 1.f, 60);

	std::vector<GLuint> *boilerIndices = new std::vector<GLuint>();

	*boilerIndices = Procedurals::drawCylinderIndices(0, 60);

	Primitive::_vertices = *boilerVertices;
	Primitive::_indices = *boilerIndices;

	Primitive::initVAO();
	updateModelMatrix();
}
