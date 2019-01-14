#include "Model.h"
#include <glm/gtc/matrix_transform.inl>

glm::mat4 Model::_GlobalModelMatrix = glm::mat4(1.f);

void Model::render()
{
	updateModelMatrix();

	glm::mat4 oldMM = _GlobalModelMatrix;

	//GlobalModelMatrix will be used to render all the model's childrens and model
	_GlobalModelMatrix *= _ModelMatrix;
	draw();
	_GlobalModelMatrix = oldMM;
}



void Model::updateModelMatrix() {
	_ModelMatrix = glm::mat4(1.f);
	_ModelMatrix = glm::translate(_ModelMatrix, _origin);
	_ModelMatrix = glm::rotate(_ModelMatrix, glm::radians(_rotation.x), glm::vec3(1.f, 0.f, 0.f));
	_ModelMatrix = glm::rotate(_ModelMatrix, glm::radians(_rotation.y), glm::vec3(0.f, 1.f, 0.f));
	_ModelMatrix = glm::rotate(_ModelMatrix, glm::radians(_rotation.z), glm::vec3(0.f, 0.f, 1.f));
	_ModelMatrix = glm::translate(_ModelMatrix, _pos - _origin);
	_ModelMatrix = glm::scale(_ModelMatrix, _scale);
}

void Model::setPos(const glm::vec3 pos) {
	_pos = pos;
}

void Model::move(const glm::vec3 pos) {
	_pos += pos;
}

void Model::setOrigin(const glm::vec3 origin) {
	_origin = origin;
}

void Model::setRotation(const glm::vec3 rotation) {
	_rotation = rotation;
}

void Model::rotate(const glm::vec3 rotation) {
	_rotation += rotation;
}

void Model::setScale(const glm::vec3 scale) {
	_scale = scale;
}

void Model::scale(const glm::vec3 scale) {
	_scale += scale;
}
