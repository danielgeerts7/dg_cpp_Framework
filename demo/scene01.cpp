/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#include "scene01.h"


Scene01::Scene01(GLFWwindow* currentWindow) : Scene(currentWindow)
{
	// Creating a new Line
	defaultObj = new GameObject(STATIC);

	// Adding 4 points to the line, to created a defaultObj
	defaultObj->CreateSquare(100, 10);

	defaultObj->Position = Point2(447, 392);
	defaultObj->Rotation = 25.0f / RAD_TO_DEG;
	defaultObj->Scale = Point2(1.0f, 1.0f);

	defaultObj->Color = Point3(0, 255, 255);
	defaultObj->filled = false;

	// Add the child to the this scene
	this->addChild(defaultObj);
	allLocalGameObjects.push_back(defaultObj);

	// Creating a new Line
	defaultObj = new GameObject(STATIC);

	// Adding 4 points to the line, to created a defaultObj
	defaultObj->CreateSquare(100, 10);

	defaultObj->Position = Point2(85, 205);
	defaultObj->Rotation = 15.0f / RAD_TO_DEG;
	defaultObj->Scale = Point2(1.0f, 1.0f);

	defaultObj->Color = Point3(255, 255, 0);
	defaultObj->filled = false;

	// Add the child to the this scene
	this->addChild(defaultObj);
	allLocalGameObjects.push_back(defaultObj);

	// Creating a new Line
	defaultObj = new GameObject(STATIC);

	// Adding 4 points to the line, to created a defaultObj
	defaultObj->CreateSquare(50, 10);

	defaultObj->Position = Point2(650, 500);
	defaultObj->Rotation = 165.0f / RAD_TO_DEG;
	defaultObj->Scale = Point2(1.0f, 1.0f);

	defaultObj->Color = Point3(0, 148, 189);
	defaultObj->filled = false;

	// Add the child to the this scene
	this->addChild(defaultObj);
	allLocalGameObjects.push_back(defaultObj);

	// Creating a new Line
	BasketLeft = new GameObject(STATIC);

	// Adding 4 points to the line, to created a defaultObj
	BasketLeft->CreateSquare(120, 10);

	BasketLeft->Position = Point2(504, 600);
	BasketLeft->Rotation = 90.0f / RAD_TO_DEG;
	BasketLeft->Scale = Point2(1.0f, 1.0f);

	BasketLeft->Color = Point3(255, 140, 0);
	BasketLeft->filled = true;
	this->addChild(BasketLeft);
	allLocalGameObjects.push_back(BasketLeft);

	// Creating a new Line
	BasketRigth = new GameObject(STATIC);

	// Adding 4 points to the line, to created a defaultObj
	BasketRigth->CreateSquare(25, 10);

	BasketRigth->Position = Point2(576, 695);
	BasketRigth->Rotation = 90.0f / RAD_TO_DEG;
	BasketRigth->Scale = Point2(1.0f, 1.0f);

	BasketRigth->Color = Point3(255, 140, 0);
	BasketRigth->filled = true;
	this->addChild(BasketRigth);
	BasketRigth->body->SetGravityScale(2);
	allLocalGameObjects.push_back(BasketRigth);

	// Creating a new Line
	BasketBottom = new GameObject(STATIC);

	// Adding 4 points to the line, to created a defaultObj
	BasketBottom->CreateSquare(25, 10);

	BasketBottom->Position = Point2(540, 710);
	BasketBottom->Rotation = 0.0f / RAD_TO_DEG;
	BasketBottom->Scale = Point2(1.0f, 1.0f);

	BasketBottom->Color = Point3(255, 140, 0);
	BasketBottom->filled = true;

	// Add the child to the this scene
	this->addChild(BasketBottom);
	allLocalGameObjects.push_back(BasketBottom);

	ball = new GameObject(DYNAMIC);

	ball->CreateCircle(10, 10);
	ball->Position = Point2(100, 180);
	ball->Rotation = 0.0f;
	ball->Scale = Point2(1.0f, 1.0f);
	ball->Color = Point3(255, 255, 255);
	ball->filled = false;

	this->addChild(ball);
	ball->body->SetGravityScale(1.0f);
	allLocalGameObjects.push_back(ball);


/** CREATING ALL DRAGGABLE GAME OBJECTS  **/
	// Creating a new Line
	draggableGameObject1 = new DraggableGameObject(Point3(255, 140, 0));

	// Adding 4 points to the line, to created a defaultObj
	draggableGameObject1->CreateSquare(10, 25);

	draggableGameObject1->Position = Point2(50, 50);
	draggableGameObject1->Rotation = 0.0f / RAD_TO_DEG;
	draggableGameObject1->Scale = Point2(1.0f, 1.0f);

	// Add the child to the this scene
	this->addChild(draggableGameObject1);
	allLocalGameObjects.push_back(draggableGameObject1);

	// Creating a new Line
	draggableGameObject2 = new DraggableGameObject(Point3(255, 0, 255));

	// Adding 4 points to the line, to created a defaultObj
	draggableGameObject2->CreateSquare(100, 10);

	draggableGameObject2->Position = Point2(200, 75);
	draggableGameObject2->Rotation = 35.0f / RAD_TO_DEG;
	draggableGameObject2->Scale = Point2(1.0f, 1.0f);

	// Add the child to the this scene
	this->addChild(draggableGameObject2);
	allLocalGameObjects.push_back(draggableGameObject2);


/** CREATING ALL BUTTONS **/
	// Creating a new Line
	StartBox2DBtn = new Button(Point3(23, 219, 36));

	// Adding 4 points to the line, to created a defaultObj
	StartBox2DBtn->CreateSquare(40, 20);

	StartBox2DBtn->Position = Point2(1200, 50);
	StartBox2DBtn->Rotation = 0.0f / RAD_TO_DEG;
	StartBox2DBtn->Scale = Point2(1.0f, 1.0f);

	StartBox2DBtn->filled = true;
	this->addChild(StartBox2DBtn);
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

	if (defaultObj != NULL) {
		delete(defaultObj);
		defaultObj = NULL;
	}
	if (ball != NULL) {
		delete(ball);
		ball = NULL;
	}
}

void Scene01::update(double deltaTime) {
	Scene::update(deltaTime);

	if (state == START) {
		if (ball->Position.y > BasketLeft->Position.y - BasketLeft->GetSquareHeight()) {
			if (ball->Position.y > BasketRigth->Position.y - BasketRigth->GetSquareHeight()) {
				if (ball->Position.x > BasketBottom->Position.x - BasketBottom->GetSquareWidth()) {
					if (ball->Position.x < BasketBottom->Position.x + BasketBottom->GetSquareWidth()) {
						ball->Color = Point2(0, 255, 180);
						for each (GameObject* test in allLocalGameObjects) {
							test->Color = Point2(0, 255, 180);
							test->filled = true;
						}
						ball->filled = true;

						state = FINISHED;
					}
				}
			}
		}
	}

	if (StartBox2DBtn->isClicked) {
		this->CanStartBox2D = true;
	}
}