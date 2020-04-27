#ifndef GAME_H
#define GAME_H

#include <thread>
#include <cstdlib>
#include <ctime>
#include "GlobalConstant.h"
#include "BaseApp.h"
#include "World.h"
#include "Figure.h"

class Game : public BaseApp
{
public:
	Game();
	~Game();

	void KeyPressed(int btnCode);
	void Update(float deltaTime);
private:
	World world;

	bool resolutionCreateFigure;
	bool mDirection;

	int moveX;
	int moveY;

	float timeStep;

	Figure* randomFigure();
	Figure* furureFigure;

	void gameOverCheck(Figure* figure);
	void createFigure();
	void start();
	void renderFutureFigure();
	void graphBorders();
	void Render();
};

#endif
