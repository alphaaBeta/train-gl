#include "Game.h"


void Game::initUniforms() {
    _shaders[MODELS]->setMat4fv(_ViewMatrix, "ViewMatrix");
    _shaders[MODELS]->setMat4fv(_ProjMatrix, "ProjMatrix");
}

Game::Game(const char *title, const int width, const int height, bool resizable = false) : W_WIDTH(width), W_HEIGHT(height), _camera(glm::vec3(-1.f, 12.5f, 7.f), glm::vec3(0.f, 1.f, 0.f)) {
    _window = nullptr;
    _frameBuffWidth = W_WIDTH;
    _frameBuffHeight = W_HEIGHT;

    _camPos = glm::vec3(19.f, 26.f, 10.f);
    _worldUp = glm::vec3(0.f, 1.f, 0.f);
    _camFront = glm::vec3(1.f, 0.f, 0.f);

    _fov = 45.f;
    _nearPlane = 0.1f;
    _farPlane = 1000.f;

    Group *workspace = new Group();

	Group *higherPistons = new Group();
	Group *lowerPistons = new Group();

	Group *rightFrontWheel = new Group();
	Group *leftFrontWheel = new Group();
	Group *rightMiddleFirstWheel = new Group();
	Group *leftMiddleFirstWheel = new Group();
	Group *rightMiddleSecondWheel = new Group();
	Group *leftMiddleSecondWheel = new Group();
	Group *rightBackWheel = new Group();
	Group *leftBackWheel = new Group();

	Group *wheelConnectors = new Group();

	Group *ground = new Group();


    _objects.push_back(workspace);
	_objects.push_back(higherPistons);
	_objects.push_back(rightFrontWheel);
	_objects.push_back(leftFrontWheel);
	_objects.push_back(rightMiddleFirstWheel);
	_objects.push_back(leftMiddleFirstWheel);
	_objects.push_back(rightMiddleSecondWheel);
	_objects.push_back(leftMiddleSecondWheel);
	_objects.push_back(rightBackWheel);
	_objects.push_back(leftBackWheel);
	_objects.push_back(wheelConnectors);
	_objects.push_back(ground);

    initGLFW();
    initWindow(title, resizable);
    initGLEW();
    initOpenGLOptions();

    initMatrices();
    initShaders();


    //initTextures();
    //initMaterials();
    initModels(*workspace);
	initHighPistons(*higherPistons);
	initWheels(*rightFrontWheel, *leftFrontWheel, *rightMiddleFirstWheel, *leftMiddleFirstWheel, *rightMiddleSecondWheel, *leftMiddleSecondWheel, *rightBackWheel, *leftBackWheel);
	initWheelConnectors(*wheelConnectors);
	initGround(*ground);
    //initLights();
    initUniforms();
}

Game::~Game() {
    glfwDestroyWindow(_window);
    glfwTerminate();

    for (const auto &i : _shaders) {
        delete i;
    }

    for (const auto &i : _objects)
        delete i;

}

