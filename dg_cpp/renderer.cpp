/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#include "renderer.h"


Renderer::Renderer()
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glEnable(GL_MULTISAMPLE); // Enable antialiasing just to be sure
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2); // OpenGL 2 version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	// Open a window and create its OpenGL context
	_window = glfwCreateWindow(window_width, window_height, "dg_cpp", NULL, NULL);
	if (_window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(_window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return;
	}
	
	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	// Create and compile our GLSL program from the shaders
	// see: shader.h/cpp
	programID = loadShaders("shaders/sprite.vert", "shaders/sprite.frag");
	// Use our shader
	glUseProgram(programID);

	// Get a handle for our buffers
	vertexPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");
	vertexUVID = glGetAttribLocation(programID, "vertexUV");

	// Get a handle for our "MVP" uniform
	matrixID = glGetUniformLocation(programID, "MVP");
	blendColorID = glGetUniformLocation(programID, "blendColor"); // blendColor uniform in fragment shader

	ProjectionMatrix = glm::ortho(0.0f, (float)window_width, (float)window_height, 0.0f, 0.1f, 100.0f);
}

Renderer::~Renderer()
{
}

void Renderer::RenderScene(Scene* scene)
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Update scene
	scene->update(1.0f);

	// Render every line that scene has
	int size = scene->GetAllGameObjects().size();

	// Make variable ModelMatrix
	glm::mat4 ViewMatrix = getViewMatrix();
	glm::mat4 ModelMatrix = glm::mat4(1.0f);

	// Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
	computeMatricesFromInputs(_window);

	// Use our shader
	glUseProgram(programID);

	for (int i = 0; i < size; i++) {
		// Get a single GameObject
		GameObject* gameobj = scene->GetAllGameObjects()[i];

		// Build the Model matrix
		glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(gameobj->Position.x, gameobj->Position.y, 0.0f));
		glm::mat4 rotationMatrix = glm::eulerAngleYXZ(0.0f, 0.0f, gameobj->Rotation);
		glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(gameobj->Scale.x, gameobj->Scale.y, 1.0f));

		ModelMatrix = translationMatrix * rotationMatrix * scalingMatrix;

		glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

		// Send our transformation to the currently bound shader,
		// in the "MVP" uniform
		glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

		// _blendColorID
		glUniform4f(blendColorID, (float)gameobj->Color.x / 255.0f, (float)gameobj->Color.y / 255.0f, (float)gameobj->Color.z / 255.0f, 1.0f);

		// Now render each line
		RenderLine(gameobj);
	}

	// Swap buffers
	glfwSwapBuffers(_window);
	glfwPollEvents();
}


void Renderer::RenderLine(Line * line)
{
	// Get size of vector<points>
	// Divide the whole size by 3 ( x,y,z )
	int size = line->getPoints().size() / 3;

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(vertexPosition_modelspaceID);
	glBindBuffer(GL_ARRAY_BUFFER, line->GetVertexbuffer());
	glVertexAttribPointer(
		vertexPosition_modelspaceID,	// attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,								// size
		GL_FLOAT,						// type
		GL_FALSE,						// normalized?
		0,								// stride
		(void*)0						// array buffer offset
		);

	// Check if line needs to be filled or not
	if (line->filled == false) {
		// Draw only a line !
		glDrawArrays(GL_LINE_LOOP, 0, size); // Starting from vertex 0; size is the size of points that the line has
	} else {
		// Draw a filled object from line !
		glDrawArrays(GL_POLYGON, 0, size); // Starting from vertex 0; size is the size of points that the line has
	}
	glDisableVertexAttribArray(0);
}


void Renderer::CleanAndTerminateWindow() {
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}