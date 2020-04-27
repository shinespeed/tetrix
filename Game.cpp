// Copyright 2009-2014 Blam BaseApps, Inc. All Rights Reserved.

#include "Game.h"

enum numberFigure
{
	TFIGURE,
	QFIGURE,
	IFIGURE,
	ZFIGURE,
	JFIGURE,
	LFIGURE,
	SFIGURE
};

Game::Game():
	Parent(40, 20),
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
	else if ((btnCode == 115)&&(world.regulationFigure(moveX, moveY + 1))) //s
	{

	}
	else if ((btnCode == 75) && (world.regulationFigure(moveX - 1, moveY))) //a
	{
		--moveX;
		world.moveFigure(moveX, moveY);
	}
	else if ((btnCode == 77) && (world.regulationFigure(moveX + 1, moveY)))
	{
		++moveX;
		world.moveFigure(moveX, moveY);
	}
}

void Game::graphBorders() 
{
	for (int i = 0; i <= BORDER_END_X; i++)
	{
		for (int j = 0; j <= BORDER_END_Y; j++)
		{
			if ( i == 0 || j == 0 || i == BORDER_END_X || j == BORDER_END_Y || (i == BORDER_1_X)&&(j <= BORDER_1_Y) || (j == BORDER_2_Y))
			{
				SetChar(i, j, L'#');
			}
			else
			{
				//SetChar(i, j, 10);
			}
		}
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
				SetChar(j + PLAYING_FIELD_X, i + PLAYING_FIELD_X, L'.');
			}
			else 
			{
				SetChar(j + PLAYING_FIELD_X, i + PLAYING_FIELD_Y, 10);
			}
		}
	}
	graphBorders();
}

void Game::createFigure()
{
	if (resolutionCreateFigure == true)
	{
		world.addFigure(randomFigure());

		moveX = START_COORD_X;
		moveY = START_COORD_Y;

		resolutionCreateFigure = false;
	}
}

Figure* Game::randomFigure() 
{
	srand(time(NULL));                   

	int random = rand() % 7;

	switch (random)
	{
	case TFIGURE:
		return new IFigure(START_COORD_X, START_COORD_Y);
		break;
	case QFIGURE:
		return new QFigure(START_COORD_X, START_COORD_Y);
		break;
	case IFIGURE:
		return new IFigure(START_COORD_X, START_COORD_Y);
		break;
	case ZFIGURE:
		return new ZFigure(START_COORD_X, START_COORD_Y);
		break;
	case JFIGURE:
		return new JFigure(START_COORD_X, START_COORD_Y);
		break;
	case LFIGURE:
		return new LFigure(START_COORD_X, START_COORD_Y);
		break;
	case SFIGURE:
		return new SFigure(START_COORD_X, START_COORD_Y);
		break;
	}
}

void Game::start()
{
	createFigure();

	if (timeStep >= GAME_ITERATION)
	{
		if (world.regulationFigure(moveX, moveY + 1))
		{
			moveY++;
		}
		else
		{
			resolutionCreateFigure = true;
		}
		world.moveFigure(moveX, moveY);
		timeStep = 0;
	}
}

void Game::Update(float deltaTime)
{
	timeStep += deltaTime;

        start();
	Render();
}
