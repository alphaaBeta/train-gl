#include "Game.h"

int main() {

	float dt = 0.f;
	float currTime = 0.f;
	float lastTime = 0.f;


	Game game("openGL", 800, 600, false);

	while (!game.getWindowShouldClose()) {

		currTime = static_cast<float>(glfwGetTime());
		dt = currTime - lastTime;
		lastTime = currTime;

		game.update(dt);
		game.render();
	}
}