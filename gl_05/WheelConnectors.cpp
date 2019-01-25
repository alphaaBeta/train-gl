#include "WheelConnectors.h"



WheelConnectors::WheelConnectors() {
	std::vector<Vertex> *wheelConnectorsVertices = new std::vector<Vertex>();
	std::vector<Vertex> tempVertices;

	*wheelConnectorsVertices = Procedurals::drawCuboidVertices(8.f, 2.f, -0.1f, 16.f, 0.5f, 0.4f);
	tempVertices = Procedurals::drawCuboidVertices(8.f, 2.f, 12.8f, 16.f, 0.5f, 0.4f);
	wheelConnectorsVertices->insert(wheelConnectorsVertices->end(), tempVertices.begin(), tempVertices.end());

	std::vector<GLuint> *wheelConnectorsIndices = new std::vector<GLuint>();
	std::vector<GLuint> tempIndices;

	*wheelConnectorsIndices = Procedurals::drawCuboidIndices(0);
	tempIndices = Procedurals::drawCuboidIndices(24);
	wheelConnectorsIndices->insert(wheelConnectorsIndices->end(), tempIndices.begin(), tempIndices.end());

	Primitive::_vertices = *wheelConnectorsVertices;
	Primitive::_indices = *wheelConnectorsIndices;

	Primitive::initVAO();
	updateModelMatrix();
}
