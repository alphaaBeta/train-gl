#include "Bumpers.h"



Bumpers::Bumpers(){
	std::vector<Vertex> tempVertices;
	std::vector<Vertex> *bumpersVertices = new std::vector<Vertex>();

	*bumpersVertices = Procedurals::drawCylinderVertices(1.f, 4.f, 4.f, 1.f, 0.3f, 1.f, 30);
	tempVertices = Procedurals::drawCylinderVertices(0.7f, 4.f, 4.f, 0.3f, 1.2f, 1.f, 30);
	bumpersVertices->insert(bumpersVertices->end(), tempVertices.begin(), tempVertices.end());
	tempVertices = Procedurals::drawCylinderVertices(1.f, 4.f, 10.f, 1.f, 0.3f, 1.f, 30);
	bumpersVertices->insert(bumpersVertices->end(), tempVertices.begin(), tempVertices.end());
	tempVertices = Procedurals::drawCylinderVertices(0.7f, 4.f, 10.f, 0.3f, 1.2f, 1.f, 30);
	bumpersVertices->insert(bumpersVertices->end(), tempVertices.begin(), tempVertices.end());

	std::vector<GLuint> *bumpersIndices = new std::vector<GLuint>();
	std::vector<GLuint> tempIndices;

	*bumpersIndices = Procedurals::drawCylinderIndices(0, 30);
	tempIndices = Procedurals::drawCylinderIndices(62, 30);
	bumpersIndices->insert(bumpersIndices->end(), tempIndices.begin(), tempIndices.end());
	tempIndices = Procedurals::drawCylinderIndices(124, 30);
	bumpersIndices->insert(bumpersIndices->end(), tempIndices.begin(), tempIndices.end());
	tempIndices = Procedurals::drawCylinderIndices(186, 30);
	bumpersIndices->insert(bumpersIndices->end(), tempIndices.begin(), tempIndices.end());

	Primitive::_vertices = *bumpersVertices;
	Primitive::_indices = *bumpersIndices;

	Primitive::initVAO();
	updateModelMatrix();
}

