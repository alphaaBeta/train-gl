#include "Wheel.h"



Wheel::Wheel() {
	std::vector<Vertex> tempVertices;
	std::vector<Vertex> *wheelVertices = new std::vector<Vertex>();

	*wheelVertices = Procedurals::drawBaselessCylinderVertices(0.f, 0.f, 0.f, 0.3f, 2.5f, 0.8f, 30);
	tempVertices = Procedurals::drawBaselessCylinderVertices(0.3f, 0.f, 0.f, 0.3f, 2.f, 1.25f, 30);
	wheelVertices->insert(wheelVertices->end(), tempVertices.begin(), tempVertices.end());
	tempVertices = Procedurals::drawCylinderVertices(0.2f, 0.f, 0.f, 0.2f, 0.4f, 1.f, 30);
	wheelVertices->insert(wheelVertices->end(), tempVertices.begin(), tempVertices.end());
	tempVertices = Procedurals::drawCylinderVertices(0.1f, 0.f, 0.f, 0.4f, 0.25f, 1.f, 30);
	wheelVertices->insert(wheelVertices->end(), tempVertices.begin(), tempVertices.end());
	tempVertices = Procedurals::drawCylinderVertices(0.29f, 0.f, 0.f, 0.02f, 2.f, 1.f, 30);
	wheelVertices->insert(wheelVertices->end(), tempVertices.begin(), tempVertices.end());

	std::vector<GLuint> *wheelIndices = new std::vector<GLuint>();
	std::vector<GLuint> tempIndices;

	*wheelIndices = Procedurals::drawBaselessCylinderIndices(0, 30);
	tempIndices = Procedurals::drawBaselessCylinderIndices(60, 30);
	wheelIndices->insert(wheelIndices->end(), tempIndices.begin(), tempIndices.end());
	tempIndices = Procedurals::drawCylinderIndices(120, 30);
	wheelIndices->insert(wheelIndices->end(), tempIndices.begin(), tempIndices.end());
	tempIndices = Procedurals::drawCylinderIndices(182, 30);
	wheelIndices->insert(wheelIndices->end(), tempIndices.begin(), tempIndices.end());
	tempIndices = Procedurals::drawCylinderIndices(244, 30);
	wheelIndices->insert(wheelIndices->end(), tempIndices.begin(), tempIndices.end());

	Primitive::_vertices = *wheelVertices;
	Primitive::_indices = *wheelIndices;

	Primitive::initVAO();
	updateModelMatrix();
}
