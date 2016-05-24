/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Dani�l Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#ifndef SCENE01_H
#define SCENE01_H

// Include all dg_cpp classes needed in this class
#include <dg_cpp/scene.h>
#include <dg_cpp/gameobject.h>
#include <dg_cpp/line.h>
#include <dg_cpp/pointx.h>
#include <dg_cpp/settings.h>

class Scene01 : public Scene
{
public:
	Scene01();
	~Scene01();

	void update(float deltaTime);

private:
	GameObject* square;
	GameObject* circle_1;
	GameObject* circle_2;
	GameObject* circle_3;
	GameObject* circle_4;

	std::vector<GameObject*> allLocalGameObjects;
};

#endif /* SCENE01_H */
