/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#ifndef DRAGGABLEGAMEOBJECT_H
#define DRAGGABLEGAMEOBJECT_H

#include <dg_cpp\gameobject.h>

class DraggableGameObject : public GameObject
{
public:
	DraggableGameObject(Point3 color);
	~DraggableGameObject();

	bool isMouseOverButton(double mouseX, double mouseY);

	Point3 firstColor;
	bool IsDraggable() { return isDraggable; }
	bool CanBeDragged = true;

private:
	bool isDraggable = false;
};

#endif /* DRAGGABLEGAMEOBJECT_H */