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
	square = new GameObject();

	// Adding 4 points to the line, to created a square
	square->addPoint(Point2(-100.0f, -100.0f));
	square->addPoint(Point2(100.0f, -100.0f));
	square->addPoint(Point2(100.0f, 100.0f));
	square->addPoint(Point2(-100.0f, 100.0f));

	square->Position = Point2(600.0f, 400.0f);
	square->Rotation = 0.0f;
	square->Scale = Point2(1.0f, 1.0f);

	square->Color = Point3(0, 255, 255);
	square->filled = true;

	// Add the child to the this scene
	this->addChild(square);

	// Creating a new Line
	pentagram = new GameObject();

	// Adding some points to the line, to created a pentagram
	pentagram->addPoint(Point2(0.0f, -110.0f));
	pentagram->addPoint(Point2(60.0f, 80.0f));
	pentagram->addPoint(Point2(-100.0f, -40.0f));
	pentagram->addPoint(Point2(100.0f, -40.0f));
	pentagram->addPoint(Point2(-60.0f, 80.0f));

	pentagram->Position = Point2(300.0f, 150.0f);
	pentagram->Rotation = 0.0f;
	pentagram->Scale = Point2(1.0f, 1.0f);

	pentagram->Color = Point3(255, 255, 0);
	pentagram->filled = false;

	// Add the child to the this scene
	this->addChild(pentagram);

	// Creating a new Line
	triangle = new GameObject();

	// Adding some points to the line, to created a star
	triangle->addPoint(Point2(0.0f, -100.0f));
	triangle->addPoint(Point2(-100.0f, 100.0f));
	triangle->addPoint(Point2(100.0f, 100.0f));

	triangle->Position = Point2(1000.0f, 500.0f);
	triangle->Rotation = 0.0f;
	triangle->Scale = Point2(1.0f, 1.0f);

	triangle->Color = Point3(0, 0, 255);
	triangle->filled = true;

	// Add the child to the this scene
	this->addChild(triangle);

	// Creating a new Line
	circle = new GameObject();

	// Adding some points to the line, to created a star
	circle->addPoint(Point2(0.0f, -100.0f));
	circle->addPoint(Point2(75.0f, -75.0f));
	circle->addPoint(Point2(100.0f, 0.0f));
	circle->addPoint(Point2(75.0f, 75.0f));
	circle->addPoint(Point2(0.0f, 100.0f));
	circle->addPoint(Point2(-75.0f, 75.0f));
	circle->addPoint(Point2(-100.0f, 0.0f));
	circle->addPoint(Point2(-75.0f, -75.0f));

	circle->Position = Point2(900.0f, 150.0f);
	circle->Rotation = 0.0f;
	circle->Scale = Point2(1.0f, 1.0f);

	circle->Color = Point3(0, 255, 0);
	circle->filled = false;

	// Add the child to the this scene
	this->addChild(circle);

	// Creating a new Line
	star = new GameObject();

	// Adding some points to the line, to created a star
	star->addPoint(Point2(0.0f, -100.0f));
	star->addPoint(Point2(25.0f, -25.0f));
	star->addPoint(Point2(100.0f, 0.0f));
	star->addPoint(Point2(25.0f, 25.0f));
	star->addPoint(Point2(0.0f, 100.0f));
	star->addPoint(Point2(-25.0f, 25.0f));
	star->addPoint(Point2(-100.0f, 0.0f));
	star->addPoint(Point2(-25.0f, -25.0f));

	star->Position = Point2(250.0f, 550.0f);
	star->Rotation = 0.0f;
	star->Scale = Point2(1.0f, 1.0f);

	star->Color = Point3(255, 0, 0);
	star->filled = false;

	// Add the child to the this scene
	this->addChild(star);

	allLocalGameObjects.push_back(square);
	allLocalGameObjects.push_back(pentagram);
	allLocalGameObjects.push_back(triangle);
	allLocalGameObjects.push_back(circle);
	allLocalGameObjects.push_back(star);
}


Scene01::~Scene01()
{
	// Delete and clear the 'allGameObjects' Vector
	int allGameObjsize = allLocalGameObjects.size();
	for (int i = 0; i < allGameObjsize; i++) {
		if (allLocalGameObjects[i] != NULL) {
			delete (allLocalGameObjects[i]);
			allLocalGameObjects[i] = NULL;
		}
	}
	allLocalGameObjects.clear();
}

void Scene01::update(float deltaTime) {
	Scene::update(deltaTime);
}