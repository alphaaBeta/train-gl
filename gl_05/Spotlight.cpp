#include "Spotlight.h"



Spotlight::Spotlight(){
	std::vector<Vertex> tempVertices;
	std::vector<Vertex> *spotlightVertices = new std::vector<Vertex>();

	/**spotlightVertices = Procedurals::drawCylinderVertices(3.5f, 12.5f, 6.5f, 0.5f, 1.f, 1.f, 30);
	tempVertices = Procedurals::drawCylinderVertices(3.4f, 12.5f, 6.5f, 0.1f, 1.f, 0.f, 30);
	spotlightVertices->insert(spotlightVertices->end(), tempVertices.begin(), tempVertices.end());*/

	*spotlightVertices = Procedurals::drawCylinderVertices(0.f, 0.f, 0.f, 0.5f, 1.f, 1.f, 30);
	tempVertices = Procedurals::drawCylinderVertices(0.5f, 0.f, 0.f, 0.1f, 1.f, 0.f, 30);
	spotlightVertices->insert(spotlightVertices->end(), tempVertices.begin(), tempVertices.end());

	std::vector<GLuint> *spotlightIndices = new std::vector<GLuint>();
	std::vector<GLuint> tempIndices;

	*spotlightIndices = Procedurals::drawCylinderIndices(0, 30);
	tempIndices = Procedurals::drawCylinderIndices(62, 30);
	spotlightIndices->insert(spotlightIndices->end(), tempIndices.begin(), tempIndices.end());

	Primitive::_vertices = *spotlightVertices;
	Primitive::_indices = *spotlightIndices;

	Primitive::initVAO();
	updateModelMatrix();
}
