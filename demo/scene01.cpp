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
	circle_1 = new GameObject();

	// Calling CreateCircle to create a circle for circle_1
	circle_1->CreateCircle(100, 6);

	circle_1->Position = Point2(300.0f, 150.0f);
	circle_1->Rotation = 0.0f;
	circle_1->Scale = Point2(1.0f, 1.0f);

	circle_1->Color = Point3(255, 255, 0);
	circle_1->filled = false;

	// Add the child to the this scene
	this->addChild(circle_1);

	// Creating a new Line
	circle_2 = new GameObject();

	// Calling CreateCircle to create a circle for circle_2
	circle_2->CreateCircle(100, 12);

	circle_2->Position = Point2(1000.0f, 500.0f);
	circle_2->Rotation = 0.0f;
	circle_2->Scale = Point2(1.0f, 1.0f);

	circle_2->Color = Point3(0, 0, 255);
	circle_2->filled = true;

	// Add the child to the this scene
	this->addChild(circle_2);

	// Creating a new Line
	circle_3 = new GameObject();

	// Calling CreateCircle to create a circle for circle_3
	circle_3->CreateCircle(100, 16);

	circle_3->Position = Point2(900.0f, 150.0f);
	circle_3->Rotation = 0.0f;
	circle_3->Scale = Point2(1.0f, 1.0f);

	circle_3->Color = Point3(0, 255, 0);
	circle_3->filled = false;

	// Add the child to the this scene
	this->addChild(circle_3);

	// Creating a new Line
	circle_4 = new GameObject();

	// Calling CreateCircle to create a circle for circle_4
	circle_4->CreateCircle(100, 24);

	circle_4->Position = Point2(250.0f, 550.0f);
	circle_4->Rotation = 0.0f;
	circle_4->Scale = Point2(1.0f, 1.0f);

	circle_4->Color = Point3(255, 0, 0);
	circle_4->filled = false;

	// Add the child to the this scene
	this->addChild(circle_4);

	allLocalGameObjects.push_back(square);
	allLocalGameObjects.push_back(circle_1);
	allLocalGameObjects.push_back(circle_2);
	allLocalGameObjects.push_back(circle_3);
	allLocalGameObjects.push_back(circle_4);
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