/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Dani�l Geerts <daniel.geerts@live.nl>
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

	defaultObj->Color = Point3(255, 255, 0);
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

	defaultObj->Color = Point3(255, 255, 0);
	defaultObj->filled = false;

	// Add the child to the this scene
	this->addChild(defaultObj);
	allLocalGameObjects.push_back(defaultObj);

	// Creating a new Line
	defaultObj = new GameObject(STATIC);

	// Adding 4 points to the line, to created a defaultObj
	defaultObj->CreateSquare(10, 150);

	defaultObj->Position = Point2(420, 550);
	defaultObj->Rotation = 0.0f / RAD_TO_DEG;
	defaultObj->Scale = Point2(1.0f, 1.0f);

	defaultObj->Color = Point3(255, 255, 0);
	defaultObj->filled = false;

	// Add the child to the this scene
	this->addChild(defaultObj);
	allLocalGameObjects.push_back(defaultObj);

	// Creating a new Line
	BasketLeft = new GameObject(STATIC);

	// Adding 4 points to the line, to created a defaultObj
	BasketLeft->CreateSquare(25, 10);

	BasketLeft->Position = Point2(504, 695);
	BasketLeft->Rotation = 90.0f / RAD_TO_DEG;
	BasketLeft->Scale = Point2(1.0f, 1.0f);

	BasketLeft->Color = Point3(0, 255, 255);
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

	BasketRigth->Color = Point3(0, 255, 255);
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

	BasketBottom->Color = Point3(0, 255, 255);
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
	ball->filled = true;

	this->addChild(ball);
	ball->body->SetGravityScale(1.0f);
	allLocalGameObjects.push_back(ball);


/** CREATING ALL DRAGGABLE GAME OBJECTS  **/
	// Creating a new Line
	draggableGameObject1 = new DraggableGameObject(Point3(255, 0, 255));

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
	StartBox2DBtn->CreateSquare(30, 30);

	StartBox2DBtn->Position = Point2(1200, 50);
	StartBox2DBtn->Rotation = 0.0f / RAD_TO_DEG;
	StartBox2DBtn->Scale = Point2(1.0f, 1.0f);

	StartBox2DBtn->filled = true;
	this->addChild(StartBox2DBtn);

	GameObject* temp = new GameObject(STATIC);
	temp->CreateCircle(20, 3);
	temp->Position = StartBox2DBtn->Position;
	temp->Rotation= StartBox2DBtn->Rotation;
	temp->Scale = StartBox2DBtn->Scale;
	temp->filled = true;
	temp->Color = Point3(255, 255, 255);
	this->addChild(temp);
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
	if (BasketLeft != NULL) {
		delete(BasketLeft);
		BasketLeft = NULL;
	}
	if (BasketRigth != NULL) {
		delete(BasketRigth);
		BasketRigth = NULL;
	}
	if (BasketBottom != NULL) {
		delete(BasketBottom);
		BasketBottom = NULL;
	}
	if (draggableGameObject1 != NULL) {
		delete(draggableGameObject1);
		draggableGameObject1 = NULL;
	}
	if (draggableGameObject2 != NULL) {
		delete(draggableGameObject2);
		draggableGameObject2 = NULL;
	}
	if (StartBox2DBtn != NULL) {
		delete(StartBox2DBtn);
		StartBox2DBtn = NULL;
	}
}

void Scene01::update(double deltaTime) {
	Scene::update(deltaTime);

	if (state == START) {
		if (ball->Position.y > BasketLeft->Position.y - BasketLeft->GetSquareHeight()) {
			if (ball->Position.y > BasketRigth->Position.y - BasketRigth->GetSquareHeight()) {
				if (ball->Position.x > BasketBottom->Position.x - BasketBottom->GetSquareWidth()) {
					if (ball->Position.x < BasketBottom->Position.x + BasketBottom->GetSquareWidth()) {
						ball->Color = Point2(255, 255, 255);
						for each (GameObject* test in allLocalGameObjects) {
							test->Color = Point2(255, 255, 255);
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