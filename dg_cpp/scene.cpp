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
	groundBodyDef.position.Set(0.0f, 720.0f);

	// Setting groundBody after setting groundBodyDef, else groundBodyDef is worthless
	groundBody = world.CreateBody(&groundBodyDef);

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(1280.0f, 1.0f);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);
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
	}
}


void Scene::addChild(GameObject* obj)
{
	obj->BindPoints();
	allGameObjects.push_back(obj);

	obj->bodyDef.position.Set(obj->Position.x, obj->Position.y);

	obj->body = world.CreateBody(&obj->bodyDef);
	obj->body->CreateFixture(&obj->fixtureDef);
}