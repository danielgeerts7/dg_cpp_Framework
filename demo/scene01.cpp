/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#include "scene01.h"


Scene01::Scene01() : Scene()
{
	// Creating a new Line
	square = new Line();

	// Adding 4 points to the line, to created a square
	square->addPoint(new Point2(-0.5f, -0.5f));
	square->addPoint(new Point2(0.5f, -0.5f));
	square->addPoint(new Point2(0.5f, 0.5f));
	square->addPoint(new Point2(-0.5f, 0.5f));

	// Add the child to the this scene
	this->addChild(square);

	// Creating a new Line
	pentagram = new Line();

	// Adding some points to the line, to created a pentagram
	pentagram->addPoint(new Point2(0.0f, 0.5f));
	pentagram->addPoint(new Point2(0.25f, -0.5f));
	pentagram->addPoint(new Point2(-0.5f, 0.25f));
	pentagram->addPoint(new Point2(0.5f, 0.25f));
	pentagram->addPoint(new Point2(-0.25f, -0.5f));

	// Add the child to the this scene
	this->addChild(pentagram);

	// Creating a new Line
	triangle = new Line();

	// Adding some points to the line, to created a star
	triangle->addPoint(new Point2(-0.5f, -0.5f));
	triangle->addPoint(new Point2(0.5f, -0.5f));
	triangle->addPoint(new Point2(0.0f, 0.5f));

	// Add the child to the this scene
	this->addChild(triangle);
}


Scene01::~Scene01()
{
}
