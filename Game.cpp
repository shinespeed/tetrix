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

Game::Game() :
	BaseApp(WINDOW_SIZE_X, WINDOW_SIZE_Y),
	mDirection(true),
	timeStep(0),
	resolutionCreateFigure(true),
	moveX(START_COORD_X),
	moveY(START_COORD_Y),
	furureFigure(randomFigure())
{}

Game::~Game() 
{
	if (furureFigure != nullptr) delete furureFigure;
}

void Game::KeyPressed(int btnCode)
{
	if (btnCode == SPACE) 
	{
		world.rotationFigure();
	}
	else if ((btnCode == DOWN)&&(world.regulationFigure(moveX, moveY + 1))) 
	{
		++moveY;
		world.moveFigure(moveX, moveY);
	}
	else if ((btnCode == LEFT) && (world.regulationFigure(moveX - 1, moveY))) 
	{
		--moveX;
		world.moveFigure(moveX, moveY);
	}
	else if ((btnCode == RIGHT) && (world.regulationFigure(moveX + 1, moveY)))
	{
		++moveX;
		world.moveFigure(moveX, moveY);
	}
}

void Game::gameOverCheck(Figure* figure)
{
	int tempX(0);
	int tempY(0);

	for (int i = 0; i < QUANTITY_SQUARE; ++i) 
	{
		tempX = figure->getArrSquareFigure(i)->xSquare;
		tempY = figure->getArrSquareFigure(i)->ySquare;
		if (world.arrSquare[tempY][tempX] != nullptr) 
		{
			gameCheck = false;
		}
	}
}

void Game::createFigure()
{
	if (resolutionCreateFigure == true)
	{
		gameOverCheck(furureFigure);

		world.checkSumSquareHorizon();
		world.addFigure(furureFigure);

		moveX = START_COORD_X;
		moveY = START_COORD_Y;

		furureFigure = randomFigure();
		renderFutureFigure();
		resolutionCreateFigure = false;
	}
}

Figure* Game::randomFigure() 
{     
	int random = rand() % 7;

	switch (random)
	{
	case TFIGURE:
		return new TFigure(START_COORD_X, START_COORD_Y);
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
			++moveY;
		}
		else
		{
			resolutionCreateFigure = true;
		}
		world.moveFigure(moveX, moveY);
		timeStep = 0;
	}
}

void Game::renderFutureFigure() 
{
	int tempX(0);
	int tempY(0);

	for (int i = 0; i < QUANTITY_SQUARE; ++i)
	{
		for (int j = 0; j < QUANTITY_SQUARE; ++j)
		{
			SetChar(i + FUTURE_FIGURE_X - 1, j + FUTURE_FIGURE_Y, 0);
		}
	}

	for (int i = 0; i < QUANTITY_SQUARE; ++i) 
	{

		tempX = furureFigure->getArrSquareFigure(i)->xSquare - START_COORD_X;
		tempY = furureFigure->getArrSquareFigure(i)->ySquare - START_COORD_Y;

		SetChar(tempX + FUTURE_FIGURE_X, tempY + FUTURE_FIGURE_Y,  10);
	}
}

void Game::graphBorders()
{
	for (int i = BORDER_START_X; i <= BORDER_END_X; ++i)
	{
		for (int j = BORDER_START_Y; j <= BORDER_END_Y; ++j)
		{
			if (i == BORDER_START_X || j == BORDER_START_Y || i == BORDER_END_X || j == BORDER_END_Y || (i == BORDER_1_X) && (j <= BORDER_1_Y) || (j == BORDER_2_Y))
			{
				SetChar(i, j, L'#');
			}
		}
	}
}

void Game::Render()
{
	graphBorders();
	SetString(3, 19, "> Point: ");
	SetString(14, 19, std::to_string(world.sumPoint));

	for (int i = 0; i < ARRAY_Y; ++i)
	{
		for (int j = 0; j < ARRAY_X; ++j)
		{
			if (world.arrSquare[i][j] == nullptr)
			{
				SetChar(j + PLAYING_FIELD_X, i + PLAYING_FIELD_Y, L'.');
			}
			else
			{
				SetChar(j + PLAYING_FIELD_X, i + PLAYING_FIELD_Y, 10);
			}
		}
	}
}

void Game::Update(float deltaTime)
{
	timeStep += deltaTime;
        start();
	Render();
}
