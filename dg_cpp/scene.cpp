/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#include "Scene.h"


Scene::Scene()
{
	// Creating a new Line
	star = new GameObject();

	// Adding some points to the line, to created a star
	star->line->addPoint(new Point2(0.0f, -100.0f));
	star->line->addPoint(new Point2(25.0f, -25.0f));
	star->line->addPoint(new Point2(100.0f, 0.0f));
	star->line->addPoint(new Point2(25.0f, 25.0f));
	star->line->addPoint(new Point2(0.0f, 100.0f));
	star->line->addPoint(new Point2(-25.0f, 25.0f));
	star->line->addPoint(new Point2(-100.0f, 0.0f));
	star->line->addPoint(new Point2(-25.0f, -25.0f));

	star->Position = new Point2(250.0f, 550.0f);
	star->Rotation = 0.0f;
	star->Scale = new Point2(1.0f, 1.0f);

	// Add the child to the this scene
	this->addChild(star);
}


Scene::~Scene()
{
}


void Scene::addChild(GameObject* obj)
{
	obj->line->BindPoints();
	allGameObjects.push_back(obj);
}

void Scene::UpdateScene() {
	star->Rotation += 0.0001;
}