#include "FrontBuffer.h"



FrontBuffer::FrontBuffer(){
	std::vector<Vertex> *frontBufferVertices = new std::vector<Vertex>();
	std::vector<Vertex> tempVertices;

	*frontBufferVertices = Procedurals::drawCuboidVertices(2.f, 2.5f, 1.5f, 2.f, 2.5f, 11.f);
	tempVertices = Procedurals::drawTriangularPrismVertices(2.f, 5.f, 1.5f, 2.f, 2.f, 11.f);
	frontBufferVertices->insert(frontBufferVertices->end(), tempVertices.begin(), tempVertices.end());

	std::vector<GLuint> *frontBufferIndices = new std::vector<GLuint>();
	std::vector<GLuint> tempIndices;

	*frontBufferIndices = Procedurals::drawCuboidIndices(0);
	tempIndices = Procedurals::drawTriangularPrismIndices(24);
	frontBufferIndices->insert(frontBufferIndices->end(), tempIndices.begin(), tempIndices.end());

	Primitive::_vertices = *frontBufferVertices;
	Primitive::_indices = *frontBufferIndices;

	Primitive::initVAO();
	updateModelMatrix();
}


