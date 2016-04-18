/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

// Include standard c++ classes
#include <vector>

// Include all dg_cpp classes needed in this class
#include <dg_cpp/renderer.h>

// Include all demo classes needed in this class
#include <demo/scene01.h>

int main( void )
{
	Renderer* renderer = new Renderer();
	Scene* scene01 = new Scene01();

	std::vector<Scene*> allScenes;
	allScenes.push_back(scene01);

	int running = 1;
	while (running == 1) {
		// Update every frame the current Scene in renderer
		renderer->RenderScene(allScenes[0]);

		// If Escape is pressed or red X button is clicked then return
		if (glfwGetKey(renderer->getCurrentWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(renderer->getCurrentWindow()) != 0) {
			running = 0;
		}
	}

	// Clean and Terminate the screen
	renderer->CleanAndTerminateWindow();

	return 0;
}
