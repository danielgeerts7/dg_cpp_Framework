/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#include "button.h"


Button::Button(Point3 color) : GameObject(STATIC)
{
	Color = color;
	firstColor = color;

	isButton = true;
}


Button::~Button()
{
}


bool Button::isMouseOverButton(double mouseX, double mouseY)
{
	if (this->Position.x + this->GetSquareWidth() > mouseX &&
		this->Position.x - this->GetSquareWidth() < mouseX &&
		this->Position.y + this->GetSquareHeight() > mouseY &&
		this->Position.y - this->GetSquareHeight() < mouseY) {
		return true;
	}
	return false;
}


