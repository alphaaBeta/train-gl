#include "chassisBox.h"



ChassisBox::ChassisBox(){
	std::vector<Vertex> *chassisBoxVertices = new std::vector<Vertex>();
	std::vector<Vertex> tempVertices;

	*chassisBoxVertices = Procedurals::drawCuboidVertices(4.f, 3.f, 1.5f, 27.f, 4.f, 11.f);

	std::vector<GLuint> *chassisBoxIndices = new std::vector<GLuint>();
	std::vector<GLuint> tempIndices;

	*chassisBoxIndices = Procedurals::drawCuboidIndices(0);

	Primitive::_vertices = *chassisBoxVertices;
	Primitive::_indices = *chassisBoxIndices;

	Primitive::initVAO();
	updateModelMatrix();
}
