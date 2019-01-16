#include "Boiler.h"



Boiler::Boiler() {
	std::vector<Vertex> *boilerVertices = new std::vector<Vertex>();

	*boilerVertices = Procedurals::drawCylinderVertices(0.f, 0.f, 0.f, 10.f, 5.f, 37);

	std::vector<GLuint> *boilerIndices = new std::vector<GLuint>();

	*boilerIndices = Procedurals::drawCylinderIndices(0, 37);

	Primitive::_vertices = *boilerVertices;
	Primitive::_indices = *boilerIndices;

	Primitive::initVAO();
	updateModelMatrix();
}


Boiler::~Boiler()
{
}