void Game::updateKeyInput(const float &dt) {
    //Program
    if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(_window, GL_TRUE);
    }

    //Camera
    if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) {
        _camera.move(dt, FORWARD);
    }
    if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) {
        _camera.move(dt, BACKWARD);
    }
    if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) {
        _camera.move(dt, LEFT);
    }
    if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) {
        _camera.move(dt, RIGHT);
    }
    if (glfwGetKey(_window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        _camera.move(dt, UP);
    }
    if (glfwGetKey(_window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
        _camera.move(dt, DOWN);
    }

	//Light
	if (glfwGetKey(_window, GLFW_KEY_2) == GLFW_PRESS) {
		light +=0.01f;
		ambient += 0.01f;
	}
	if (glfwGetKey(_window, GLFW_KEY_1) == GLFW_PRESS) {
		light -= 0.01f;
		ambient -= 0.01f;
	}
}

void Game::updateMouseInput() {
    glfwGetCursorPos(_window, &_mouseX, &_mouseY);

    if (_firstMouse) {
        _lastMouseX = _mouseX;
        _lastMouseY = _mouseY;
        _firstMouse = false;
    }

    //Calc offset
    _mouseOffsetX = _mouseX - _lastMouseX;
    _mouseOffsetY = _lastMouseY - _mouseY;

    //Set last X and Y
    _lastMouseX = _mouseX;
    _lastMouseY = _mouseY;
}

int Game::getWindowShouldClose() {
    return glfwWindowShouldClose(_window);
}

void Game::update(const float &dt) {
    glfwPollEvents();

	_objects[1]->setPos(glm::vec3(0.5f));
	_objects[1]->move(glm::vec3(1.5f * sin(wheelConnectorDegree * PI / 180.f), -1.5f * cos(wheelConnectorDegree * PI / 180.f), 0.f));
	_objects[10]->setPos(glm::vec3(0.5f));
	_objects[10]->move(glm::vec3(1.5f * sin(wheelConnectorDegree * PI / 180.f), -1.5f * cos(wheelConnectorDegree * PI / 180.f), 0.f));
	wheelConnectorDegree += 0.80f;

	_objects[11]->move(glm::vec3(0.03f, 0.f, 0.f));
	if (_objects[11]->_pos.x >= 3.f)
	{
		_objects[11]->move(glm::vec3(-3.f, 0.f, 0.f));
	}

    updateKeyInput(dt);
    updateMouseInput();
    _camera.updateMouseInput(dt, _mouseOffsetX, _mouseOffsetY);
}

void Game::render() {
    glClearColor(0.70588f, 0.87451f, 0.97647f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    //Update the uniforms
    updateUniforms();

    //Render models
    for (const auto &i : _objects) {
        i->render();
    }

    //End Draw
    glfwSwapBuffers(_window);
    glFlush();

    glBindVertexArray(0);
    glUseProgram(0);
    glActiveTexture(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Game::updateUniforms() {
    //Update view matrix (camera)
    _ViewMatrix = _camera.getViewMatrix();
    _lightPos = _camera.getPosition();

    _shaders[MODELS]->setMat4fv(_ViewMatrix, "ViewMatrix");
    _shaders[MODELS]->setVec3f(_camera.getPosition(), "cameraPos");
    //light related, for_now_there, these should be attributes of Material or Light classes
    /*_shaders[MODELS]->setVec3f(_lightPos, "light.position");
    _shaders[MODELS]->setVec3f(glm::vec3(1.0f), "light.ambient");
    _shaders[MODELS]->setVec3f(glm::vec3(0.5f), "light.diffuse");
    _shaders[MODELS]->setVec3f(glm::vec3(1.0f), "light.specular");
    _shaders[MODELS]->set1f(32.f, "light.shininess");
    _shaders[MODELS]->set1f(1.0f, "light.constant");
    _shaders[MODELS]->set1f(0.027f, "light.linear");
    _shaders[MODELS]->set1f(0.0028f, "light.quadratic");*/
	_shaders[MODELS]->setVec3f(glm::vec3(10.f, 13.f, 4.f), "light.lightDir");
	_shaders[MODELS]->set1f(light, "light.light");
	_shaders[MODELS]->set1f(ambient, "light.ambient");
    //end for_now_there
    //Update framebuffer size and projection matrix (usefull when resizing window)
    glfwGetFramebufferSize(_window, &_frameBuffWidth, &_frameBuffHeight);

    _ProjMatrix = glm::perspective(
                      glm::radians(_fov),
                      static_cast<float>(_frameBuffHeight) / _frameBuffHeight,
                      _nearPlane,
                      _farPlane
                  );

    _shaders[MODELS]->setMat4fv(_ProjMatrix, "ProjMatrix");
}

void Game::initGLFW() {
    if (glfwInit() == GL_FALSE) {
        std::cout << "eror glfw init" << std::endl;
    }
}

void Game::initWindow(const char *title, bool resizable) {
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    _window = glfwCreateWindow(W_WIDTH, W_HEIGHT, title, nullptr, nullptr);

    if (_window == nullptr) {
        std::cout << "eror window create" << std::endl;
        glfwTerminate();
    }

    glfwGetFramebufferSize(_window, &_frameBuffWidth, &_frameBuffHeight);
    //glfwSetFramebufferSizeCallback(_window, Game::framebuffer_resize_callback);
    glViewport(0, 0, _frameBuffWidth, _frameBuffHeight);
    glfwMakeContextCurrent(_window);
}

void Game::initGLEW() {
    glewExperimental = true;
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        std::cout << "eror glew init" << std::endl;
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
}

void Game::initOpenGLOptions() {
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    // myszka
    glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glFogi(GL_FOG_COORD_SRC, GL_FRAGMENT_DEPTH);
}

void Game::initMatrices() {
    _ViewMatrix = glm::mat4(1.f);
    // https://stackoverflow.com/questions/21830340/understanding-glmlookat
    _ViewMatrix = glm::lookAt(_camPos, _camPos + _camFront, _worldUp);

    _ProjMatrix = glm::mat4(1.f);
    _ProjMatrix = glm::perspective(
                      glm::radians(_fov),
                      static_cast<float>(_frameBuffWidth) / _frameBuffHeight,
                      _nearPlane,
                      _farPlane
                  );
}

void Game::initShaders() {
    _shaders.push_back(new ShaderProgram("Light.Vertex", "Light.Fragment"));
    _shaders.push_back(new ShaderProgram("Shader.Vertex", "Shader.Fragment"));
    //_shader->Use();
}

void Game::initModels(Group &root) {
    root.addModel(*(new Cabin()));
    root.addModel(*(new Boiler()));
	Chimney *chimney = new Chimney();
	chimney->move(glm::vec3(7.f, 15.f, 7.f));
	chimney->setOrigin(glm::vec3(7.f, 15.f, 7.f));
	chimney->rotate(glm::vec3(0.f, 0.f, 90.f));
	root.addModel(*chimney);
	root.addModel(*(new BlackBox()));
	Spotlight *spotlight = new Spotlight();
	spotlight->move(glm::vec3(4.f, 12.5f, 7.f));
	spotlight->setOrigin(glm::vec3(4.f, 12.5f, 7.f));
	spotlight->rotate(glm::vec3(0.f, 0.f, 180.f));
	root.addModel(*spotlight);
	root.addModel(*(new ChassisBox()));
	root.addModel(*(new FrontBuffer()));
	SideBuffer *leftBuffer = new SideBuffer();
	leftBuffer->move(glm::vec3(2.f, 2.5f, 1.5f));
	leftBuffer->setOrigin(glm::vec3(2.f, 2.5f, 1.5f));
	leftBuffer->rotate(glm::vec3(-90.f, 0.f, 0.f));
	root.addModel(*leftBuffer);
	SideBuffer *rightBuffer = new SideBuffer();
	rightBuffer->move(glm::vec3(4.f, 2.5f, 14.5f));
	rightBuffer->setOrigin(glm::vec3(4.f, 2.5f, 14.5f));
	rightBuffer->rotate(glm::vec3(-90.f, 0.f, 90.f));
	root.addModel(*rightBuffer);
	root.addModel(*(new Bumpers()));

	root.move(glm::vec3(0.f, 0.5f, 0.f));
}

void Game::initHighPistons(Group &higherPistons) {
	Piston *firstPiston = new Piston();
	firstPiston->move(glm::vec3(9.4f, 1.8f, 0.2f));
	firstPiston->setOrigin(glm::vec3(9.4f, 1.8f, 0.2f));
	Piston *secondPiston = new Piston();
	secondPiston->move(glm::vec3(21.4f, 1.8f, 0.2f));
	secondPiston->setOrigin(glm::vec3(21.4f, 1.8f, 0.2f));
	Piston *thirdPiston = new Piston();
	thirdPiston->move(glm::vec3(9.4f, 1.8f, 12.5f));
	thirdPiston->setOrigin(glm::vec3(9.4f, 1.8f, 12.5f));
	Piston *fourthPiston = new Piston();
	fourthPiston->move(glm::vec3(21.4f, 1.8f, 12.5f));
	fourthPiston->setOrigin(glm::vec3(21.4f, 1.8f, 12.5f));

	higherPistons.addModel(*firstPiston);
	higherPistons.addModel(*secondPiston);
	higherPistons.addModel(*thirdPiston);
	higherPistons.addModel(*fourthPiston);

	higherPistons.move(glm::vec3(0.f, 0.5f, 0.f));
}

void Game::initWheels(Group &rightFrontWheel, Group &leftFrontWheel, Group &rightMiddleFirstWheel, Group &leftMiddleFirstWheel, Group &rightMiddleSecondWheel, Group &leftMiddleSecondWheel, Group &rightBackWheel, Group &leftBackWheel) {
	Wheel *rightFrontWheelModel = new Wheel();
	rightFrontWheelModel->move(glm::vec3(9.f, 2.5f, 1.4f));
	rightFrontWheelModel->setOrigin(glm::vec3(9.f, 2.5f, 1.4f));
	rightFrontWheelModel->rotate(glm::vec3(0.f, 90.f, 0.f));

	Wheel *rightMiddleFirstWheelModel = new Wheel();
	rightMiddleFirstWheelModel->move(glm::vec3(15.f, 2.5f, 1.4f));
	rightMiddleFirstWheelModel->setOrigin(glm::vec3(15.f, 2.5f, 1.4f));
	rightMiddleFirstWheelModel->rotate(glm::vec3(0.f, 90.f, 0.f));

	Wheel *rightMiddleSecondWheelModel = new Wheel();
	rightMiddleSecondWheelModel->move(glm::vec3(21.f, 2.5f, 1.4f));
	rightMiddleSecondWheelModel->setOrigin(glm::vec3(21.f, 2.5f, 1.4f));
	rightMiddleSecondWheelModel->rotate(glm::vec3(0.f, 90.f, 0.f));

	Wheel *rightBackWheelModel = new Wheel();
	rightBackWheelModel->move(glm::vec3(29.f, 2.5f, 1.4f));
	rightBackWheelModel->setOrigin(glm::vec3(29.f, 2.5f, 1.4f));
	rightBackWheelModel->rotate(glm::vec3(0.f, 90.f, 0.f));

	Wheel *leftFrontWheelModel = new Wheel();
	leftFrontWheelModel->move(glm::vec3(9.f, 2.5f, 13.2f));
	leftFrontWheelModel->setOrigin(glm::vec3(9.f, 2.5f, 13.2f));
	leftFrontWheelModel->rotate(glm::vec3(0.f, 90.f, 0.f));

	Wheel *leftMiddleFirstWheelModel = new Wheel();
	leftMiddleFirstWheelModel->move(glm::vec3(15.f, 2.5f, 13.2f));
	leftMiddleFirstWheelModel->setOrigin(glm::vec3(15.f, 2.5f, 13.2f));
	leftMiddleFirstWheelModel->rotate(glm::vec3(0.f, 90.f, 0.f));

	Wheel *leftMiddleSecondWheelModel = new Wheel();
	leftMiddleSecondWheelModel->move(glm::vec3(21.f, 2.5f, 13.2f));
	leftMiddleSecondWheelModel->setOrigin(glm::vec3(21.f, 2.5f, 13.2f));
	leftMiddleSecondWheelModel->rotate(glm::vec3(0.f, 90.f, 0.f));

	Wheel *leftBackWheelModel = new Wheel();
	leftBackWheelModel->move(glm::vec3(29.f, 2.5f, 13.2f));
	leftBackWheelModel->setOrigin(glm::vec3(29.f, 2.5f, 13.2f));
	leftBackWheelModel->rotate(glm::vec3(0.f, 90.f, 0.f));

	rightFrontWheel.addModel(*rightFrontWheelModel);
	rightFrontWheel.addModel(*rightMiddleFirstWheelModel);
	rightFrontWheel.addModel(*rightMiddleSecondWheelModel);
	rightFrontWheel.addModel(*rightBackWheelModel);
	rightFrontWheel.addModel(*leftFrontWheelModel);
	rightFrontWheel.addModel(*leftMiddleFirstWheelModel);
	rightFrontWheel.addModel(*leftMiddleSecondWheelModel);
	rightFrontWheel.addModel(*leftBackWheelModel);

	rightFrontWheel.move(glm::vec3(0.f, 0.5f, 0.f));
}

void Game::initWheelConnectors(Group & wheelConnectors) {
	wheelConnectors.addModel(*(new WheelConnectors()));
	wheelConnectors.move(glm::vec3(0.f, 0.5f, 0.f));
}

void Game::initGround(Group & ground) {
	//ground.addModel(*(new Skybox));
	ground.addModel(*(new Ground()));
	ground.addModel(*(new Tracks()));
}

void Game::initLights() {
    _lightPos = _camera.getPosition();
}


//void Game::initTextures() {
//	return (void)1;
//}
