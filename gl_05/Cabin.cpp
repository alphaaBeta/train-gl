#include "Cabin.h"
#include "Game.h"


Cabin::Cabin()
{		
	std::vector<Vertex> tempVertices;

	std::vector<Vertex> *cabinVertices = new std::vector<Vertex>();

	tempVertices = Procedurals::drawCuboidVertices(19.f, 23.f, 0.5f, 14.f, 0.2f, 13.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	tempVertices = Procedurals::drawCuboidVertices(31.f, 7.f, 1.5f, 1.f, 16.f, 11.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	tempVertices = Procedurals::drawCuboidVertices(26.f, 22.f, 1.5f, 5.f, 1.f, 1.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	tempVertices = Procedurals::drawCuboidVertices(20.f, 21.f, 1.5f, 6.f, 2.f, 1.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	tempVertices = Procedurals::drawCuboidVertices(20.f, 16.f, 1.5f, 1.f, 5.f, 1.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	tempVertices = Procedurals::drawCuboidVertices(25.f, 16.f, 1.5f, 1.f, 5.f, 1.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	tempVertices = Procedurals::drawCuboidVertices(20.f, 7.f, 1.5f, 6.f, 10.f, 1.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	//heh
	tempVertices = Procedurals::drawCuboidVertices(26.f, 22.f, 11.5f, 5.f, 1.f, 1.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	tempVertices = Procedurals::drawCuboidVertices(20.f, 21.f, 11.5f, 6.f, 2.f, 1.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	tempVertices = Procedurals::drawCuboidVertices(20.f, 16.f, 11.5f, 1.f, 5.f, 1.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	tempVertices = Procedurals::drawCuboidVertices(25.f, 16.f, 11.5f, 1.f, 5.f, 1.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	tempVertices = Procedurals::drawCuboidVertices(20.f, 7.f, 11.5f, 6.f, 10.f, 1.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	tempVertices = Procedurals::drawCuboidVertices(20.f, 21.f, 2.5f, 1.f, 2.f, 9.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	tempVertices = Procedurals::drawCuboidVertices(20.f, 17.f, 5.5f, 1.f, 4.f, 3.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	tempVertices = Procedurals::drawCuboidVertices(20.f, 7.f, 1.5f, 12.f, 1.f, 11.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	tempVertices = Procedurals::drawCuboidVertices(20.f, 8.f, 2.5f, 1.f, 9.f, 9.f);
	cabinVertices->insert(cabinVertices->end(), tempVertices.begin(), tempVertices.end());

	std::vector<GLuint> tempIndices;

	std::vector<GLuint> *cabinIndices = new std::vector<GLuint>();

	tempIndices = Procedurals::drawRectangleIndices(0);
	cabinIndices->insert(cabinIndices->end(), tempIndices.begin(), tempIndices.end());

	for (GLuint i = 0; i <= 380; i = i + 24) {
		tempIndices = Procedurals::drawCuboidIndices(i);
		cabinIndices->insert(cabinIndices->end(), tempIndices.begin(), tempIndices.end());
	}

	Primitive::_vertices = *cabinVertices;
	Primitive::_indices = *cabinIndices;

	Primitive::initVAO();
	updateModelMatrix();

}
