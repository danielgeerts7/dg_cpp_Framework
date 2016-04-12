/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#include "line.h"


Line::Line()
{
}


Line::~Line()
{
}
// from vector to array
std::vector<GLfloat> Line::getPointsAsArray() {
	/*
	int size = points_vector.size();
	
	GLfloat* points_array = CreateNewArrayWithRigthSize(size);
	for (int i = 0; i < size; i++) {
		points_array[i] = points_vector[i]->x;
		points_array[i+1] = points_vector[i]->y;
		points_array[i+2] = 0.0f;

		// because i add more then 1 element
		i++;
		i++;
	}

	for (int i = 0; i < size; i++) {
		points_array[i] = points_vector[i];
	}
	

	std::array<GLfloat, size> g_vertex_buffer_data;
	static GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};
	*/

	return points_vector;
	//return array[] temp = points_vector;
}