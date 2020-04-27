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

	bool regulationFigure(int futureX, int futureY);
	bool regulationSquare(int squarefutureX, int squarefutureY);
	bool whoseSquare(int squarefutureX, int squarefutureY);

	void moveFigure(const int x, const int y);

	void calculationFutureXY(int &futureX, int &futureY, const int index);
	void rotationFigure();
	void rotationMatrixSquare(const int index, int &numberViolation);

	void addFigure(Figure* figure);
};
