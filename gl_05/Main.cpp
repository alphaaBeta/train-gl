#include "Game.h"
#include "Config.h"

int main() {

    float dt = 0.f;
    float currTime = 0.f;
    float lastTime = 0.f;


    Game game("openGL", Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT, false);

    while (!game.getWindowShouldClose()) {

        currTime = static_cast<float>(glfwGetTime());
        dt = currTime - lastTime;
        lastTime = currTime;

        game.update(dt);
        game.render();
    }
}