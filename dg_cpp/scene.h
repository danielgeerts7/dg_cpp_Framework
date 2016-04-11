/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Daniël Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include <dg_cpp/line.h>

class Scene
{
public:
	Scene();
	~Scene();

	void addChild(Line* line);

	std::vector<Line*> GetAllLines() { return allLines; }

private:
	std::vector<Line*> allLines;
};

#endif /* SCENE_H */