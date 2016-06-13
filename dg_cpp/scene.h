/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#ifndef SCENE_H
#define SCENE_H

// Include standard headers
#include <string>
#include <vector>

#include <dg_cpp/gameobject.h>
#include <dg_cpp/settings.h>
#include <dg_cpp/timer.h>
#include <Box2D.h>

class Scene
{
public:
	Scene();
	~Scene();

	virtual void update(double deltaTime);
	
	// Define the ground body.
	b2BodyDef groundBodyDef;

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	b2Body* groundBody;

	// Define the ground box shape.
	b2PolygonShape groundBox;

	b2BodyDef LeftWallBodyDef;
	b2Body* LeftWallBody;
	b2PolygonShape LeftWallBox;

	b2BodyDef RightWallBodyDef;
	b2Body* RightWallBody;
	b2PolygonShape RightWallBox;

	std::vector<GameObject*> ChildrenInScene;

	void addChild(GameObject* child);
	//std::vector<GameObject*> GetChildren(return Children);

	// Construct a world object, which will hold and simulate the rigid bodies.
	b2World world = b2World(b2Vec2(0.0f, 1.0f));
};

#endif /* SCENE_H */