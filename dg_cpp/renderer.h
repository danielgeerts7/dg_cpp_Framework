/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#ifndef RENDERER_H
#define RENDERER_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

// Include all dg_cpp classes needed in this class
#include <dg_cpp/scene.h>
#include <dg_cpp/line.h>

class Renderer
{
public:
	Renderer();
	~Renderer();

	int InitRenderer();

	void RenderScene(Scene* scene);
	void CleanAndTerminateWindow();

	GLFWwindow* getCurrentWindow() { return _window; }

private:
	void RenderLines(Line* line);

	GLFWwindow* _window;

	int window_width = 1280;
	int window_height = 720;
};

#endif /* RENDERER_H */
