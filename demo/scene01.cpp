/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Dani�l Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#include "scene01.h"


Scene01::Scene01() : Scene()
{
	// Creating a new Line
	square = new GameObject();

	// Adding 4 points to the line, to created a square
	square->addPoint(new Point2(-100.0f, -100.0f));
	square->addPoint(new Point2(100.0f, -100.0f));
	square->addPoint(new Point2(100.0f, 100.0f));
	square->addPoint(new Point2(-100.0f, 100.0f));

	square->Position = new Point2(600.0f, 400.0f);
	square->Rotation = 0.0f;
	square->Scale = new Point2(1.0f, 1.0f);

	// Add the child to the this scene
	this->addChild(square);

	// Creating a new Line
	pentagram = new GameObject();

	// Adding some points to the line, to created a pentagram
	pentagram->addPoint(new Point2(0.0f, -100.0f));
	pentagram->addPoint(new Point2(60.0f, 80.0f));
	pentagram->addPoint(new Point2(-100.0f, -40.0f));
	pentagram->addPoint(new Point2(100.0f, -40.0f));
	pentagram->addPoint(new Point2(-60.0f, 80.0f));

	pentagram->Position = new Point2(300.0f, 150.0f);
	pentagram->Rotation = 0.0f;
	pentagram->Scale = new Point2(1.0f, 1.0f);

	// Add the child to the this scene
	this->addChild(pentagram);

	// Creating a new Line
	triangle = new GameObject();

	// Adding some points to the line, to created a star
	triangle->addPoint(new Point2(0.0f, -100.0f));
	triangle->addPoint(new Point2(-100.0f, 100.0f));
	triangle->addPoint(new Point2(100.0f, 100.0f));

	triangle->Position = new Point2(1000.0f, 500.0f);
	triangle->Rotation = 0.0f;
	triangle->Scale = new Point2(1.0f, 1.0f);

	// Add the child to the this scene
	this->addChild(triangle);

	// Creating a new Line
	circle = new GameObject();

	// Adding some points to the line, to created a star
	circle->addPoint(new Point2(0.0f, -100.0f));
	circle->addPoint(new Point2(75.0f, -75.0f));
	circle->addPoint(new Point2(100.0f, 0.0f));
	circle->addPoint(new Point2(75.0f, 75.0f));
	circle->addPoint(new Point2(0.0f, 100.0f));
	circle->addPoint(new Point2(-75.0f, 75.0f));
	circle->addPoint(new Point2(-100.0f, 0.0f));
	circle->addPoint(new Point2(-75.0f, -75.0f));

	circle->Position = new Point2(900.0f, 150.0f);
	circle->Rotation = 0.0f;
	circle->Scale = new Point2(1.0f, 1.0f);

	// Add the child to the this scene
	this->addChild(circle);

	// Creating a new Line
	star = new GameObject();

	// Adding some points to the line, to created a star
	star->addPoint(new Point2(0.0f, -100.0f));
	star->addPoint(new Point2(25.0f, -25.0f));
	star->addPoint(new Point2(100.0f, 0.0f));
	star->addPoint(new Point2(25.0f, 25.0f));
	star->addPoint(new Point2(0.0f, 100.0f));
	star->addPoint(new Point2(-25.0f, 25.0f));
	star->addPoint(new Point2(-100.0f, 0.0f));
	star->addPoint(new Point2(-25.0f, -25.0f));

	star->Position = new Point2(250.0f, 550.0f);
	star->Rotation = 0.0f;
	star->Scale = new Point2(1.0f, 1.0f);

	// Add the child to the this scene
	this->addChild(star);

	point = new Point2(0.25f, 0.0f);
}


Scene01::~Scene01()
{
	if (square != NULL) {
		delete (square);
		square = NULL;
	}
	if (pentagram != NULL) {
		delete (pentagram);
		pentagram = NULL;
	}
	if (triangle != NULL) {
		delete (triangle);
		triangle = NULL;
	}
	if (circle != NULL) {
		delete (circle);
		circle = NULL;
	}
	if (star != NULL) {
		delete (star);
		star = NULL;
	}
	if (point != NULL) {
		delete (point);
		point = NULL;
	}
}

void Scene01::update(float deltaTime) {
	Scene::update(deltaTime);

	star->Rotation += 0.001;

	if (pentagram->Position->x >= 400) {
		pentagram->Position->x = 399;
		point = new Point2(0.0f, 0.25f);
	} else if (pentagram->Position->y >= 400) {
		pentagram->Position->y = 399;
		point = new Point2(-0.25f, 0.0f);
	} else if (pentagram->Position->x <= 150) {
		pentagram->Position->x = 151;
		point = new Point2(0.0f, -0.25f);
	} else if (pentagram->Position->y <= 150) {
		pentagram->Position->y = 151;
		point = new Point2(0.25f, 0.0f);
	}

	pentagram->Position->x += point->x;
	pentagram->Position->y += point->y;
	pentagram->Rotation += 0.001f;
}