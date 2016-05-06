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

	Color = new Point3(255, 255, 255);
}

GameObject::~GameObject()
{
	if (Position != NULL) {
		delete(Position);
		Position = NULL;
	}
	if (Scale != NULL) {
		delete(Scale);
		Scale = NULL;
	}
}