#include "SideBuffer.h"

SideBuffer::SideBuffer() {
	std::vector<Vertex> *sideBufferVertices = new std::vector<Vertex>();
	std::vector<Vertex> tempVertices;

	*sideBufferVertices = Procedurals::drawTriangularPrismVertices(0.f, 0.f, 0.f, 2.f, 2.f, 2.5f);
	tempVertices = Procedurals::drawTriangleBasedPyramidVertices(0.f, 0.f, 2.5f, 2.f, 2.f, 2.f);
	sideBufferVertices->insert(sideBufferVertices->end(), tempVertices.begin(), tempVertices.end());

	std::vector<GLuint> *sideBufferIndices = new std::vector<GLuint>();
	std::vector<GLuint> tempIndices;

	*sideBufferIndices = Procedurals::drawTriangularPrismIndices(0);
	tempIndices = Procedurals::drawTriangleBasedPyramidIndices(18);
	sideBufferIndices->insert(sideBufferIndices->end(), tempIndices.begin(), tempIndices.end());

	Primitive::_vertices = *sideBufferVertices;
	Primitive::_indices = *sideBufferIndices;

	Primitive::initVAO();
	updateModelMatrix();
}


