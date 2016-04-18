/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#include "Scene.h"


Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::update(float deltaTime)
{
}


void Scene::addChild(GameObject* obj)
{
	obj->line->BindPoints();
	allGameObjects.push_back(obj);
}