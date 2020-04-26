#pragma once

#include "GlobalConstant.h"
#include "Figure.h"
#include "Square.h"
#include <iostream>

class World
{
public:
	World();
	~World();

	Square* arrSquare[ARRAY_Y][ARRAY_X];

	Figure* tempFigure;
	Figure* buffFigure;

	void moveFigure(const int x, const int y);
	void rotationFigure();
	void matrixRot(int index);
	void addFigure(Figure* figure);
};

