/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#include "gameobject.h"


GameObject::GameObject() : Line()
{
	Position = Point2(0.0f, 0.0f);
	Rotation = 0.0f;
	Scale = Point2(1.0f, 1.0f);

	// Set (default) color to white
	Color = Point3(255, 255, 255);
}

GameObject::~GameObject()
{
}