#ifndef BASEAPP_H
#define BASEAPP_H

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include "BaseApp.h"

using namespace std;

class BaseApp
{
private:
	HANDLE mConsole;
	HANDLE mConsoleIn;

	CHAR_INFO* mChiBuffer;
	COORD mDwBufferSize;
	COORD mDwBufferCoord;
	SMALL_RECT mLpWriteRegion;

	void Render();

public:
	const int X_SIZE;
	const int Y_SIZE;

	bool gameCheck;

	BaseApp(int xSize= WINDOW_SIZE_X, int ySize= WINDOW_SIZE_Y);
	virtual ~BaseApp();

	void Run();

	void SetChar(int x, int y, wchar_t c);
	void SetString(int x, int y, string str);
	wchar_t GetChar(int x, int y);

	virtual void Update(float deltaTime) = 0;
	virtual void KeyPressed(int btnCode) = 0;
};
#endif
