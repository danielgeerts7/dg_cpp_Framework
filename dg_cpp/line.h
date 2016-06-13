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
	void addPoint(Point2 point) { points_vector.push_back(point.x);  points_vector.push_back(point.y);  points_vector.push_back(0.0f); }
	
	std::vector<GLfloat> getPointsGLfloat() { return points_vector; }
	std::vector<Point2> getPointsPoint2();
	GLuint GetVertexbuffer() { return vertexbuffer; }

	void BindPoints();

	void CreateCircle(int radius, int segments);
	void CreateSquare(int scaleX, int scaleY);
	int GetCircleRadius() { return Radius; };

	int GetSquareWidth() { return Width; };
	int GetSquareHeight() { return Height; };

	bool filled;

private:
	// List of all points
	std::vector<GLfloat> points_vector;
	GLuint vertexbuffer;
	int Radius = 0;
	int Width = 0;
	int Height = 0;
};

#endif /* LINE_H */