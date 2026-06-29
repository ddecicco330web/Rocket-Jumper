#include "../Headers/RenderManager.hpp"

void RenderManager::startup()
{
	window.create(sf::VideoMode({ 1280, 720 }), "SFML works!");
}

void RenderManager::shutdown()
{
	window.close();
}

void RenderManager::render(double alpha)
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	window.clear();
	window.draw(shape);
	window.display();
}

