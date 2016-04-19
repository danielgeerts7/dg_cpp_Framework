/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#include "gameobject.h"


GameObject::GameObject() : Line()
{
	Position = new Point2(0.0f, 0.0f);
	Rotation = 0.0f;
	Scale = new Point2(1.0f, 1.0f);
}

GameObject::~GameObject()
{
}