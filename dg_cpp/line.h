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
	void addPoint(Point2* newPoint) { points.push_back(newPoint); }

private:
	// List of all points
	std::vector<Point2*> points;
};

#endif /* LINE_H */