#include "BlackBox.h"



BlackBox::BlackBox() {
	std::vector<Vertex> *blackBoxVertices = new std::vector<Vertex>();
	std::vector<Vertex> tempVertices;

	*blackBoxVertices = Procedurals::drawCuboidVertices(8.f, 7.f, 0.5f, 18.f, 3.5f, 13.f);

	std::vector<GLuint> *blackBoxIndices = new std::vector<GLuint>();
	std::vector<GLuint> tempIndices;

	*blackBoxIndices = Procedurals::drawCuboidIndices(0);

	Primitive::_vertices = *blackBoxVertices;
	Primitive::_indices = *blackBoxIndices;

	Primitive::initVAO();
	updateModelMatrix();
}


BlackBox::~BlackBox() {
}
