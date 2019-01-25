#include "WheelBox.h"



WheelBox::WheelBox() {
	std::vector<Vertex> *wheelBoxVertices = new std::vector<Vertex>();

	*wheelBoxVertices = Procedurals::drawCuboidVertices(0.f, 0.f, 0.f, 2.1f, 0.14f, 0.14f);

	std::vector<GLuint> *wheelBoxIndices = new std::vector<GLuint>();

	*wheelBoxIndices = Procedurals::drawCuboidIndices(0);

	Primitive::_vertices = *wheelBoxVertices;
	Primitive::_indices = *wheelBoxIndices;

	Primitive::initVAO();
	updateModelMatrix();
}
