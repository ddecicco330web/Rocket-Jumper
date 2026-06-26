#include "../Headers/RenderManager.hpp"

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