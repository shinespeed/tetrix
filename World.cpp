#include "World.h"


World::World(){}

World::~World()
{
	delete[] arrSquare;
}

bool World::regulationFigure(int futureX, int futureY)
{
	int tempX = 0;
	int tempY = 0;
	int numberViolation = 0;

	for (int i = 0; i < QUANTITY_SQUARE; i++)
	{
	    tempX = tempFigure->getArrSquareFigure(i)->xSquare + (futureX - tempFigure->getXFigure());
		tempY = tempFigure->getArrSquareFigure(i)->ySquare + (futureY - tempFigure->getYFigure());

		if (!regulationSquare(tempX, tempY)) ++numberViolation;
	} 
	if (numberViolation == 0) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool World::regulationSquare(int squarefutureX, int squarefutureY)
{
	if (squarefutureX >= 0 && squarefutureX < ARRAY_X && squarefutureY < ARRAY_Y)
	{
		if (arrSquare[squarefutureY][squarefutureX] == nullptr) 
		{
			return true;
		}
		else
		{
			return whoseSquare(squarefutureX, squarefutureY);
		}
	} 
	else return false;
}

bool World::whoseSquare(int squarefutureX, int squarefutureY)
{
	bool squareFigure = false;

	for (int i = 0; i < QUANTITY_SQUARE; ++i)
	{
		if (arrSquare[squarefutureY][squarefutureX] == tempFigure->getArrSquareFigure(i))
		{
			squareFigure = true;
			break;
		}
	}
	return squareFigure;
}

void World::calculationFutureXY(int &futureX, int &futureY, const int index)
{
	futureX = tempFigure->getArrSquareFigure(0)->xSquare + tempFigure->getArrSquareFigure(0)->ySquare - tempFigure->getArrSquareFigure(index)->ySquare;
	futureY = tempFigure->getArrSquareFigure(index)->xSquare + tempFigure->getArrSquareFigure(0)->ySquare - tempFigure->getArrSquareFigure(0)->xSquare;
}

void World::rotationMatrixSquare(const int index, int &numberViolation)
{
	int tempX(0);
	int tempY(0);

	calculationFutureXY(tempX, tempY, index);
	
	arrSquare[tempY][tempX] = tempFigure->getArrSquareFigure(index);

	arrSquare[tempFigure->getArrSquareFigure(index)->ySquare][tempFigure->getArrSquareFigure(index)->xSquare] = nullptr;

	tempFigure->getArrSquareFigure(index)->xSquare = tempX;
	tempFigure->getArrSquareFigure(index)->ySquare = tempY;
}

void World::rotationFigure()
{
	int numberViolation(0);
	int tempX(0);
	int tempY(0);

	for (int i = 1; i < QUANTITY_SQUARE; ++i)
	{
		calculationFutureXY(tempX, tempY, i);
		
		if (!regulationSquare(tempX, tempY))
		{ 
			++numberViolation; 
			break;
		}
	}

	if (numberViolation == 0) 
	{
		for (int i = 1; i < QUANTITY_SQUARE; ++i) 
		{
			rotationMatrixSquare(i, numberViolation);
		}
	}

	moveFigure(tempFigure->getXFigure(), tempFigure->getYFigure());
}

void World::moveFigure(const int x, const int y) 
{
	arrSquare[tempFigure->getArrSquareFigure(0)->ySquare][tempFigure->getArrSquareFigure(0)->xSquare] = nullptr;
	arrSquare[tempFigure->getArrSquareFigure(1)->ySquare][tempFigure->getArrSquareFigure(1)->xSquare] = nullptr;
	arrSquare[tempFigure->getArrSquareFigure(2)->ySquare][tempFigure->getArrSquareFigure(2)->xSquare] = nullptr;
	arrSquare[tempFigure->getArrSquareFigure(3)->ySquare][tempFigure->getArrSquareFigure(3)->xSquare] = nullptr;

	tempFigure->moveFigure(x, y);

	arrSquare[tempFigure->getArrSquareFigure(0)->ySquare][tempFigure->getArrSquareFigure(0)->xSquare] = tempFigure->getArrSquareFigure(0);
	arrSquare[tempFigure->getArrSquareFigure(1)->ySquare][tempFigure->getArrSquareFigure(1)->xSquare] = tempFigure->getArrSquareFigure(1);
	arrSquare[tempFigure->getArrSquareFigure(2)->ySquare][tempFigure->getArrSquareFigure(2)->xSquare] = tempFigure->getArrSquareFigure(2);
	arrSquare[tempFigure->getArrSquareFigure(3)->ySquare][tempFigure->getArrSquareFigure(3)->xSquare] = tempFigure->getArrSquareFigure(3);
}

void World::addFigure(Figure* figure) 
{
	tempFigure = figure;

	arrSquare[figure->getArrSquareFigure(0)->ySquare][figure->getArrSquareFigure(0)->xSquare] = figure->getArrSquareFigure(0);
	arrSquare[figure->getArrSquareFigure(1)->ySquare][figure->getArrSquareFigure(1)->xSquare] = figure->getArrSquareFigure(1);
        arrSquare[figure->getArrSquareFigure(2)->ySquare][figure->getArrSquareFigure(2)->xSquare] = figure->getArrSquareFigure(2);
	arrSquare[figure->getArrSquareFigure(3)->ySquare][figure->getArrSquareFigure(3)->xSquare] = figure->getArrSquareFigure(3);
}
