/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Dani�l Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#ifndef RENDERER_H
#define RENDERER_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <thread>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/transform.hpp>

// Include all dg_cpp classes needed in this class
#include <dg_cpp/shader.h>
#include <dg_cpp/camera.h>
#include <dg_cpp/scene.h>
#include <dg_cpp/line.h>
#include <dg_cpp/settings.h>

class Renderer
{
public:
	Renderer();
	~Renderer();

	void RenderScene(Scene* scene);
	void CleanAndTerminateWindow();

	GLFWwindow* getCurrentWindow() { return _window; }

private:
	void RenderGameObject(glm::mat4& modelMatrix, GameObject* gameobject, Scene* scene);
	void RenderLine(Line* line);

	glm::mat4 _getModelMatrix(GameObject * gameobject);

	void showFrameRate(float numsecs);

	double _calculateDeltaTime();
	double _deltaTime = 0; ///< @brief deltaTime member

	GLFWwindow* _window;

	GLuint programID;
	GLuint vertexPosition_modelspaceID;
	GLuint vertexUVID;
	GLuint matrixID;

	glm::mat4 ViewMatrix;

	GLuint blendColorID;

	glm::mat4 ProjectionMatrix;
};

#endif /* RENDERER_H */
