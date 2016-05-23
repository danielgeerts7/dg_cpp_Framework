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

	bodyDef.type = b2_dynamicBody;
	dynamicBox.SetAsBox(100.0f, 100.0f);

	fixtureDef.shape = &dynamicBox;
	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;
	// Override the default friction.
	fixtureDef.friction = 0.5f;
}

GameObject::~GameObject()
{
}