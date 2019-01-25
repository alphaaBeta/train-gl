#pragma once

#include <iostream>
#include <vector>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp>

#include "ShaderProgram.h"
#include "Texture.h"
#include "Camera.h"
#include "Primitive.h"
#include "Group.h"
#include "Cabin.h"
#include "Boiler.h"
#include "Chimney.h"
#include "Skybox.h"
#include "BlackBox.h"
#include "Spotlight.h"
#include "chassisBox.h"
#include "FrontBuffer.h"
#include "SideBuffer.h"
#include "Bumpers.h"
#include "Piston.h"
#include "Wheel.h"
#include "WheelBox.h"
#include "WheelConnectors.h"
#include "Ground.h"
#include "Tracks.h"

#define PI 3.14159265359

enum {LIGHT = 0, MODELS};

class Group;

class Game {
  private:
    // Window
    GLFWwindow *_window;
    const int W_WIDTH;
    const int W_HEIGHT;
    int _frameBuffWidth;
    int _frameBuffHeight;

    // Mouse
    double _lastMouseX;
    double _lastMouseY;
    double _mouseX;
    double _mouseY;
    double _mouseOffsetX;
    double _mouseOffsetY;
    bool _firstMouse;

    // Camera
    Camera _camera;
    float _fov;
    float _nearPlane;
    float _farPlane;

    // Matrixes
    glm::mat4 _ViewMatrix;
    glm::vec3 _camPos;
    glm::vec3 _worldUp;
    glm::vec3 _camFront;

    glm::mat4 _ProjMatrix;

    // Shaders
    std::vector<ShaderProgram *> _shaders;

    // TODO:Textures

    // Models
    std::vector<Model *> _objects;

    // Light (for now used as directional light)
    glm::vec3 _lightPos;

    void initGLFW();
    void initWindow(const char *title, bool resizable);
    void initGLEW();
    void initOpenGLOptions();
    void initMatrices();
    void initShaders();
    //void initTextures();
    void initModels(Group &root);
	void initHighPistons(Group &higherPistons);
	void initWheels(Group &rightFrontWheel, Group &leftFrontWheel, Group &rightMiddleFirstWheel, Group &leftMiddleFirstWheel, Group &rightMiddleSecondWheel, Group &leftMiddleSecondWheel, Group &rightBackWheel, Group &leftBackWheel);
	void initWheelConnectors(Group &wheelConnectors);
	void initGround(Group &ground);
	void initLights();
    void initUniforms();

	float wheelConnectorDegree = 0.f;

  public:
    Game(const char *title, const int width, const int height, bool resizable);
    ~Game();
    void updateKeyInput(const float &dt);
    void updateMouseInput();
    int getWindowShouldClose();
    void update(const float &dt);
    void render();
    void updateUniforms();
};

