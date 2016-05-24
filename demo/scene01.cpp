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
	square = new GameObject(STATIC);

	// Adding 4 points to the line, to created a square
	square->addPoint(Point2(-100.0f, -100.0f));
	square->addPoint(Point2(100.0f, -100.0f));
	square->addPoint(Point2(100.0f, 100.0f));
	square->addPoint(Point2(-100.0f, 100.0f));

	square->Position = Point2(800.0f, 400.0f);
	square->Rotation = 25.0f / RAD_TO_DEG;
	square->Scale = Point2(1.0f, 1.0f);

	square->Color = Point3(0, 255, 255);
	square->filled = true;

	// Add the child to the this scene
	this->addChild(square);

	// Creating a new Line
	circle_1 = new GameObject(STATIC);

	// Calling CreateCircle to create a circle for circle_1
	circle_1->CreateCircle(100, 3);

	circle_1->Position = Point2(400.0f, 400.0f);
	circle_1->Rotation = 180.0f / RAD_TO_DEG;
	circle_1->Scale = Point2(1.0f, 1.0f);

	circle_1->Color = Point3(255, 255, 0);
	circle_1->filled = true;

	// Add the child to the this scene
	this->addChild(circle_1);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 40; j++) {
			GameObject* temp = new GameObject(DYNAMIC);

			temp->CreateCircle(10, 8);
			temp->Position = Point2(0.0f + (30.0f * j), 30.0f * i);
			temp->Rotation = 0.0f;
			temp->Scale = Point2(1.0f, 1.0f);
			int col1 = rand() % 255 + 1;
			int col2 = rand() % 255 + 1;
			int col3 = rand() % 255 + 1;
			temp->Color = Point3(col1, col2, col3);
			temp->filled = true;
			
			this->addChild(temp);
			temp->body->SetGravityScale(100.0f);
			//temp->body->SetActive(false);
			allLocalGameObjects.push_back(temp);
		}
	}

	allLocalGameObjects.push_back(square);
	allLocalGameObjects.push_back(circle_1);
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