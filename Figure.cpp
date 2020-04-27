#include "Figure.h"

Figure:: Figure() {}

Figure::~Figure() 
{
}

void Figure::moveFigure(const int xFigure, const int yFigure)
{
	arrSquareFigure[0]->moveSquare((xFigure - this->xFigure), (yFigure - this->yFigure));
	arrSquareFigure[1]->moveSquare((xFigure - this->xFigure), (yFigure - this->yFigure));
	arrSquareFigure[2]->moveSquare((xFigure - this->xFigure), (yFigure - this->yFigure));
	arrSquareFigure[3]->moveSquare((xFigure - this->xFigure), (yFigure - this->yFigure));

	this->xFigure = xFigure;
	this->yFigure = yFigure;
}

Square* Figure::getArrSquareFigure(int index)
{
	return arrSquareFigure[index];
}

int Figure::getXFigure()
{
	return xFigure;
}
int Figure::getYFigure()
{
	return yFigure;
}

TFigure::TFigure(int _xFigure, int _yFigure)
{
	xFigure = _xFigure;
	yFigure = _yFigure;
	createSquareFigure();
}

TFigure::~TFigure()
{
	if (arrSquareFigure != nullptr) delete[] arrSquareFigure;
}

void TFigure::createSquareFigure() 
{
	arrSquareFigure[0] = new Square(xFigure + TFIGURE_COORD_1_X, yFigure + TFIGURE_COORD_1_Y);
	arrSquareFigure[1] = new Square(xFigure + TFIGURE_COORD_2_X, yFigure + TFIGURE_COORD_2_Y);
	arrSquareFigure[2] = new Square(xFigure + TFIGURE_COORD_3_X, yFigure + TFIGURE_COORD_3_Y);
	arrSquareFigure[3] = new Square(xFigure + TFIGURE_COORD_4_X, yFigure + TFIGURE_COORD_4_Y);
}

QFigure::QFigure(int _xFigure, int _yFigure)
{
	xFigure = _xFigure;
	yFigure = _yFigure;
	createSquareFigure();
}

QFigure::~QFigure()
{

}

void QFigure::createSquareFigure()
{
	arrSquareFigure[0] = new Square(xFigure + QFIGURE_COORD_1_X, yFigure + QFIGURE_COORD_1_Y);
	arrSquareFigure[1] = new Square(xFigure + QFIGURE_COORD_2_X, yFigure + QFIGURE_COORD_2_Y);
	arrSquareFigure[2] = new Square(xFigure + QFIGURE_COORD_3_X, yFigure + QFIGURE_COORD_3_Y);
	arrSquareFigure[3] = new Square(xFigure + QFIGURE_COORD_4_X, yFigure + QFIGURE_COORD_4_Y);
}

IFigure::IFigure(int _xFigure, int _yFigure)
{
	xFigure = _xFigure;
	yFigure = _yFigure;
	createSquareFigure();
}

IFigure::~IFigure()
{

}

void IFigure::createSquareFigure()
{
	arrSquareFigure[2] = new Square(xFigure + IFIGURE_COORD_1_X, yFigure + IFIGURE_COORD_1_Y);
	arrSquareFigure[1] = new Square(xFigure + IFIGURE_COORD_2_X, yFigure + IFIGURE_COORD_2_Y);
	arrSquareFigure[0] = new Square(xFigure + IFIGURE_COORD_3_X, yFigure + IFIGURE_COORD_3_Y);
	arrSquareFigure[3] = new Square(xFigure + IFIGURE_COORD_4_X, yFigure + IFIGURE_COORD_4_Y);
}

ZFigure::ZFigure(int _xFigure, int _yFigure)
{
	xFigure = _xFigure;
	yFigure = _yFigure;
	createSquareFigure();
}

ZFigure::~ZFigure()
{

}

void ZFigure::createSquareFigure()
{
	arrSquareFigure[0] = new Square(xFigure + ZFIGURE_COORD_1_X, yFigure + ZFIGURE_COORD_1_Y);
	arrSquareFigure[1] = new Square(xFigure + ZFIGURE_COORD_2_X, yFigure + ZFIGURE_COORD_2_Y);
	arrSquareFigure[2] = new Square(xFigure + ZFIGURE_COORD_3_X, yFigure + ZFIGURE_COORD_3_Y);
	arrSquareFigure[3] = new Square(xFigure + ZFIGURE_COORD_4_X, yFigure + ZFIGURE_COORD_4_Y);
}

JFigure::JFigure(int _xFigure, int _yFigure)
{
	xFigure = _xFigure;
	yFigure = _yFigure;
	createSquareFigure();
}

JFigure::~JFigure()
{

}

void JFigure::createSquareFigure()
{
	arrSquareFigure[2] = new Square(xFigure + JFIGURE_COORD_1_X, yFigure + JFIGURE_COORD_1_Y);
	arrSquareFigure[1] = new Square(xFigure + JFIGURE_COORD_2_X, yFigure + JFIGURE_COORD_2_Y);
	arrSquareFigure[0] = new Square(xFigure + JFIGURE_COORD_3_X, yFigure + JFIGURE_COORD_3_Y);
	arrSquareFigure[3] = new Square(xFigure + JFIGURE_COORD_4_X, yFigure + JFIGURE_COORD_4_Y);
}

SFigure::SFigure(int _xFigure, int _yFigure)
{
	xFigure = _xFigure;
	yFigure = _yFigure;
	createSquareFigure();
}

SFigure::~SFigure()
{

}

void SFigure::createSquareFigure()
{
	arrSquareFigure[0] = new Square(xFigure + SFIGURE_COORD_1_X, yFigure + SFIGURE_COORD_1_Y);
	arrSquareFigure[1] = new Square(xFigure + SFIGURE_COORD_2_X, yFigure + SFIGURE_COORD_2_Y);
	arrSquareFigure[2] = new Square(xFigure + SFIGURE_COORD_3_X, yFigure + SFIGURE_COORD_3_Y);
	arrSquareFigure[3] = new Square(xFigure + SFIGURE_COORD_4_X, yFigure + SFIGURE_COORD_4_Y);
}

LFigure::LFigure(int _xFigure, int _yFigure)
{
	xFigure = _xFigure;
	yFigure = _yFigure;
	createSquareFigure();
}

LFigure::~LFigure()
{

}

void LFigure::createSquareFigure()
{
	arrSquareFigure[2] = new Square(xFigure + LFIGURE_COORD_1_X, yFigure + LFIGURE_COORD_1_Y);
	arrSquareFigure[1] = new Square(xFigure + LFIGURE_COORD_2_X, yFigure + LFIGURE_COORD_2_Y);
	arrSquareFigure[0] = new Square(xFigure + LFIGURE_COORD_3_X, yFigure + LFIGURE_COORD_3_Y);
	arrSquareFigure[3] = new Square(xFigure + LFIGURE_COORD_4_X, yFigure + LFIGURE_COORD_4_Y);
}
