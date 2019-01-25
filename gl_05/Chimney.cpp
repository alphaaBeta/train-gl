#include "Chimney.h"



Chimney::Chimney() {
	std::vector<Vertex> tempVertices;
	std::vector<Vertex> *chimneyVertices = new std::vector<Vertex>();

	*chimneyVertices = Procedurals::drawCylinderVertices(0.f, 0.f, 0.f, 4.f, 1.f, 1.f, 30);//bottom
	tempVertices = Procedurals::drawCylinderVertices (4.f, 0.f, 0.f, 1.f, 1.f, 2.f, 30);//middle
	chimneyVertices->insert(chimneyVertices->end(), tempVertices.begin(), tempVertices.end());
	tempVertices = Procedurals::drawCylinderVertices(5.f, 0.f, 0.f, 3.f, 2.f, 1.f, 30);//top
	chimneyVertices->insert(chimneyVertices->end(), tempVertices.begin(), tempVertices.end());

	std::vector<GLuint> *chimneyIndices = new std::vector<GLuint>();
	std::vector<GLuint> tempIndices;

	*chimneyIndices = Procedurals::drawCylinderIndices(0, 30);//bottom
	tempIndices = Procedurals::drawCylinderIndices(62, 30);//middle
	chimneyIndices->insert(chimneyIndices->end(), tempIndices.begin(), tempIndices.end());
	tempIndices = Procedurals::drawCylinderIndices(124, 30);//top
	chimneyIndices->insert(chimneyIndices->end(), tempIndices.begin(), tempIndices.end());

	Primitive::_vertices = *chimneyVertices;
	Primitive::_indices = *chimneyIndices;

	Primitive::initVAO();
	updateModelMatrix();
}
