//#define _CRTDBG_MAP_ALLOC

#include "Subsystems/Headers/RenderManager.hpp"
#include "Subsystems/GameManager/GameManager.h"

RenderManager gRenderManager;
GameManager gGameManager;

int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	// Start up subsystems
	gRenderManager.startup();

	// Run the main game loop
	gGameManager.run();

	// Shut down subsystems
	gRenderManager.shutdown();
}
