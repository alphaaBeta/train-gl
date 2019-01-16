#pragma once

#define GLEW_STATIC
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum direction { FORWARD = 0, BACKWARD, LEFT, RIGHT, UP, DOWN };

class Camera {
  private:
    glm::mat4 _ViewMatrix;

    GLfloat _moveSpeed;
    GLfloat _sense;

    glm::vec3 _worldUp;
    glm::vec3 _pos;
    glm::vec3 _front;
    glm::vec3 _right;
    glm::vec3 _up;

    // https://howthingsfly.si.edu/flight-dynamics/roll-pitch-and-yaw
    GLfloat _pitch;
    GLfloat _yaw;
    GLfloat _roll;

    void updateCamVecs();

  public:
    Camera(glm::vec3 pos, glm::vec3 worldUp);
    ~Camera();
    const glm::vec3 getPosition() const;
    const void setPosition(glm::vec3 pos);
    const glm::mat4 getViewMatrix();
    void move(const float &dt, const int direction);
    void updateMouseInput(const float &dt, const double &offsetX, const double &offsetY);
};