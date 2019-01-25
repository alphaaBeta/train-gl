#include "Boiler.h"



Boiler::Boiler() {
	std::vector<Vertex> *boilerVertices = new std::vector<Vertex>();
	std::vector<Vertex> tempVertices;

	*boilerVertices = Procedurals::drawCylinderVertices(4.f, 11.5f, 7.f, 17.f, 4.5f, 1.f, 60);
	tempVertices = Procedurals::drawCuboidVertices(11.f, 15.f, 5.f, 5.f, 5.f, 4.f);
	boilerVertices->insert(boilerVertices->end(), tempVertices.begin(), tempVertices.end());
	tempVertices = Procedurals::drawCuboidVertices(17.f, 15.f, 6.f, 2.5f, 3.f, 2.f);
	boilerVertices->insert(boilerVertices->end(), tempVertices.begin(), tempVertices.end());


	std::vector<GLuint> *boilerIndices = new std::vector<GLuint>();
	std::vector<GLuint> tempIndices;

	*boilerIndices = Procedurals::drawCylinderIndices(0, 60);
	tempIndices = Procedurals::drawCuboidIndices(122);
	boilerIndices->insert(boilerIndices->end(), tempIndices.begin(), tempIndices.end());
	tempIndices = Procedurals::drawCuboidIndices(146);
	boilerIndices->insert(boilerIndices->end(), tempIndices.begin(), tempIndices.end());

	Primitive::_vertices = *boilerVertices;
	Primitive::_indices = *boilerIndices;

	Primitive::initVAO();
	updateModelMatrix();
}
