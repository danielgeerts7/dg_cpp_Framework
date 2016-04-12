/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#include "renderer.h"


Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

int Renderer::InitRenderer() {
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2); // OpenGL 2 version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	// Open a window and create its OpenGL context
	_window = glfwCreateWindow(window_width, window_height, "dg_cpp", NULL, NULL);
	if (_window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(_window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
}

void Renderer::RenderScene(Scene* scene)
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Render every line that scene has
	int size = scene->GetAllLines().size();
	for (int i = 0; i < size; i++) {
		Line* templine = scene->GetAllLines()[i];
		std::vector<GLfloat> test = templine->getPointsAsArray();
		int size = templine->getPointsAsArray().size();

		GLfloat* arr_vec;

		if (size == 6) {
			static GLfloat vec_to_array[] = {
				test[0], test[1], test[2],
				test[3], test[4], test[5],
			};

			arr_vec = vec_to_array;
		} else if (size == 9) {
			static GLfloat vec_to_array[] = {
				test[0], test[1], test[2],
				test[3], test[4], test[5],
				test[6], test[7], test[8],
			};

			arr_vec = vec_to_array;
		} else if (size == 12) {
			static GLfloat vec_to_array[] = {
				test[0], test[1], test[2],
				test[3], test[4], test[5],
				test[6], test[7], test[8],
				test[9], test[10], test[11],
			};

			arr_vec = vec_to_array;
		}

		static GLfloat g_vertex_buffer_data[] = {
			-1.0f, -1.0f, 0.0f,
			1.0f, -1.0f, 0.0f,
			0.0f,  1.0f, 0.0f,
		};

		glGenBuffers(1, &vertexbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		//glBufferData(GL_ARRAY_BUFFER, sizeof(arr_vec), arr_vec, GL_STATIC_DRAW);
		glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

		// Now render each line
		RenderLines(templine);
		
		if (templine != NULL) {
			templine->~Line();
			templine = NULL;
		}
	}

	// Swap buffers
	glfwSwapBuffers(_window);
	glfwPollEvents();
}


void Renderer::RenderLines(Line * line)
{
	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
		);
	// Draw the triangle !
	glDrawArrays(GL_LINE_LOOP, 0, 9 / 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
	glDisableVertexAttribArray(0);
}


void Renderer::CleanAndTerminateWindow() {
	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}