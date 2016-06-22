/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#include "Scene.h"


Scene::Scene(GLFWwindow* currentWindow)
{
	CurrentWindow = currentWindow;

	// Set the ground body position.
	groundBodyDef.position.Set(-(float)WINDOW_WIDTH /2, (float)WINDOW_HEIGHT);

	// Setting groundBody after setting groundBodyDef, else groundBodyDef is worthless
	groundBody = world.CreateBody(&groundBodyDef);

	// The extents are the half-widths of the box.
	groundBox.SetAsBox((float)WINDOW_WIDTH * 2, 1.0f);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);

	LeftWallBodyDef.position.Set(1.0f, -25.0f);
	LeftWallBody = world.CreateBody(&LeftWallBodyDef);
	LeftWallBox.SetAsBox(1.0f, (float)WINDOW_HEIGHT + 50);
	LeftWallBody->CreateFixture(&LeftWallBox, 0.0f);

	RightWallBodyDef.position.Set((float) WINDOW_WIDTH - 1.0f, -25.0f);
	RightWallBody = world.CreateBody(&RightWallBodyDef);
	RightWallBox.SetAsBox(1.0f, (float)WINDOW_HEIGHT + 50);
	RightWallBody->CreateFixture(&RightWallBox, 0.0f);
}


Scene::~Scene()
{
}

void Scene::update(double deltaTime) {
	int size = ChildrenInScene.size();

	for (int i = 0; i < size; i++) {
		ChildrenInScene[i]->Position.x = ChildrenInScene[i]->body->GetPosition().x;
		ChildrenInScene[i]->Position.y = ChildrenInScene[i]->body->GetPosition().y;
		ChildrenInScene[i]->Rotation = ChildrenInScene[i]->body->GetAngle();
	}

	for each (Button* button in ChildrenInScene) {
		if (button->IsButton()) {
			double mouseX, mouseY;
			glfwGetCursorPos(CurrentWindow, &mouseX, &mouseY);
			if (button->isMouseOverButton(mouseX, mouseY)) {
				button->Color = button->firstColor - 50;

				if (glfwGetMouseButton (CurrentWindow, GLFW_MOUSE_BUTTON_1 ) == GLFW_PRESS) {
					button->Color = button->firstColor - 100;
					button->isClicked = true;
				}
			} else {
				button->Color = button->firstColor;
			}
		}
	}

	// Do this when the current scene is FINISHED
	if (state == FINISHED) {
		this->CanStartBox2D = false;
		// MAYBE SAVE SCORE
		// STOP/DELETE THIS->SCENE
		// START SCENE02
		// SET 'state' TO START AGAIN
		// state = START;
	}
}

void Scene::addChild(GameObject * child)
{
	child->BindPoints();

	ChildrenInScene.push_back(child);

	child->bodyDef.position.Set(child->Position.x, child->Position.y);

	int sizeOfPoints = child->getPointsPoint2().size();
	std::vector<b2Vec2> temp = std::vector<b2Vec2>();
	for (int i = 0; i < sizeOfPoints; i++) {
		temp.push_back(b2Vec2(child->getPointsPoint2()[i].x, child->getPointsPoint2()[i].y));
	}

	child->dynamicBox.Set(&temp[0], sizeOfPoints);
	child->fixtureDef.shape = &child->dynamicBox;
	child->body = world.CreateBody(&child->bodyDef);
	child->body->CreateFixture(&child->fixtureDef);
	child->body->SetTransform(b2Vec2(child->Position.x, child->Position.y), child->Rotation);
}