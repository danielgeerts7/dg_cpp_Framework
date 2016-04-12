/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#ifndef LINE_H
#define LINE_H

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <vector>

#include <dg_cpp/pointx.h>

class Line
{
public:
	Line();
	~Line();

	// Add a point to the points list
	void addPoint(float posX, float posY ) { points_vector.push_back(posX);  points_vector.push_back(posY);  points_vector.push_back(0.0f); }
	
	std::vector<GLfloat> getPoints() { return points_vector; }
	std::vector<GLfloat> getPointsAsArray();

private:
	// List of all points
	std::vector<GLfloat> points_vector;
};

#endif /* LINE_H */