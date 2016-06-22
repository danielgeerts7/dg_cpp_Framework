/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <dg_cpp/line.h>
#include <dg_cpp/pointx.h>
#include <Box2D.h>

const static enum BodyType { DYNAMIC, STATIC, KINEMATIC };
const static enum TypeOfObject { GAMEOBJECT, BUTTON, DRAGGABLE };


class GameObject : public Line
{
public:
	GameObject(BodyType type);
	~GameObject();

	Point2 Position;
	float Rotation;
	Point2 Scale;

	Point3 Color;

	b2BodyDef bodyDef;
	b2Body* body = NULL;
	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;

	BodyType GetBodyType() { return bodytype; };

	TypeOfObject objectType = GAMEOBJECT;
	TypeOfObject GetObjectType() { return objectType; };

private:
	BodyType bodytype;
};

#endif /* GAMEOBJECT_H */