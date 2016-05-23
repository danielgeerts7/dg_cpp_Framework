/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include <dg_cpp/gameobject.h>
#include <Box2D.h>

class Scene
{
public:
	Scene();
	~Scene();

	virtual void update(float deltaTime);

	
	// Define the gravity vector.
	b2Vec2 gravity = b2Vec2(0.0f, 1.0f);

	// Construct a world object, which will hold and simulate the rigid bodies.
	b2World world = b2World(gravity);
	
	// Define the ground body.
	b2BodyDef groundBodyDef;

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	b2Body* groundBody;

	// Define the ground box shape.
	b2PolygonShape groundBox;

	void addChild(GameObject* obj);

	std::vector<GameObject*> GetAllGameObjects() { return allGameObjects; }

private:
	std::vector<GameObject*> allGameObjects;

	float timeStep = 1.0f / 60.0f;
	int velocityIterations = 6;
	int positionIterations = 2;
};

#endif /* SCENE_H */