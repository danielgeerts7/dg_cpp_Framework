/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

// Include standard c++ classes
#include <vector>
#include <thread>
#include <string>

// Include all dg_cpp classes needed in this class
#include <dg_cpp/renderer.h>

// Include all demo classes needed in this class
#include <demo/scene01.h>
#include <demo/box2ddemo.h>

int running = 1;

int main(void)
{
	//Check if demo works, press ESC to kill the application
	//Box2Ddemo demoTest;
	//demoTest.TestBox2D();
	
	Renderer* renderer = new Renderer();
	Scene* scene01 = new Scene01(renderer->getCurrentWindow());
	int currentScene = 0;

	std::vector<Scene*> allScenes;
	allScenes.push_back(scene01);

	while (running == 1) {
		// Update every frame the current Scene in renderer
		renderer->RenderScene(allScenes[currentScene]);

		// If Escape is pressed or red X button is clicked then return
		if (glfwGetKey(renderer->getCurrentWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(renderer->getCurrentWindow()) != 0) {
			running = 0;
		}
	}

	// Clean and Terminate the screen
	renderer->CleanAndTerminateWindow();

	if (renderer != NULL) {
		delete(renderer);
		renderer = NULL;
	}

	int sceneSize = allScenes.size();
	for (int i = 0; i < sceneSize; i++) {
		if (allScenes[i] != NULL) {
			delete(allScenes[i]);
			allScenes[i] = NULL;
		}
	}

	return 0;
}