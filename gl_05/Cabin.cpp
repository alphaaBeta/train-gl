#include "Cabin.h"
#include "Game.h"


Cabin::Cabin()
{		
	std::vector<Vertex> tempVertices;

	std::vector<Vertex> *cabinVertices = new std::vector<Vertex>();

	tempVertices = Procedurals::drawRectangleVertices(19.f, 23.f, 0.5f, 14.f, 13.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	tempVertices = Procedurals::drawCuboidVertices(31.f, 6.f, 2.5f, 1.f, 17.f, 9.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	std::vector<GLuint> tempIndices;

	std::vector<GLuint> *cabinIndices = new std::vector<GLuint>();

	tempIndices = Procedurals::drawRectangleIndices(0);
	cabinIndices->insert(cabinIndices->end(), tempIndices.begin(), tempIndices.end());

	tempIndices = Procedurals::drawCuboidIndices(4);
	cabinIndices->insert(cabinIndices->end(), tempIndices.begin(), tempIndices.end());

	Primitive::_vertices = *cabinVertices;
	Primitive::_indices = *cabinIndices;

	Primitive::initVAO();
	updateModelMatrix();

}




Cabin::~Cabin()
{

}
