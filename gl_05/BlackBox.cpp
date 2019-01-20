#include "BlackBox.h"



BlackBox::BlackBox() {
	std::vector<Vertex> *blackBoxVertices = new std::vector<Vertex>();
	std::vector<Vertex> tempVertices;

	*blackBoxVertices = Procedurals::drawCuboidVertices(8.f, 7.f, 0.5f, 18.f, 3.5f, 13.f);
	tempVertices = Procedurals::drawSlouchedCuboidVertices(10.f, 5.5f, 12.5f, 2.f, 1.5f, 1.f);
	blackBoxVertices->insert(blackBoxVertices->end(), tempVertices.begin(), tempVertices.end());
	tempVertices = Procedurals::drawSlouchedCuboidVertices(22.5f, 5.5f, 12.5f, 2.f, 1.5f, 1.f);
	blackBoxVertices->insert(blackBoxVertices->end(), tempVertices.begin(), tempVertices.end());
	tempVertices = Procedurals::drawSlouchedCuboidVertices(10.f, 5.5f, 0.5f, 2.f, 1.5f, 1.f);
	blackBoxVertices->insert(blackBoxVertices->end(), tempVertices.begin(), tempVertices.end());
	tempVertices = Procedurals::drawSlouchedCuboidVertices(22.5f, 5.5f, 0.5f, 2.f, 1.5f, 1.f);
	blackBoxVertices->insert(blackBoxVertices->end(), tempVertices.begin(), tempVertices.end());

	std::vector<GLuint> *blackBoxIndices = new std::vector<GLuint>();
	std::vector<GLuint> tempIndices;

	*blackBoxIndices = Procedurals::drawCuboidIndices(0);
	tempIndices = Procedurals::drawCuboidIndices(24);
	blackBoxIndices->insert(blackBoxIndices->end(), tempIndices.begin(), tempIndices.end());
	tempIndices = Procedurals::drawCuboidIndices(48);
	blackBoxIndices->insert(blackBoxIndices->end(), tempIndices.begin(), tempIndices.end());
	tempIndices = Procedurals::drawCuboidIndices(72);
	blackBoxIndices->insert(blackBoxIndices->end(), tempIndices.begin(), tempIndices.end());
	tempIndices = Procedurals::drawCuboidIndices(96);
	blackBoxIndices->insert(blackBoxIndices->end(), tempIndices.begin(), tempIndices.end());

	Primitive::_vertices = *blackBoxVertices;
	Primitive::_indices = *blackBoxIndices;

	Primitive::initVAO();
	updateModelMatrix();
}


BlackBox::~BlackBox() {
}
