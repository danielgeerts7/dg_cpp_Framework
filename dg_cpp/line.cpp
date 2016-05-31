/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#include "line.h"


Line::Line()
{
	// Set filled to false (now only render the line)
	filled = false;
}


Line::~Line()
{
	glDeleteBuffers(1, &vertexbuffer);
}

std::vector<Point2> Line::getPointsPoint2()
{
	std::vector<Point2> temp;
	
	int size = points_vector.size();
	for (int i = 0; i < size; i++) {
		temp.push_back(Point2(points_vector[i], points_vector[i+1], points_vector[i+2]));
		i++;
		i++;
	}

	return temp;
}

void Line::BindPoints() {
	glDeleteBuffers(1, &vertexbuffer);

	int size = this->getPointsGLfloat().size();
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->getPointsGLfloat()[0]) * size, &this->getPointsGLfloat()[0], GL_STATIC_DRAW);
}

void Line::CreateCircle(int radius, int segments) {
	Radius = radius;
	int step = 360 / segments;

	for (int i = 0; i < 360; i += step) {
		float x = cos(i*0.0174532925)*radius;
		float y = sin(i*0.0174532925)*radius;
		this->addPoint(Point2(x, y));
	}
	//this->addPoint(Point2(points_vector[0], points_vector[1]));
}

void Line::CreateSquare(int scaleX, int scaleY) {
	this->addPoint(Point2(-scaleX, -scaleY));
	this->addPoint(Point2(scaleX, -scaleY));
	this->addPoint(Point2(scaleX, scaleY));
	this->addPoint(Point2(-scaleX, scaleY));
}