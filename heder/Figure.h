#pragma once

#include "GlobalConstant.h"
#include "Square.h"
#include <vector>

class Figure
{
public:
	Figure();
	~Figure();

	virtual int getXFigure() = 0;
	virtual int getYFigure() = 0;

	virtual void moveFigure(const int xFigure, const int yFigure) = 0;

	virtual Square* getArrSquareFigure(int index) = 0;
};

class TFigure : public Figure
{
public:
	TFigure(int xFigure, int yFigure);
	~TFigure();

	void moveFigure(const int xFigure, const int yFigure) override;
	void createSquareFigure();

	int getXFigure() override;
	int getYFigure() override;

	Square* getArrSquareFigure(int index) override;

	int xFigure;
	int yFigure;

	Square* arrSquareFigure[4];
};

class QFigure : public Figure
{
public:
	QFigure();
	~QFigure();
};

class IFigure : public Figure
{
public:
	IFigure();
	~IFigure();
};

class ZFigure : public Figure
{
public:
	ZFigure();
	~ZFigure();
};

class SFigure : public Figure
{
public:
	SFigure();
	~SFigure();
};

class JFigure : public Figure
{
public:
	JFigure();
	~JFigure();
};