#pragma once
#include <SFML/Graphics.hpp>

class RenderManager
{
public:
	sf::RenderWindow window;

	RenderManager() = default;
	~RenderManager() = default;
	void startup();
	void shutdown();
	void render(double alpha);
};

extern RenderManager gRenderManager;