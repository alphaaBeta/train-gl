#include "Skybox.h"
#include "Procedurals.h"


Skybox::Skybox()
{
	std::vector<Vertex> *skyboxVertices = new std::vector<Vertex>();

	*skyboxVertices = Procedurals::drawCuboidVertices(-150.f, -150.f, -150.f, 300.f, 300.f, 300.f);

	std::vector<GLuint> *skyboxIndices = new std::vector<GLuint>();

	*skyboxIndices = Procedurals::drawCuboidIndices(0);

	Primitive::_vertices = *skyboxVertices;
	Primitive::_indices = *skyboxIndices;

	Primitive::initVAO();
	updateModelMatrix();
}
