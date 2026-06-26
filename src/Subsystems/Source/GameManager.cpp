#include "../Headers/GameManager.hpp"


void GameManager::run()
{
	isRunning = true;

	// Main game loop
	while (isRunning)
	{
		// Update game state
		while (const std::optional event = gRenderManager.window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				isRunning = false;
			}
		}

		// Render the game
		gRenderManager.render();
	}
}