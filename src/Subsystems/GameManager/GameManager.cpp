#include "GameManager.h"


void GameManager::run()
{
	isRunning = true;

	/*int renderFPS = 0;
	int updateFPS = 0;
	std::chrono::duration<double> timer(0.0);
	std::chrono::duration<double> second(1.0);*/

	// Fixed Time Step
	constexpr std::chrono::duration<double> dt(1.0 / 60.0);

	// Total simulated game time
	std::chrono::duration<double> t(0.0);

	std::chrono::duration<double> accumulator(0.0);

	auto currentTime = std::chrono::steady_clock::now();

	// Main game loop
	while (isRunning)
	{
		// Update game state
		auto newTime = std::chrono::steady_clock::now();
		std::chrono::duration<double> frameTime = newTime - currentTime;
		currentTime = newTime;

		// If the game freezes or breaks in a breakpoint, clamp the frameTime
		if (frameTime.count() > 0.25) 
		{
			frameTime = std::chrono::duration<double>(0.25);
		}

		accumulator += frameTime;


		while (accumulator >= dt)
		{
			// Input
			while (const std::optional event = gRenderManager.window.pollEvent())
			{
				if (event->is<sf::Event::Closed>())
				{
					isRunning = false;
				}
			}

			// Update Game
			/*updateFPS++;

			timer += dt;
			if (timer >= second)
			{
				std::printf("Render FPS: %d\n", renderFPS);
				std::printf("Update FPS: %d\n\n", updateFPS);

				updateFPS = 0;
				renderFPS = 0;
				timer -= second;
			}*/

			t += dt;
			accumulator -= dt;
		}

		// Calculate the interpolation factor (how far we are between logic steps)
		const double alpha = accumulator.count() / dt.count();

		// Render the game
		gRenderManager.render(alpha);
		//renderFPS++;
	}
}