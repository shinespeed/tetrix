// Copyright 2009-2014 Blam BaseApps, Inc. All Rights Reserved.

#pragma once

#include <cstdlib>
#include <ctime>
#include "GlobalConstant.h"
#include "BaseApp.h"
#include "World.h"
#include "Figure.h"

class Game : public BaseApp
{
	typedef BaseApp Parent;

public:
	Game();

	virtual void KeyPressed(int btnCode);
	virtual void Update(float deltaTime);

private:
	World world;

	void Render();
	void start();
	void graphBorders();

	void createFigure();
	Figure* randomFigure();

	bool resolutionCreateFigure;
	bool mDirection;

	int moveX;
	int moveY;

	float timeStep;
};
