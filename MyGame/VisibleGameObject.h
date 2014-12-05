#pragma once
#include <string>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class VisibleGameObject
{
public:
	VisibleGameObject();
	virtual ~VisibleGameObject();

	virtual void load(std::string filename);
	virtual void draw(sf::RenderWindow &window);
	virtual void update(float elapsedTime);

	virtual void setPosition(float x, float y);
	virtual sf::Vector2f getPosition() const;
	virtual bool getIsLoaded() const;

	virtual char * getType();

	//protected:
	sf::Sprite& getSprite();
	std::string filename;

private:
	sf::Sprite sprite;
	sf::Texture image;

	bool isLoaded;
};