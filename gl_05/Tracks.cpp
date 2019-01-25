#include "Tracks.h"

Tracks::Tracks() {
	std::vector<Vertex> *tracksVertices = new std::vector<Vertex>();
	std::vector<Vertex> tempVertices;

	*tracksVertices = Procedurals::drawCuboidVertices(-150.f, 0.5f, 0.98f, 300.f, 0.3f, 0.25f);
	tempVertices = Procedurals::drawCuboidVertices(-150.f, 0.5f, 12.78f, 300.f, 0.3f, 0.25f);
	tracksVertices->insert(tracksVertices->end(), tempVertices.begin(), tempVertices.end());

	for (int i = 0; i < 200; ++i) {
		tempVertices = Procedurals::drawCuboidVertices(-150.f+1.5f*i, 0.0f, 0.48f, 0.75f, 0.5f, 12.80f);
		tracksVertices->insert(tracksVertices->end(), tempVertices.begin(), tempVertices.end());
	}

	std::vector<GLuint> *tracksIndices = new std::vector<GLuint>();
	std::vector<GLuint> tempIndices;

	*tracksIndices = Procedurals::drawCuboidIndices(0);
	tempIndices = Procedurals::drawCuboidIndices(24);
	tracksIndices->insert(tracksIndices->end(), tempIndices.begin(), tempIndices.end());

	for (int i = 0; i < 200; ++i) {
		tempIndices = Procedurals::drawCuboidIndices(48+24*i);
		tracksIndices->insert(tracksIndices->end(), tempIndices.begin(), tempIndices.end());
	}

	Primitive::_vertices = *tracksVertices;
	Primitive::_indices = *tracksIndices;

	Primitive::initVAO();
	updateModelMatrix();
}
