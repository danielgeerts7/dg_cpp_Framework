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
#include <dg_cpp/line.h>
#include <dg_cpp/gameobject.h>
#include <dg_cpp/draggablegameobject.h>
#include <dg_cpp/button.h>
#include <dg_cpp/pointx.h>
#include <dg_cpp/settings.h>

class Scene01 : public Scene
{
public:
	Scene01(GLFWwindow* currentWindow);
	~Scene01();

	virtual void update(double deltaTime);

private:
	GameObject* defaultObj;
	GameObject* ball;

	GameObject* BasketLeft;
	GameObject* BasketRigth;
	GameObject* BasketBottom;

	DraggableGameObject* draggableGameObject1;
	DraggableGameObject* draggableGameObject2;
	Button* StartBox2DBtn;

	std::vector<GameObject*> allLocalGameObjects;
};

#endif /* SCENE01_H */
