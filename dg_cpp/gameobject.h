/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <dg_cpp/line.h>
#include <dg_cpp/pointx.h>

class GameObject : public Line
{
public:
	GameObject();
	~GameObject();

	Point2 Position;
	float Rotation;
	Point2 Scale;

	Point3 Color;
};

#endif /* GAMEOBJECT_H */