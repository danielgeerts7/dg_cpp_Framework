/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#ifndef SCENE01_H
#define SCENE01_H

// Include all dg_cpp classes needed in this class
#include <dg_cpp/scene.h>
#include <dg_cpp/gameobject.h>
#include <dg_cpp/line.h>
#include <dg_cpp/pointx.h>

class Scene01 : public Scene
{
public:
	Scene01();
	~Scene01();

	void update(float deltaTime);

private:
	GameObject* square;
	GameObject* pentagram;
	GameObject* triangle;
	GameObject* circle;
	GameObject* star;

	std::vector<GameObject*> allGameObjects;
	std::vector<Point2*> allBounceSpeeds;
};

#endif /* SCENE01_H */
