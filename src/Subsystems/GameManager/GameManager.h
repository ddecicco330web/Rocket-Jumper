#pragma once
#include "../RenderManager/RenderManager.h"


class GameManager
{
public:
	GameManager() = default;
	~GameManager() = default;
	void run();

private:
	bool isRunning = false;
};

extern GameManager gGameManager;