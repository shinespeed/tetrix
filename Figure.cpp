#include "Figure.h"

Figure:: Figure() {}

Figure::~Figure() {}

TFigure::TFigure(int xFigure, int yFigure):
    xFigure(xFigure),
	yFigure(yFigure)
{
	createSquareFigure();
}

TFigure::~TFigure()
{
	//delete[] arrSquareFigure;
}

void TFigure::createSquareFigure() 
{
	arrSquareFigure[0] = new Square(xFigure + TFIGURE_COORD_1_X, yFigure + TFIGURE_COORD_1_Y);
	arrSquareFigure[1] = new Square(xFigure + TFIGURE_COORD_2_X, yFigure + TFIGURE_COORD_2_Y);
	arrSquareFigure[2] = new Square(xFigure + TFIGURE_COORD_3_X, yFigure + TFIGURE_COORD_3_Y);
	arrSquareFigure[3] = new Square(xFigure + TFIGURE_COORD_4_X, yFigure + TFIGURE_COORD_4_Y);
}

void TFigure::moveFigure(const int xFigure, const int yFigure)
{
	arrSquareFigure[0]->moveSquare((xFigure - this->xFigure), (yFigure - this->yFigure));
	arrSquareFigure[1]->moveSquare((xFigure - this->xFigure), (yFigure - this->yFigure));
	arrSquareFigure[2]->moveSquare((xFigure - this->xFigure), (yFigure - this->yFigure));
	arrSquareFigure[3]->moveSquare((xFigure - this->xFigure), (yFigure - this->yFigure));

	this->xFigure = xFigure;
	this->yFigure = yFigure;
}

Square* TFigure::getArrSquareFigure(int index)
{
	return arrSquareFigure[index];
}

int TFigure::getXFigure() 
{
	return xFigure;
}
int TFigure::getYFigure() 
{
	return yFigure;
}

QFigure::QFigure()
{
}

QFigure::~QFigure()
{
}

IFigure::IFigure()
{
}

IFigure::~IFigure()
{
}

ZFigure::ZFigure()
{
}

ZFigure::~ZFigure()
{
}

JFigure::JFigure()
{
}

JFigure::~JFigure()
{
}

SFigure::SFigure()
{
}

SFigure::~SFigure()
{
}