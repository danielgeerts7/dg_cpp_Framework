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
	_window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "dg_cpp", NULL, NULL);
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

	// Make variable ModelMatrix
	ViewMatrix = getViewMatrix();

	ProjectionMatrix = glm::ortho(0.0f, (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT, 0.0f, 0.1f, 100.0f);
}

Renderer::~Renderer()
{
}

void Renderer::RenderScene(Scene* scene)
{
	// Calculate deltaTime
	_calculateDeltaTime();

	// Show deltaTime
	showFrameRate(1);

	if (scene->CanStartBox2D == true) {
		static double vsync = 1.0f / 60.0f;
		scene->world.Step(vsync, 8, 3);
	}

	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Update scene
	scene->update(_deltaTime);
	ViewMatrix = getViewMatrix();

	// Render every line that scene has
	int size = scene->ChildrenInScene.size();

	// Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
	computeMatricesFromInputs(_window);

	// Use our shader
	glUseProgram(programID);

	for (int i = 0; i < size; i++) {
		// Get a single GameObject
		glm::mat4 modelMatrix = glm::mat4(1.0f);
		GameObject* gameobj = scene->ChildrenInScene[i];
		this->RenderGameObject(modelMatrix, gameobj, scene);
	}

	// Swap buffers
	glfwSwapBuffers(_window);
	glfwPollEvents();
}

void Renderer::RenderGameObject(glm::mat4& modelMatrix, GameObject* gameobject, Scene* currentScene) {
	modelMatrix *= this->_getModelMatrix(gameobject);

	// generate the ModelMatrix
	glm::mat4 MVP = ProjectionMatrix * ViewMatrix * modelMatrix;

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

	// _blendColorID
	glUniform4f(blendColorID, (float)gameobject->Color.x / 255.0f, (float)gameobject->Color.y / 255.0f, (float)gameobject->Color.z / 255.0f, 1.0f);


	// Now render each line
	RenderLine(gameobject);
}

void Renderer::RenderLine(Line * line)
{
	// Get size of vector<points>
	// Divide the whole size by 3 ( x,y,z )
	int size = line->getPointsGLfloat().size() / 3;

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

	// Draw only a line !
	glDrawArrays(GL_LINE_LOOP, 0, size); // Starting from vertex 0; size is the size of points that the line has
	if (line->filled) {
		// Draw a filled object from line !
		glDrawArrays(GL_POLYGON, 0, size); // Starting from vertex 0; size is the size of points that the line has
	}
	glDisableVertexAttribArray(0);
}

glm::mat4 Renderer::_getModelMatrix(GameObject* gameobject)
{
	// OpenGL doesn't understand our Vector2. Make it glm::vec3 compatible.
	glm::vec3 position = glm::vec3(gameobject->Position.x, gameobject->Position.y, 0.0f);
	glm::vec3 rotation = glm::vec3(0.0f, 0.0f, gameobject->Rotation);
	glm::vec3 scale = glm::vec3(gameobject->Scale.x, gameobject->Scale.y, 1.0f);

	// Build the Model matrix
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), position);
	glm::mat4 rotationMatrix = glm::eulerAngleYXZ(0.0f, 0.0f, rotation.z);
	glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), scale);

	glm::mat4 mm = translationMatrix * rotationMatrix * scalingMatrix;

	return mm;
}

void Renderer::showFrameRate(float numsecs)
{
	static int frames = 0;
	static double time = 0;

	frames++;
	time += _deltaTime;
	if (time >= numsecs) {
		printf("%f ms/frame (%f FPS)\n", (numsecs * 1000) / double(frames), frames / numsecs);
		frames = 0;
		time = 0;
	}
}

double Renderer::_calculateDeltaTime()
{
	static double lastTime = glfwGetTime();
	double startTime = glfwGetTime();
	_deltaTime = startTime - lastTime;
	lastTime = startTime;

	return _deltaTime;
}

void Renderer::CleanAndTerminateWindow() {
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}