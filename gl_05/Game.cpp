#include "Game.h"
#include "Group.h"
#include "Cabin.h"

void Game::initUniforms() {
    _shader->setMat4fv(_ViewMatrix, "ViewMatrix");
    _shader->setMat4fv(_ProjMatrix, "ProjectionMatrix");
}

Game::Game(const char *title, const int width, const int height, bool resizable = false) : W_WIDTH(width), W_HEIGHT(height), _camera(glm::vec3(19.f, 26.f, 10.f), glm::vec3(0.f, 1.f, 0.f)) {
    _window = nullptr;
    _frameBuffWidth = W_WIDTH;
    _frameBuffHeight = W_HEIGHT;

    _camPos = glm::vec3(19.f, 26.f, 10.f);
    _worldUp = glm::vec3(0.f, 1.f, 0.f);
    _camFront = glm::vec3(0.f, 0.f, -1.f);

    _fov = 45.f;
    _nearPlane = 0.1f;
    _farPlane = 1000.f;

	Group* workspace = new Group();

	_objects.push_back(workspace);

    initGLFW();
    initWindow(title, resizable);
    initGLEW();
    initOpenGLOptions();

    initMatrices();
    initShaders();

	
    //initTextures();
    //initMaterials();
    initModels(*workspace);
    //initLights();
    initUniforms();

}

Game::~Game() {
    glfwDestroyWindow(_window);
    glfwTerminate();

    delete _shader;

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

    /*for (const auto &i : _objects) {
        i->rotate(glm::vec3(0.0f, 0.1f, 0.0f));
    }*/

    updateKeyInput(dt);
    updateMouseInput();
    _camera.updateMouseInput(dt, _mouseOffsetX, _mouseOffsetY);
}

void Game::render() {
    glClearColor(0.f, 0.f, 0.f, 1.f);
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

    _shader->setMat4fv(_ViewMatrix, "ViewMatrix");
    _shader->setVec3f(_camera.getPosition(), "cameraPos");

    //Update framebuffer size and projection matrix (usefull when resizing window)
    glfwGetFramebufferSize(_window, &_frameBuffWidth, &_frameBuffHeight);

    _ProjMatrix = glm::perspective(
                      glm::radians(_fov),
                      static_cast<float>(_frameBuffHeight) / _frameBuffHeight,
                      _nearPlane,
                      _farPlane
                  );

    _shader->setMat4fv(_ProjMatrix, "ProjMatrix");
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
    _shader = new ShaderProgram("Shader.Vertex", "Shader.Fragment");
	_shader->Use();
}

void Game::initModels(Group& root)
{
	root.addModel(*(new Cabin()));
}


//void Game::initTextures() {
//	return (void)1;
//}
