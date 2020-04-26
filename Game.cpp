// Copyright 2009-2014 Blam BaseApps, Inc. All Rights Reserved.

#include "Game.h"

Game::Game():
	Parent(100, 80),
	mDirection(true),
	timeStep(0),
	resolutionCreateFigure(true),
	moveX(START_COORD_X),
	moveY(START_COORD_Y)
{}

void Game::KeyPressed(int btnCode)
{
	if (btnCode == 32) //
	{
		world.rotationFigure();
	}
	else if (btnCode == 115) //s
	{

	}
	else if (btnCode == 97) //a
	{
		--moveX;
		world.moveFigure(moveX, moveY);
	}
	else if (btnCode == 100) //
	{
		++moveX;
		world.moveFigure(moveX, moveY);
	}
}

void Game::Render() 
{
	for (int i = 0; i < ARRAY_Y; i++) 
	{
		for (int j = 0; j < ARRAY_X; j++) 
		{
			if (world.arrSquare[i][j] == nullptr) 
			{
				SetChar(j, i, L'.');
			}
			else 
			{
				SetChar(j, i, 10);
			}
		}
	}
}

void Game::start() 
{
	createFigure();

	if (timeStep >= GAME_ITERATION)
	{
		moveY++;
		world.moveFigure(moveX, moveY);
		timeStep = 0;
	}
}

void Game::createFigure()
{
	if (resolutionCreateFigure == true)
	{
		world.addFigure(new TFigure(START_COORD_X, START_COORD_Y));

		moveX = START_COORD_X;
		moveY = START_COORD_Y;

		resolutionCreateFigure = false;
	}
}

void Game::Update(float deltaTime)
{
       timeStep += deltaTime;
       start();
       Render();
}
