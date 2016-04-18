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

class Scene
{
public:
	Scene();
	~Scene();

	virtual void UpdateScene();

	void addChild(GameObject* obj);
	GameObject* star;
	std::vector<GameObject*> GetAllGameObjects() { return allGameObjects; }

private:
	std::vector<GameObject*> allGameObjects;
};

#endif /* SCENE_H */