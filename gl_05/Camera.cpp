#include "Camera.h"

void Camera::updateCamVecs() {
	_front.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
	_front.y = sin(glm::radians(_pitch));
	_front.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));

	_front = glm::normalize(_front);
	// cross() is vecA x vecB so result is prostopadly to A and B
	_right = glm::normalize(glm::cross(_front, _worldUp));
	_up = glm::normalize(glm::cross(_right, _front));
}

Camera::Camera(glm::vec3 pos, glm::vec3 worldUp) {
	_ViewMatrix = glm::mat4(1.f);

	_moveSpeed = 3.f;
	_sense = 5.f;

	_worldUp = worldUp;
	_pos = pos;
	_right = glm::vec3(0.f);
	_up = worldUp;

	_pitch = 0.f;
	_yaw = -90.f;
	_roll = 0.f;

	updateCamVecs();
}

Camera::~Camera()
{
}

const glm::vec3 Camera::getPosition() const
{
	return _pos;
}

const glm::mat4 Camera::getViewMatrix() {
	updateCamVecs();	// location    target     up
	_ViewMatrix = glm::lookAt(_pos, _pos + _front, _up);
	return _ViewMatrix;
}

void Camera::move(const float &dt, const int direction) {
	switch (direction)
	{
	case LEFT:
		_pos -= _right * _moveSpeed * dt;
		break;
	case RIGHT:
		_pos += _right * _moveSpeed * dt;
		break;
	case FORWARD:
		_pos += _front * _moveSpeed * dt;
		break;
	case BACKWARD:
		_pos -= _front * _moveSpeed * dt;
		break;
	default:
		break;
	}
}

void Camera::updateMouseInput(const float &dt, const double &offsetX, const double &offsetY) {
	_pitch += offsetY * _sense * dt;
	_yaw += offsetX * _sense * dt;

	if (_pitch > 80.f)
		_pitch = 80.f;
	else if (_pitch < -80.f)
		_pitch = -80.f;

	if (_yaw > 360.f || _yaw < -360.f)
		_yaw = 0.f;
}




