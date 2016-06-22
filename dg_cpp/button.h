/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#ifndef BUTTON_H
#define BUTTON_H

#include <dg_cpp\gameobject.h>

class Button : public GameObject
{
public:
	Button(Point3 color);
	~Button();

	bool isMouseOverButton(double mouseX, double mouseY);

	Point3 firstColor;
	bool isClicked = false;

private:
	std::string TextBtn;
};

#endif /* BUTTON_H */