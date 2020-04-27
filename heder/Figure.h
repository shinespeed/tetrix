#ifndef FIGURE_H
#define FIGURE_H

#include "GlobalConstant.h"
#include "Square.h"

class Figure
{
public:
	Figure();
	virtual ~Figure();

	int getXFigure();
	int getYFigure();

	void moveFigure(const int xFigure, const int yFigure);
	Square* getArrSquareFigure(int index);

	int xFigure;
	int yFigure;
	Square* arrSquareFigure[QUANTITY_SQUARE];
};

class TFigure : public Figure
{
public:
	TFigure(int xFigure, int yFigure);
	~TFigure();

	void createSquareFigure();
};

class QFigure : public Figure
{
public:
	QFigure(int xFigure, int yFigure);
	~QFigure();

	void createSquareFigure();
};

class IFigure : public Figure
{
public:
	IFigure(int xFigure, int yFigure);
	~IFigure();

	void createSquareFigure();
};

class ZFigure : public Figure
{
public:
	ZFigure(int xFigure, int yFigure);
	~ZFigure();

	void createSquareFigure();
};

class SFigure : public Figure
{
public:
	SFigure(int xFigure, int yFigure);
	~SFigure();

	void createSquareFigure();
};

class JFigure : public Figure
{
public:
	JFigure(int xFigure, int yFigure);
	~JFigure();

	void createSquareFigure();
};

class LFigure : public Figure
{
public:
	LFigure(int xFigure, int yFigure);
	~LFigure();

	void createSquareFigure();
};
#endif
