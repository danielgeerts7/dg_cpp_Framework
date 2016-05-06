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

	allGameObjects.push_back(square);
	allGameObjects.push_back(pentagram);
	allGameObjects.push_back(triangle);
	allGameObjects.push_back(circle);
	allGameObjects.push_back(star);

	for each (GameObject* var in allGameObjects) {
		allBounceSpeeds.push_back(new Point2(0.2f, 0.3f));
	}

	pentagram_speed = new Point2(0.25f, 0.0f);
}


Scene01::~Scene01()
{
	int size = allGameObjects.size();
	for (int i = 0; i < size; i++) {
		if (allGameObjects[i] != NULL) {
			delete (allGameObjects[i]);
			allGameObjects[i] = NULL;
		}
	}
	if (pentagram_speed != NULL) {
		delete (pentagram_speed);
		pentagram_speed = NULL;
	}
}

void Scene01::update(float deltaTime) {
	Scene::update(deltaTime);

	int size = allGameObjects.size();
	for (int i = 0; i < size; i++) {
		if (allGameObjects[i]->Position->x >= 1280 - 100) {
			allBounceSpeeds[i]->x = allBounceSpeeds[i]->x * -1;
		}
		else if (allGameObjects[i]->Position->x <= 0 + 100) {
			allBounceSpeeds[i]->x = allBounceSpeeds[i]->x * -1;
		}
		else if (allGameObjects[i]->Position->y >= 720 - 100) {
			allBounceSpeeds[i]->y = allBounceSpeeds[i]->y * -1;
		}
		else if (allGameObjects[i]->Position->y <= 0 + 100) {
			allBounceSpeeds[i]->y = allBounceSpeeds[i]->y * -1;
		}

		allGameObjects[i]->Position->x += allBounceSpeeds[i]->x;
		allGameObjects[i]->Position->y += allBounceSpeeds[i]->y;

		allGameObjects[i]->Rotation += 0.003;
	}
}