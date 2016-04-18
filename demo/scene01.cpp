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
	line = new Line();

	// Adding 4 points to the line, to created a square
	line->addPoint(new Point2(-0.5f, -0.5f));
	line->addPoint(new Point2(0.5f, -0.5f));
	line->addPoint(new Point2(0.5f, 0.5f));
	line->addPoint(new Point2(-0.5f, 0.5f));

	// Add the child to the this scene
	this->addChild(line);
}


Scene01::~Scene01()
{
}
