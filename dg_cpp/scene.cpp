/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#include "Scene.h"


Scene::Scene()
{
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

	fpstimer.start();
}


Scene::~Scene()
{
}

void Scene::update(float deltaTime)
{
	// Instruct the world to perform a single step of simulation.
	// It is generally best to keep the time step and iterations fixed.
	world.Step(timeStep, velocityIterations, positionIterations);

	int size = allGameObjects.size();
	
	for (int i = 0; i < size; i++) {
		allGameObjects[i]->Position.x = allGameObjects[i]->body->GetPosition().x;
		allGameObjects[i]->Position.y = allGameObjects[i]->body->GetPosition().y;
		allGameObjects[i]->Rotation = allGameObjects[i]->body->GetAngle();
	}

	// ###############################################################
	// show FPS
	// ###############################################################
	static int framecounter = 0;
	if (fpstimer.seconds() > 1.0f) {
		std::string fpstxt = "FPS: ";
		fpstxt.append(std::to_string(framecounter));
		fpstxt.append("\n");
		printf(fpstxt.c_str());
		framecounter = 0;
		fpstimer.start();
	}
	framecounter++;
}


void Scene::addChild(GameObject* obj)
{
	obj->BindPoints();
	allGameObjects.push_back(obj);

	obj->bodyDef.position.Set(obj->Position.x, obj->Position.y);
	
	int sizeOfPoints = obj->getPointsPoint2().size();
	std::vector<b2Vec2> temp = std::vector<b2Vec2>();
	for (int i = 0; i < sizeOfPoints; i++) {
		temp.push_back(b2Vec2(obj->getPointsPoint2()[i].x, obj->getPointsPoint2()[i].y));
	}

	obj->dynamicBox.Set(&temp[0], sizeOfPoints);
	obj->fixtureDef.shape = &obj->dynamicBox;
	obj->body = world.CreateBody(&obj->bodyDef);
	obj->body->CreateFixture(&obj->fixtureDef);
	obj->body->SetTransform (obj->body->GetPosition(), obj->Rotation);
}