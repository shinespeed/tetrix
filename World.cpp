#include "World.h"


World::World()
{
}

World::~World()
{
	//delete[] arrSquare;
}

void World::matrixRot(int index) 
{
	int tempX = 0;
	int tempY = 0;

	tempX = tempFigure->getArrSquareFigure(0)->xSquare + tempFigure->getArrSquareFigure(0)->ySquare - tempFigure->getArrSquareFigure(index)->ySquare;
	tempY = tempFigure->getArrSquareFigure(index)->xSquare + tempFigure->getArrSquareFigure(0)->ySquare - tempFigure->getArrSquareFigure(0)->xSquare;

	arrSquare[tempY][tempX] = tempFigure->getArrSquareFigure(index);

	arrSquare[tempFigure->getArrSquareFigure(index)->ySquare][tempFigure->getArrSquareFigure(index)->xSquare] = nullptr;

	tempFigure->getArrSquareFigure(index)->xSquare = tempX;
	tempFigure->getArrSquareFigure(index)->ySquare = tempY;
}

void World::rotationFigure()
{
	matrixRot(1);
	matrixRot(2);
	matrixRot(3);
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