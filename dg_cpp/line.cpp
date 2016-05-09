/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Dani�l Geerts <daniel.geerts@live.nl>
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
}

void Line::BindPoints() {
	int size = this->getPoints().size();
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(this->getPoints()[0]) * size, &this->getPoints()[0], GL_STATIC_DRAW);
}