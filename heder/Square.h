#pragma once

class Square
{
public:
	Square(int x_Square, int y_Square);
	~Square();

	void moveSquare(int xSquare, int ySquare);

	int xSquare;
	int ySquare;
};

